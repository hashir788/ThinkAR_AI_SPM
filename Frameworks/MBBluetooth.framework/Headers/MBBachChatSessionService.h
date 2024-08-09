//
//  MBBachChatSessionService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/12/20.
//

#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN

@interface MBBachDevice : NSObject

@property (nonatomic, copy) NSString *mac;

@property (nonatomic, copy) NSString *name;

- (instancetype)initWithName:(NSString *)name mac:(NSString *)mac;

@end

@interface MBBachChatSessionService : MBDeviceFrameService

+ (void)addListenChatSessionStart:(void(^)(BOOL))listener;

+ (void)addListenChatSessionStop:(void(^)(BOOL))listener;

+ (void)syncStopChatSession:(nullable void(^)(BOOL))completion;

+ (void)addListenChatSessionStarScan:(void(^)(BOOL))listener;

+ (void)syncDeveices:(NSArray<MBBachDevice*> *)devices completion:(nullable void(^)(BOOL))completion;

+ (void)addListenChatSessionInviter:(void(^)(MBBachDevice*))listener;

+ (void)inviterDevice:(MBBachDevice *)device completion:(nullable void(^)(BOOL))completion;

+ (void)addListenInviterResult:(void(^)(BOOL, MBBachDevice*))listener;

+ (void)syncInviterResult:(BOOL)isAcceptTheInvitation completion:(nullable void(^)(BOOL))completion;

//+ (void)addListenRecordingStatus:(void(^)(BOOL))listener;

+ (void)syncRecordingStatus:(BOOL)isRecording completion:(nullable void(^)(BOOL))completion;


/// send text content to peripheral
/// - Parameters:
///   - content: text content
///   - type: (类型包括：-1：识音错误，-2：其他错误 0x01:发起者说话内容 0x02:接受者说话内容)
///   - completion: Send a result callback
+ (void)syncContent:(NSString *)content type:(NSInteger)type completion:(nullable void(^)(BOOL))completion;

#pragma mark -- auto refuse ivniter switch
+ (void)requestRefuseInviterStatus:(nullable void(^)(BOOL))completion;

+ (void)syncRefuseInviterStatus:(BOOL)isRefuse completion:(nullable void(^)(BOOL))completion;

+ (void)syncNetDisconnect:(nullable void(^)(BOOL))completion;

@end

NS_ASSUME_NONNULL_END
