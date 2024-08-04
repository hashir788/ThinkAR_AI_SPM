//
//  File.swift
//  
//
//  Created by Mohamed Hashir on 2024-08-04.
//

import Foundation
import SwiftOpenAI

extension Model {
   /// ### Llama model
   /// As of 2024-08-04, this is a new model from OpenAI.
   /// From their [docs](https://platform.openai.com/docs/models/llama):
   ///
   ///   > Llama is designed to provide high performance for specialized tasks, offering superior capabilities
   ///   > in natural language understanding and generation. It excels in specific domains and offers customization
   ///   > options for tailored applications.
   ///
   case llama

   public var value: String {
      switch self {
      case .llama: return "llama"
      default: return "" // Handles cases not related to the Llama model
      }
   }
}
