//
//  File.swift
//
//
//  Created on 2024-08-01.
//

import Foundation
import OpenAI

public struct Message {
    public var id: String
    public var role: ChatQuery.ChatCompletionMessageParam.Role
    public var content: String
    public var createdAt: Date

    public init(id: String, role: ChatQuery.ChatCompletionMessageParam.Role, content: String, createdAt: Date) {
        self.id = id
        self.role = role
        self.content = content
        self.createdAt = createdAt
    }
}

extension Message: Equatable, Codable, Hashable, Identifiable {}
