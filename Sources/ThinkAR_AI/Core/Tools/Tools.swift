//
//  File.swift
//
//
//  Created by Mohamed Hashir on 2024-08-09.
//

import Foundation
import MBBluetooth

struct Tools {
    enum ToolCalls: String {
        case lookupCalendar = "lookup_calendar"
        case changeBrightness = "change_brightness"
        case changeVolume = "change_volume"
        case getNews = "get_news"

        init?(from string: String) {
            switch string {
            case "lookup_calendar":
                self = .lookupCalendar
            case "change_brightness":
                self = .changeBrightness
            case "change_volume":
                self = .changeVolume
            case "get_news":
                self = .getNews
            default:
                return nil
            }
        }
    }

    let tool: ToolCalls
}

class ToolsHandler {
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
        case .getNews:
            let topic = args!["topic"] as! String
            print("Getting news about \(topic)")
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
        }
    }
}
