//
//  File.swift
//  
//
//  Created by Mohamed Hashir on 2024-08-01.
//

import Foundation
import OpenAI

public struct Message {
   public var id: String
   public var role: ChatQuery.ChatCompletionMessageParam.Role
   public var content: String
   public var createdAt: Date
}

extension Message: Equatable, Codable, Hashable, Identifiable {}
