// The Swift Programming Language
// https://docs.swift.org/swift-book

import Combine
import Foundation
import MBBluetooth
import OpenAI

public final class ThinkAR_AI: ObservableObject {
    private static var groqKey = "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"
    
    private static let config = OpenAI.Configuration(token: groqKey, host: "api.groq.com", scheme: "https")
    private let openAI = OpenAI(configuration: config)
    private let groqModel = "llama3-groq-70b-8192-tool-use-preview"
    
    public init() {}
    
    @Published var conversations: [Conversation] = []
    @Published var conversationErrors: [Conversation.ID: Error] = [:]
    @Published var selectedConversationID: Conversation.ID?
    
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
    func sendMessage(
        message: Message,
        conversationId: Conversation.ID
    ) async {
        guard let conversationIndex = conversations.firstIndex(where: { $0.id == conversationId }) else {
            return
        }
        conversations[conversationIndex].messages.append(message)
        
        await handleChat(
            conversationId: conversationId
        )
    }
    
    @MainActor
    func handleChat(conversationId: String) async {
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
                            messageText += "Function call: name=\(name) arguments=\(argument ?? "")\n"
                            let toolHandler = ToolsHandler()
                            let toolChoice = Tools(tool: Tools.ToolCalls(rawValue: name)!)
                            
                            let toolResult: String = toolHandler.invokeTools(toolChoice)
                            print(toolResult)
                            // TO DO
                            // 1. Make a chat completion request to finalize the answer
                        }
                    }
                    
                    let message = Message(
                        id: partialChatResult.id,
                        role: choice.delta.role ?? .tool,
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
                        
                        print(conversation)
                        
                    } else {
                        conversations[conversationIndex].messages.append(message)
                    }
                }
            }
        } catch {
            conversationErrors[conversationId] = error
        }
    }
    
    public func addVoiceMessage(audioMessage: Data) {}
    
    public func translate() {}
}
