//
//  File.swift
//
//
//  Created by Mohamed Hashir on 2024-08-02.
//

import Foundation

public protocol ThinkARAIProtocol {
    /// List of conversations: Type of ``Conversation``
    @Published var conversations: [Conversation]
    /// List of Errors
    @Published var conversationErrors: [Conversation.ID: Error]
    /// Currently selected conversation ID
    @Published var selectedConversationID: Conversation.ID?
    
    /// Currently selected conversation
    public var selectedConversation: Conversation?
    
    /// Selected conersation publisher
    public var selectedConversationPublisher: AnyPublisher<Conversation?, Never>

    /// Function that adds messages to a conversation
    /// - Parameters:
    ///   - message: The message to be added to the conversation. Type of ``Message``
    ///   - conversationId: ID of the current conversation. Type of ``Conversation.ID``
    /// - Returns: Void
    public func addMessage(message: Message, conversationId: Conversation.ID) async
    
    /// Function that adds a voice message. Audio is transcribed and then a message is added
    /// - Parameters:
    ///   - audio: Audio file to be transcribed. Type of ``Data``
    ///   - fileType: Type of the audio file. ``AudioTranscriptionQuery.FileType``
    ///   - conversationId: ID of the conversation ``String``
    public func addVoiceMessage(audio: Data, fileType: AudioTranscriptionQuery.FileType, conversationId: String)
    
    /// Function that transalte a message from one to another language
    /// - Parameters:
    ///   - audio: Audio file to be translated. Type of ``Data``
    ///   - fileType: Type of the audio file. ``AudioTranslationQuery.FileType``
    ///   - conversationId:  ID of the conversation ``String``
    public func addTranslationMessage(audio: Data, fileType: AudioTranslationQuery.FileType, conversationId: String)
    
    /// Function that creates a conversation
    /// - Returns: ID of the created conversation
    public func createConversation() -> String
    
    /// Select/set a conversation from list of conversaitons
    /// - Parameter conversationId: ID of the converastion to be selcted/set ``String``
    public func selectConversation(_ conversationId: Conversation.ID?)
    
    /// Function to delete a conversation
    /// - Parameter conversationId: ID of the converastion to be deleted ``String``
    public func deleteConversation(_ conversationId: Conversation.ID)
}
