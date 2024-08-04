// The Swift Programming Language
// https://docs.swift.org/swift-book

import Foundation
import SwiftOpenAI

public struct ThinkAR_AI{
    private static var  groqKey = "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"
    private let service:some OpenAIService = OpenAIServiceFactory.service(apiKey: .bearer(groqKey), baseURL:"https://api.groq.com/openai", debugEnabled: false)
    
//    private let service:some OpenAIService = OpenAIServiceFactory.service( baseURL:"https://api.groq.com//openai")
    
    public init(){}
    
    public  func addMessage(_ message:String) async -> Result< [ChatCompletionObject.ChatChoice], APIError> {
        let parameters = ChatCompletionParameters(messages: [.init(role: .user, content: .text(message))], model: .custom("llama-3.1-70b-versatile"))
//        let parameters = ChatCompletionParameters(messages: [.init(role: .user, content: .text(message))], model: .custom("llama3.1"))
        do {
           let choices = try await service.startChat(parameters: parameters).choices
            return Result.success(choices)
           // Work with choices
        } catch APIError.responseUnsuccessful(let description, let statusCode) {
           print("Network error with status code: \(statusCode) and description: \(description)")
            return Result.failure(APIError.responseUnsuccessful(description: description, statusCode: statusCode))
        } catch {
           print(error.localizedDescription)
            return Result.failure(APIError.responseUnsuccessful(description: error.localizedDescription, statusCode: 500))
        }
    }
    
    public func addVoiceMessage(audioMessage:Data){}
    
    public func translate(){}
    
    
    
}
