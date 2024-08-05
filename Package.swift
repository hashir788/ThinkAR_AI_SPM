// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "ThinkAR_AI",
    platforms: [.iOS(.v15), .macOS(.v14)],
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "ThinkAR_AI",
            targets: ["ThinkAR_AI"]),
    ],
    dependencies: [
//        .package(url: "https://github.com/jamesrochabrun/SwiftOpenAI", from: "3.6.2")
//        .package(url: "https://github.com/MacPaw/OpenAI", branch: "main")
        .package(url: "https://github.com/hashir788/OpenAI", branch: "main"),
    ],
    targets: [
        // Targets are the basic building blocks of a package, defining a module or a test suite.
        // Targets can depend on other targets in this package and products from dependencies.
        .target(
            name: "ThinkAR_AI", dependencies: ["OpenAI"], path: "Sources"),
        .testTarget(
            name: "ThinkAR_AITests",
            dependencies: ["ThinkAR_AI"]),
    ]
)
