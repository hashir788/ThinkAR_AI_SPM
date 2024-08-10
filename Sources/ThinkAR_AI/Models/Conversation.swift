//
//  File.swift
//  
//
//  Created by Mohamed Hashir on 2024-08-10.
//

import Foundation

public struct Conversation {
    init(id: String, messages: [Message] = []) {
        self.id = id
        self.messages = messages
    }
    
    public typealias ID = String
    
    public let id: String
    public var messages: [Message]
}

extension Conversation: Equatable, Identifiable {}
