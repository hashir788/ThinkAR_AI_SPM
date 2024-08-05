// The Swift Programming Language
// https://docs.swift.org/swift-book

import Foundation
import OpenAI

public struct ThinkAR_AI{
    private static var  groqKey = "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"
    private static let host = "api.groq.com/openai".addingPercentEncoding(withAllowedCharacters: .urlHostAllowed)
    private static let config = OpenAI.Configuration(token: groqKey, host:host ?? "api.groq.com", scheme: "https")
    private let openAI = OpenAI(configuration: config)
    
    public init(){}
    
    public  func addMessage(_ message:String) async -> Result< ChatResult, Error> {
       
//        let query = ChatQuery(model:"llama-3.1-70b-versatile", prompt: message, temperature: 0, maxTokens: 100, topP: 1)
        let query = ChatQuery(messages: [.init(role: .user, content: message)!], model:"llama-3.1-70b-versatile")
        do {
            let result = try await openAI.chats(query: query)
            return Result.success(result)
           // Work with choices
        } catch {
           print(error.localizedDescription)
            return Result.failure(error)
        }
    }
    
    public func addVoiceMessage(audioMessage:Data){}
    
    public func translate(){}
    
    
    
}
