// The Swift Programming Language
// https://docs.swift.org/swift-book

import Combine
import Foundation
import OpenAI

public final class ThinkAR_AI: ThinkARAIProtocol, ObservableObject {
    public init() {}
    
    private static var groqKey = "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"
    
    private static let config = OpenAI.Configuration(token: groqKey, host: "api.groq.com", scheme: "https")
    private let openAI = OpenAI(configuration: config)
    private let groqModel = "llama3-groq-70b-8192-tool-use-preview"
    
    @Published public var conversations: [Conversation] = []
    @Published public var conversationErrors: [Conversation.ID: Error] = [:]
    @Published public var selectedConversationID: Conversation.ID?
    
    public var selectedConversation: Conversation? {
        selectedConversationID.flatMap { id in
            conversations.first { $0.id == id }
        }
    }
    
    public var selectedConversationPublisher: AnyPublisher<Conversation?, Never> {
        $selectedConversationID.receive(on: RunLoop.main).map { id in
            self.conversations.first(where: { $0.id == id })
        }
        .eraseToAnyPublisher()
    }
    
    public func createConversation() -> String {
        let systemMessage = Message(id: UUID().uuidString, role: .system, content: SystemMessage.prompt.rawValue, createdAt: Date())
        let conversation = Conversation(id: UUID().uuidString, messages: [
            systemMessage
        ])
        conversations.append(conversation)
        return conversation.id
    }
    
    public func selectConversation(_ conversationId: Conversation.ID?) {
        selectedConversationID = conversationId
    }
    
    public func deleteConversation(_ conversationId: Conversation.ID) {
        conversations.removeAll(where: { $0.id == conversationId })
    }
    
    @MainActor
    public func addMessage(message: Message, conversationId: Conversation.ID) async {
        guard let conversationIndex = conversations.firstIndex(where: { $0.id == conversationId }) else {
            return
        }
        conversations[conversationIndex].messages.append(message)
        
        await handleChat(
            conversationId: conversationId,
            message: message
        )
    }

    @MainActor
    func handleChat(conversationId: String, message lastUserMessage: Message) async {
        guard let conversation = conversations.first(where: { $0.id == conversationId }) else {
            return
        }
        do {
            guard let conversationIndex = conversations.firstIndex(where: { $0.id == conversationId }) else {
                return
            }
            
            let query = ChatQuery(
                messages: conversation.messages.map { message in
                    ChatQuery.ChatCompletionMessageParam(role: message.role, content: message.content)!
                }, model: groqModel,
                tools: AgentTools.tools
            )
            let chatsStream: AsyncThrowingStream<ChatStreamResult, Error> = openAI.chatsStream(
                query: query)
            
            var functionCalls = [(name: String, argument: String?)]()
            
            for try await partialChatResult in chatsStream {
                for choice in partialChatResult.choices {
                    let existingMessages = conversations[conversationIndex].messages
                    // Function calls are also streamed, so we need to accumulate.
                    choice.delta.toolCalls?.forEach { toolCallDelta in
                        if let functionCallDelta = toolCallDelta.function {
                            if let nameDelta = functionCallDelta.name {
                                functionCalls.append((nameDelta, functionCallDelta.arguments))
                            }
                        }
                    }
                    var messageText = choice.delta.content ?? ""
                    if let finishReason = choice.finishReason,
                       finishReason == .toolCalls
                    {
                        for (name, argument) in functionCalls {
                            let toolHandler = ToolsHandler()
                            let toolChoice = Tools(tool: Tools.ToolCalls(rawValue: name)!)
                            
                            let toolResult: String = toolHandler.invokeTools(toolChoice, arguments: argument)
//                            print(toolResult)
                            
                            // Make a new chat completion request
                            let toolSystemMessage = Message(id: UUID().uuidString, role: .system, content: SystemMessage.toolSystemPrompt.rawValue, createdAt: Date())
                            var finalMsgs = [toolSystemMessage, lastUserMessage, .init(id: UUID().uuidString, role: .tool, content: toolResult, createdAt: Date())]
                            
                            let msgs = finalMsgs.map { message in
                                ChatQuery.ChatCompletionMessageParam(role: message.role, content: message.content)!
                            }
                            print(finalMsgs)
                            let toolQuery = ChatQuery(
                                messages: msgs, model: groqModel
                            )
                            
                            let result = try await openAI.chats(query: toolQuery)
                            messageText += "\(String(describing: result.choices[0].message.content?.string))"
                        }
                    }
                    
                    let message = Message(
                        id: partialChatResult.id,
                        role: choice.delta.role ?? .assistant,
                        content: messageText,
                        createdAt: Date(timeIntervalSince1970: TimeInterval(partialChatResult.created))
                    )
                    
                    if let existingMessageIndex = existingMessages.firstIndex(where: { $0.id == partialChatResult.id }) {
                        // Meld into previous message
                        let previousMessage = existingMessages[existingMessageIndex]
                        let combinedMessage = Message(
                            id: message.id, // id stays the same for different deltas
                            role: message.role,
                            content: previousMessage.content + message.content,
                            createdAt: message.createdAt
                        )
                        conversations[conversationIndex].messages[existingMessageIndex] = combinedMessage
                        
                    } else {
                        conversations[conversationIndex].messages.append(message)
                    }
                }
            }
        } catch {
            conversationErrors[conversationId] = error
        }
    }
    
    public func addVoiceMessage(audio: Data, fileType: String, conversationId: Conversation.ID) async {
        let query = AudioTranscriptionQuery(file: audio, fileType: .init(rawValue: fileType)!, model: .whisper_1)
        do {
            let result = try await openAI.audioTranscriptions(query: query)
            let message = Message(id: UUID().uuidString, role: .user, content: result.text, createdAt: Date())
            await addMessage(message: message, conversationId: conversationId)
        } catch {
            print(error)
        }
    }
    
    public func addTranslationMessage(audio: Data, fileType: String, conversationId: Conversation.ID) async {
        let query = AudioTranslationQuery(file: audio, fileType: .init(rawValue: fileType)!, model: .whisper_1)
        do {
            let result = try await openAI.audioTranslations(query: query)
            let message = Message(id: UUID().uuidString, role: .user, content: result.text, createdAt: Date())
            await addMessage(message: message, conversationId: conversationId)
        } catch {
            print(error)
        }
    }
}
