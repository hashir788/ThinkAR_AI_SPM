//
//  File.swift
//
//
//  Created on 2024-08-05.
//

import Foundation
import OpenAI

enum AgentTools {
    static let tools = [
        ChatQuery.ChatCompletionToolParam(function: .init(
            name: "lookup_calendar",
            description: "Lookup users' calendar",
            parameters: .init(
                type: .object,
                properties: [:],
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
        )),
        ChatQuery.ChatCompletionToolParam(function: .init(
            name: "search_internet",
            description: "Search internet for latest news, current affairs, stock prices and anything on internet ",
            parameters: .init(
                type: .object,
                properties: [
                    "query": .init(type: .string, description: "News Topic")
                ],
                required: ["query"]
            )
        )),
        ChatQuery.ChatCompletionToolParam(function: .init(
            name: "get_EMR",
            description: "Get EMR of a patient",
            parameters: .init(
                type: .object,
                properties: [
                    "ID": .init(type: .string, description: "ID of the patient")
                ],
                required: ["ID"]
            )
        )),
        ChatQuery.ChatCompletionToolParam(function: .init(
            name: "get_ECG",
            description: "Get ECG of a patient",
            parameters: .init(
                type: .object,
                properties: [
                    "ID": .init(type: .string, description: "ID of the patient")
                ],
                required: ["ID"]
            )
        ))
    ]
}
