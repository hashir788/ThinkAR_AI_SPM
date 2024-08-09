//
//  File.swift
//
//
//  Created by Mohamed Hashir on 2024-08-09.
//

import Foundation


struct Tools{
    enum ToolCalls:String {
        case calendarLookup = "calendar_lookup"
        case changeBrightness = "change_brightness"
        case changeVolume = "change_volume"
        
        init?(from string:String) {
            switch string {
            case "calendar_lookup":
                self = .calendarLookup
            case "change_brightness":
                self = .changeBrightness
            case "change_volume":
                self = .changeVolume
            default:
                return nil
            }
        }
    }
    let tool:ToolCalls
}

class ToolsHandler{
    func invokeTools(_ t:Tools) -> String {
        switch t.tool {
        case .calendarLookup:
            print("Calendar func is called")
            return "Calendar func is called"
        case .changeBrightness:
            print("Change brightness func is called")
            return "Change brightness func is called"
        case .changeVolume:
            print("Change volume func is called")
            return "Change volume func is called"
        }
    }
}
