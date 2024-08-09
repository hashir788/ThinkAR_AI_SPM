//
//  MBGlassesVoiceService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/7/31.
//

#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint16_t, VoiceAssistantType) {
    VoiceAssistantTypeQuestion = 1, //问题
    VoiceAssistantTypeAnswer   = 2, //答案
    VoiceAssistantTypePrompt   = 3, //提示
    VoiceAssistantTypeOpen     = 4, //打开
    VoiceAssistantTypeClose    = 5, //关闭
    VoiceAssistantTypeLcdOn    = 6, //打开屏幕
    VoiceAssistantTypeLcdOff   = 7, //关闭屏幕
    
    VoiceAssistantTypeBackHomepage = 8, //回到主页 ASSISTANT_BACK_HOME_SCR
    VoiceAssistantTypeVolInc       = 9, //音量增大
    VoiceAssistantTypeVolDec       = 10, //音量增减小
    VoiceAssistantTypeVolMute      = 11, //静音
    VoiceAssistantTypeVoleCancelMute = 12, //取消静音
    VoiceAssistantTypeVolSetMax      = 13, //设置音量最大
    VoiceAssistantTypeVolSetMin      = 14, //设置音量最小
    VoiceAssistantTypeVoleSetVal     = 15, //设置音量val
    
    /// QQ音乐控制
    VoiceAssistantTypeMusicPrev  = 16,
    VoiceAssistantTypeMusicNext  = 17,
    VoiceAssistantTypeMusicPlay  = 18,
    VoiceAssistantTypeMusicPause = 19,
    VoiceAssistantTypeQuerySchedule = 20,
    
    //打电话
    VoiceAssistantTypePhoneByName = 21,//按名称打电话
    VoiceAssistantTypePhoneByNumber = 22, //按号码打电话
    
    VoiceAssistantTypeExit,
    VoiceAssistantTypeChoice,
    VoiceAssistantTypePlayTTS ,
    VoiceAssistantTypeNone,
    
    //查看或创建日程
    VoiceAssistantTypeScheduleView   = 26,
    VoiceAssistantTypeScheduleCreate = 27,
    
    
    VoiceAssistantTypeWakeUp = 30, //唤醒语音的回调
};

typedef NS_ENUM(uint16_t, VoiceAssistantOption) {
    VoiceAssistantOptionNone = 0,
    VoiceAssistantOptionNavigation = 1,
    VoiceAssistantOptionPrompter   = 2,
    VoiceAssistantOptionTranslate  = 3,
    VoiceAssistantOptionSchedule   = 4,
    VoiceAssistantOptionContact    = 5,
    VoiceAssistantOptionMusic      = 6,
    VoiceAssistantOptionMessage    = 7,
    VoiceAssistantOptionSetting    = 8,
    VoiceAssistantOptionChatGPT    = 9
};

@interface MBGlassesNavigationObject : NSObject

@property (nonatomic, copy) NSString *poi;
@property (nonatomic, copy) NSString *address;
@property (nonatomic, assign) double distance;

@end

/// 语音助手相关命令
@interface MBGlassesVoiceService : MBDeviceFrameService

/// 【语音助手一麦克风开关-设置】
+ (void)syncMicrophoneSwitch:(BOOL)isOn
                  completion:(nullable void(^)(BOOL))completion;

/// 【语音助手一麦克风开关-获取】
+ (void)requestMicrophoneSwitch:(nullable void(^)(BOOL))completion;

/// 【语音助手一APP打开(关闭长按2S唤醒开关)-设置】
+ (void)syncVoiceWakeupSwitch:(BOOL)isOn
                   completion:(nullable void(^)(BOOL))completion;

/// 【语音助手一APP打开(关闭长按2S唤醒开关)-获取】
+ (void)requestVoiceWakeupSwitch:(nullable void(^)(BOOL))completion;

/// 【语音助手一A设置状态-唤醒】//0:结束唤醒 1:唤醒
+ (void)syncVoiceWakeupStatus:(BOOL)isOn
                      completion:(nullable void(^)(BOOL))completion;

/// 【语音助手一A设置状态-唤醒】//回复唤醒状态结果
+ (void)responseVoiceWakeupResultCompletion:(nullable void(^)(BOOL))completion;
/// 【语音助手一设置状态（双向指令）】
+ (void)addVoiceAssistantStatusListener:(void(^)(BOOL))listener;

/// 【语音助手一是否在语音应用内的状态（固件发送）】
+ (void)addVoiceStreamListener:(void(^)(BOOL))listener;

/// 语音会话内容
/// - Parameters:
///   - type: 0x01：问题，0x02：答案 0x03:提示 0x04:打开0x05：关闭
///   - data: 待发送的数据
+ (void)syncVoiceBinaryPacket:(UInt16)type
                         data:(NSData *)data
                   completion:(nullable void(^)(BOOL))completion __attribute__((deprecated("Use syncVoiceBinaryPacket:isEnd:data:completion:")));

/// 语音会话内容
/// - Parameters:
///   - type: 0x01：问题，0x02：答案 0x03:提示 0x04:打开0x05：关闭
///   - isEnd: 本次会话是否结束
///   - data: 待发送的数据
+ (void)syncVoiceBinaryPacket:(UInt16)type
                        isEnd:(BOOL)isEnd
                         data:(NSData *)data
                   completion:(nullable void(^)(BOOL))completion;

+ (void)syncContentType:(VoiceAssistantType)type
                  isEnd:(BOOL)isEnd
                   data:(NSData *)data
             completion:(nullable void(^)(BOOL))completion;

+ (void)syncVoiceMapBinaryPacket:(NSArray<MBGlassesNavigationObject*> *)array
                      completion:(nullable void(^)(BOOL))completion;

+ (void)addAudioStreamingListener:(void(^)(NSData *))listener;

+ (void)removeAudioStreamingListener;

@end

NS_ASSUME_NONNULL_END
