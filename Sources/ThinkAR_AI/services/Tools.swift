//
//  File.swift
//
//
//  Created by Mohamed Hashir on 2024-08-05.
//

import Foundation
import OpenAI

struct AgentTools {
    static let tools = [
        ChatQuery.ChatCompletionToolParam(function: .init(
            name: "lookup_calendar",
            description: "Lookup users' calendar",
            parameters: .init(
                type: .object,
                properties: [
                    "user_id": .init(type: .string, description: "ID if the user")
                ],
                required: []
            )
        )),
        ChatQuery.ChatCompletionToolParam(function: .init(
            name: "change_brightness",
            description: "Change the brightness of the device",
            parameters: .init(
                type: .object,
                properties: [
                    "action_type": .init(type: .string, description: "Increase or Decrease action")
                ],
                required: ["action_type"],
                enum: ["Increase", "Decrease"]
            )
        )),
        ChatQuery.ChatCompletionToolParam(function: .init(
            name: "change_volume",
            description: "Change the volume of the device",
            parameters: .init(
                type: .object,
                properties: [
                    "action_type": .init(type: .string, description: "Increase or Decrease volume")
                ],
                required: ["action_type"],
                enum: ["Increase", "Decrease"]
            )
        ))
    ]
    
    
    public init(){}
    
    
}
