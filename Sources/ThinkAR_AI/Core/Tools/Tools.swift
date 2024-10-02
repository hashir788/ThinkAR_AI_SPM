//
//  File.swift
//
//
//  Created on 2024-08-09.
//

import Foundation
import MBBluetooth
import OpenAI

struct Tools {
    enum ToolCalls: String {
        case lookupCalendar = "lookup_calendar"
        case changeBrightness = "change_brightness"
        case changeVolume = "change_volume"
        case searchInternet = "search_internet"
        case getEMR = "get_EMR"
        case getECG = "get_ECG"

        init?(from string: String) {
            switch string {
            case "lookup_calendar":
                self = .lookupCalendar
            case "change_brightness":
                self = .changeBrightness
            case "change_volume":
                self = .changeVolume
            case "search_internet":
                self = .searchInternet
            case "get_EMR":
                self = .getEMR
            case "get_ECG":
                self = .getECG
            default:
                return nil
            }
        }
    }

    let tool: ToolCalls
}

class ToolsHandler {
    private static var groqKey = "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"

    private static let config = OpenAI.Configuration(token: groqKey, host: "api.groq.com", scheme: "https")
    private let openAI = OpenAI(configuration: config)
    private let groqModel = "llama3-groq-70b-8192-tool-use-preview"

    func invokeTools(_ t: Tools, arguments: String?) async -> String {
        let args = arguments?.toDictionary()

        switch t.tool {
        case .lookupCalendar:
            return """
            {
                events:[
                        {
                            id:1233,
                            name: Meeting with CEO,
                            startTime:2024/07/08 10:00 AM,
                            endTime:2024/07/08 11:00 AM,
                        },
                        {
                            id:85878,
                            name: Lunch With Joe,
                            startTime:2024/07/08 12:00 PM,
                            endTime:2024/07/08 1:00 PM,
                        },
                    ]
            }
            """
        case .changeBrightness:
            let action = args!["action_type"] as! String
            print("Asked to \(action) the brightness")
            if action == "Increase" {
                return "Device Brightness Increased"
            } else {
                return "Device Brightnes Decreased"
            }
        case .changeVolume:
            let action = args!["action_type"] as! String
            print("Asked to \(action) the volume")
            if action == "Increase" {
                return "Device Volume Increased"
            } else {
                return "Device Volume Decreased"
            }
        case .searchInternet:
            let topic = args!["query"] as! String
            print("Searching internet about \(topic)")
            let url = URL(string: "https://google.serper.dev/news")!

            let parameters: [String: String] = [
                "q": topic
            ]
            let jsonData = try! JSONSerialization.data(withJSONObject: parameters, options: [])
            // Create the request
            var request = URLRequest(url: url)
            request.httpMethod = "POST"
            request.setValue("application/json", forHTTPHeaderField: "Content-Type")
            request.setValue("5f5381c914125b3dbc899a123e53b8e3208a7def", forHTTPHeaderField: "X-API-KEY")
            request.httpBody = jsonData

            do {
                // Perform the request
                let (data, _) = try await URLSession.shared.data(for: request)

                if let result = String(data: data, encoding: .utf8) {
                    return result
                } else {
                    return URLError(.badServerResponse).failureURLString!
                }
            } catch {
                return "Something went wrong \(error)"
            }
        case .getEMR:
            let id = args!["ID"] as! String
            print("Getting EMR of a patient id of \(id)....")

            let msgs =
                [
                    ChatQuery.ChatCompletionMessageParam(role: .system, content: "You're a medical expert assistant, great at creating EMR's. Create Detailed and Precise EMR for provided patient ID. Always create EMR with close to real life data, do not use standard names like John Doe.")!,
                    ChatQuery.ChatCompletionMessageParam(role: .user, content: "Generate a detailed EMR for patient with ID of \(id), Return as JSON Object")!
                ]

            let toolQuery = ChatQuery(
                messages: msgs, model: groqModel
            )

            do {
                let result = try await openAI.chats(query: toolQuery)
                print("Patient's EMR is : \(result.choices[0].message.content!)")
                return "Patient's EMR is : \(result.choices[0].message.content!)"
            } catch {
                return "Error in Getting Patient's EMR"
            }
        case .getECG:
            let id = args!["ID"] as! String
            print("Getting ECG of a patient id of \(id)....")

            let msgs =
                [
                    ChatQuery.ChatCompletionMessageParam(role: .system, content: "You're a medical expert assistant, great at creating ECG's. Create Detailed and Precise ECG for provided patient ID. Always create EMR with close to real life data, do not use standard names like John Doe.")!,
                    ChatQuery.ChatCompletionMessageParam(role: .user, content: "Generate a detailed ECG for patient with ID of \(id), Return as JSON Object")!
                ]

            let toolQuery = ChatQuery(
                messages: msgs, model: groqModel
            )

            do {
                let result = try await openAI.chats(query: toolQuery)
                print("Patient's ECG is : \(result.choices[0].message.content!)")
                return "Patient's ECG is : \(result.choices[0].message.content!)"
            } catch {
                return "Error in Getting Patient's ECG"
            }
        }
    }
}
