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

        init?(from string: String) {
            switch string {
            case "lookup_calendar":
                self = .lookupCalendar
            case "change_brightness":
                self = .changeBrightness
            case "change_volume":
                self = .changeVolume
            default:
                return nil
            }
        }
    }

    let tool: ToolCalls
}

class ToolsHandler {
    func invokeTools(_ t: Tools, arguments: String?) -> String {
        let args = arguments?.toDictionary()

        switch t.tool {
        case .lookupCalendar:
            print("Calendar func is called")
            return "Calendar func is called"
        case .changeBrightness:
            let action = args!["action_type"] as! String
            print("Asked to \(action) the brightness")
            if action == "Increase" {
                return "Device Brightness Increased"
            } else {
                return "Device Brightnes Decreases"
            }
        case .changeVolume:
            let action = args!["action_type"] as! String
            print("Asked to \(action) the volume")
            if action == "Increase" {
                return "Device Volume Increased"
            } else {
                return "Device Volume Decreases"
            }
        }
    }
}
