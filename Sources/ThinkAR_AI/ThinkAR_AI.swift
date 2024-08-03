// The Swift Programming Language
// https://docs.swift.org/swift-book

import Foundation

public struct ThinkAR_AI{
    
    public init(){}
    
    public func addMessage(_ message:String) -> Message {
        print("Message: \(message) added")
        return Message(id:"",content: message, role: "", createdAt: Date.distantFuture)
    }
    
    public func addVoiceMessage(audioMessage:Data){}
    
    public func translate(){}
    
    
    
}
