//
//  MBPicassoCrossScreenInputService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/11/27.
//

#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(UInt8, MBPicassoInputSessionType) {
    /** 输入无限制 */
    MBPicassoInputSessionTypeNone    = 0x00,
        /** 文本 */
    MBPicassoInputSessionTypeText    = 0x10,
        /** 数字 */
    MBPicassoInputSessionTypeNumber  = 0x20,
        /** phone */
    MBPicassoInputSessionTypePhone   = 0x30,
};

@interface MBPicassoInputSession: NSObject

@property (nonatomic, assign) UInt8 sessionId;
@property (nonatomic, assign) MBPicassoInputSessionType type;
@property (nonatomic, assign) BOOL  isPassword;
@property (nonatomic, assign) UInt16 maxLength;
@property (nonatomic, copy  ) NSString *content;

@end

@interface MBPicassoCrossScreenInputService : MBDeviceFrameService

+ (void)addAppStatusListener:(void(^)(void))listener;

+ (void)syncAppStatus:(BOOL)isActive completion:(nullable void(^)(BOOL))completion;

+ (void)addStartSessionListener:(void(^)(MBPicassoInputSession *))listener;

+ (void)addUpdateSessionListener:(void(^)(MBPicassoInputSession *))listener;

+ (void)syncText:(NSString *)text sessionId:(UInt8)sessionId completion:(nullable void(^)(BOOL))completion;

+ (void)addStopSessionListener:(void(^)(BOOL))listener;

+ (void)stopInputSessionWithCompletion:(void(^)(BOOL))completion;

+ (void)requestSettings:(void(^)(BOOL, BOOL))completion;

+ (void)syncAllowInput:(BOOL)isAllow isAnchor:(BOOL)isAnchor completion:(void(^)(BOOL))completion;

@end

NS_ASSUME_NONNULL_END
