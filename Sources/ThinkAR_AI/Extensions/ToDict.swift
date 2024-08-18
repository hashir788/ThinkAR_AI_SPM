//
//  File.swift
//
//
//  Created on 2024-08-10.
//

import Foundation

extension String {
    func toDictionary() -> [String: Any]? {
        guard let jsonData = data(using: .utf8) else {
            print("Failed to convert JSON string to Data.")
            return nil
        }

        do {
            let dict = try JSONSerialization.jsonObject(with: jsonData, options: []) as? [String: Any]
            return dict
        } catch {
            print("Failed to deserialize JSON: \(error.localizedDescription)")
            return nil
        }
    }
}
