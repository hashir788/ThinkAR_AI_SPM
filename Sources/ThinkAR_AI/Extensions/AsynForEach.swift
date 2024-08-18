//
//  File.swift
//
//
//  Created on 2024-08-09.
//

import Foundation

extension Array {
    func asyncForEach(_ operation: @escaping (Element) async throws -> Void) async rethrows {
        for element in self {
            try await operation(element)
        }
    }
}
