// The Swift Programming Language
// https://docs.swift.org/swift-book

import Foundation
import OpenAI
import MBBluetooth


public struct ThinkAR_AI{
    private static var  groqKey = "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"
    
    private static let config = OpenAI.Configuration(token: groqKey, host:"api.groq.com", scheme: "https")
    private let openAI = OpenAI(configuration: config)
    
    public init(){}
    
    public  func addMessage(message:Message) async {
        let query = ChatQuery(messages: [
            .init(role:.system , content: """
             You are an AI assistant specially designed for ThinkAR Smart Glass.
             Your are instructed by voice or text commands
                  You have access to the users personal details and can carry out their daily tasks for them.
                  The examples of task you can carry out are:
                   - Lookup calendar and schedule
                   - Based on the calendar you can book cabs, order foods, set reminders etc.
                   - Check weather
                   - Make calls and many more.
                  Suggest plans and actions if you think it is suitable based on the context,
                   - for example if the user has multiple meetings or a busy day help the
                     user out by creating an action plan with how much time should be spent
                     or add reminders and so on..
                  Your ultimate goal is to be a smart assistant to the user***
                  *Please make sure you get the user's permission before making any critical decisions,
                    like booking an uber rider or ordering food from Food Panda*
                  ** Your answers must be short and precise**
        """)!,.init(role:.init(rawValue: message.role)!, content: message.content)!], model:"llama-3.1-70b-versatile", tools: AgentTools.tools)
        do {
            let chatsStream: AsyncThrowingStream<ChatStreamResult, Error> = openAI.chatsStream(
                query: query)
            
            var functionCalls = [(name: String, argument: String?)]()
            
            for try await partialChatResult in chatsStream {
                for choice in partialChatResult.choices {
                    //                    let existingMessages = conversations[conversationIndex].messages
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
                    functionCalls.forEach {  (name: String, argument: String?)  in
                            messageText += "Function call: name=\(name) arguments=\(argument ?? "")\n"
                            let toolHandler = ToolsHandler()
                            let toolChoice = Tools(tool: Tools.ToolCalls(rawValue: name)!)
                            
                            let toolResult:String = toolHandler.invokeTools(toolChoice)
                            print(toolResult)
                        }
                    }
                   
                    let m = Message(
                        id: partialChatResult.id,
                        content: messageText,
                        role: choice.delta.role?.rawValue ?? "assistant",
                        createdAt: Date(timeIntervalSince1970: TimeInterval(partialChatResult.created))
                    )
                    
                    if functionCalls.count > 0 {
                        print("Not empty")
                        await addMessage(message: m)
                    }
                    
                  
                    print(m)
                    //                    if let existingMessageIndex = existingMessages.firstIndex(where: { $0.id == partialChatResult.id }) {
                    //                        // Meld into previous message
                    //                        let previousMessage = existingMessages[existingMessageIndex]
                    //                        let combinedMessage = Message(
                    //                            id: message.id, // id stays the same for different deltas
                    //                            role: message.role,
                    //                            content: previousMessage.content + message.content,
                    //                            createdAt: message.createdAt
                    //                        )
                    //                        conversations[conversationIndex].messages[existingMessageIndex] = combinedMessage
                    //                    } else {
                    //                        conversations[conversationIndex].messages.append(message)
                    //                    }
                }
            }
        }catch {
            
        }
        
        
        
    }
    
    public func addVoiceMessage(audioMessage:Data){}
    
    public func translate(){}
    
    
    
}
