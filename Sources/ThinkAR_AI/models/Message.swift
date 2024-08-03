//
//  File.swift
//  
//
//  Created by Mohamed Hashir on 2024-08-01.
//

import Foundation


public struct Message{
    
    public init(id: String, content: String, role: String, createdAt: Date) {
        self.id = id
        self.content = content
        self.role = role
        self.createdAt = createdAt
    }
    
    var id:String;
    var content:String;
    var role:String;
    var createdAt:Date
}
