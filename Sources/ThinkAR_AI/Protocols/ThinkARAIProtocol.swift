//
//  File.swift
//
//
//  Created by Mohamed Hashir on 2024-08-02.
//

import Foundation

import Combine
import Foundation

public protocol ThinkARAIProtocol {
    /// List of conversations: Type of ``Conversation``
    var conversations: [Conversation] { get set }
    /// List of Errors
    var conversationErrors: [Conversation.ID: Error] { get set }
    /// Currently selected conversation ID
    var selectedConversationID: Conversation.ID? { get set }
    
    /// Currently selected conversation
    var selectedConversation: Conversation? { get }
    
    /// Selected conversation publisher
    var selectedConversationPublisher: AnyPublisher<Conversation?, Never> { get }
    
    /// Function that adds messages to a conversation
    /// - Parameters:
    ///   - message: The message to be added to the conversation. Type of ``Message``
    ///   - conversationId: ID of the current conversation. Type of ``Conversation.ID``
    /// - Returns: Void
    func addMessage(message: Message, conversationId: Conversation.ID) async
    
    /// Function that adds a voice message. Audio is transcribed and then a message is added
    /// - Parameters:
    ///   - audio: Audio file to be transcribed. Type of ``Data``
    ///   - fileType: Type of the audio file. ``String``
    ///   - conversationId: ID of the conversation. Type of ``Conversation.ID``
    func addVoiceMessage(audio: Data, fileType: String, conversationId: Conversation.ID) async
    
    /// Function that translates a message from one language to another
    /// - Parameters:
    ///   - audio: Audio file to be translated. Type of ``Data``
    ///   - fileType: Type of the audio file. ``String``
    ///   - conversationId: ID of the conversation. Type of ``Conversation.ID``
    func addTranslationMessage(audio: Data, fileType: String, conversationId: Conversation.ID) async
    
    /// Function that will create an audio speech using passed input text
    /// - Parameter input: Input to be created as audio speech ``String``
    func createAudioSpeech(input: String) -> Data async
    
    /// Function that creates a conversation
    /// - Returns: ID of the created conversation
    func createConversation() -> Conversation.ID
    
    /// Select/set a conversation from list of conversations
    /// - Parameter conversationId: ID of the conversation to be selected/set. Type of ``Conversation.ID``
    func selectConversation(_ conversationId: Conversation.ID?)
    
    /// Function to delete a conversation
    /// - Parameter conversationId: ID of the conversation to be deleted. Type of ``Conversation.ID``
    func deleteConversation(_ conversationId: Conversation.ID)
}
