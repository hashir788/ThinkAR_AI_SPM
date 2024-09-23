import Combine
import Foundation
import OpenAI

public final class ThinkAR_AI: ThinkARAIProtocol, ObservableObject {
    public init() {}
    
    private static var groqKey = "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"
    
    private static let config = OpenAI.Configuration(token: groqKey, host: "api.groq.com", scheme: "https")
    private let openAI = OpenAI(configuration: config)
    private let groqModel = "llama3-groq-70b-8192-tool-use-preview"
//    private let groqModel = "llama-3.1-70b-versatile"
    
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
                            
                            let toolResult: String = await toolHandler.invokeTools(toolChoice, arguments: argument)
                            print(toolResult)
                            // Make a new chat completion request
                            let toolSystemMessage = Message(id: UUID().uuidString, role: .system, content: SystemMessage.toolSystemPrompt.rawValue, createdAt: Date())
                            let toolResultMessage = Message(id: UUID().uuidString, role: .assistant, content: toolResult, createdAt: Date())
//                            let finalMsgs = [toolSystemMessage, lastUserMessage, toolResultMessage]
                            let finalMsgs = [Message(id: UUID().uuidString, role: .system, content: SystemMessage.prompt.rawValue, createdAt: Date()), Message(id: UUID().uuidString, role: .user, content: """
                            User question and API responses for that question are provided.
                            Compose a nice chat response like an assistant using those details.
                            
                            User Question: \(lastUserMessage.content)
                            
                            API Response: \(toolResult)
                            
                            """, createdAt: Date())]

                            let msgs = finalMsgs.map { message in
                                ChatQuery.ChatCompletionMessageParam(role: message.role, content: message.content)!
                            }
                            let toolQuery = ChatQuery(
                                messages: msgs, model: groqModel
                            )

                            print(msgs)

                            let result = try await openAI.chats(query: toolQuery)
                            print(result)
                            messageText += "\(String(describing: result.choices[0].message.content?.string))"
//                            print(messageText)
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
                print("Stream Completed")
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
    
    public func createAudioSpeech(input: String) async -> Result<Data, Error> {
        do {
            let query = AudioSpeechQuery(model: .tts_1, input: input, voice: .alloy, responseFormat: .mp3, speed: 1.0)
            let result = try await openAI.audioCreateSpeech(query: query)
            return .success(result.audio)
        } catch {
            print(error)
            return .failure(error)
        }
    }
}
