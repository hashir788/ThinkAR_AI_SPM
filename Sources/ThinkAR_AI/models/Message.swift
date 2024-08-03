//
//  File.swift
//  
//
//  Created by Mohamed Hashir on 2024-08-01.
//

import Foundation


public struct Message{
   public var id:String;
   public var content:String;
   public var role:String;
    public var createdAt:Date;
    
    public init(id: String, content: String, role: String, createdAt: Date) {
        self.id = id
        self.content = content
        self.role = role
        self.createdAt = createdAt
    }
    
}
