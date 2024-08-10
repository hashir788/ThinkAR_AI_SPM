//
//  File.swift
//  
//
//  Created by Mohamed Hashir on 2024-08-10.
//

import SwiftUI

private struct IDProviderKey: EnvironmentKey {
    static let defaultValue: () -> String = {
        UUID().uuidString
    }
}

extension EnvironmentValues {
    public var idProviderValue: () -> String {
        get { self[IDProviderKey.self] }
        set { self[IDProviderKey.self] = newValue }
    }
}

extension View {
    public func idProviderValue(_ idProviderValue: @escaping () -> String) -> some View {
        environment(\.idProviderValue, idProviderValue)
    }
}
