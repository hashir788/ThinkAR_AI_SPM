//
//  MBGlassesChatGPTService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/9/20.
//

#import <Foundation/Foundation.h>
#import "MBGlassesChatGPTService.h"
#import "MBDeviceFrameService.h"
#import "MBBatchRequest.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(UInt8, MBGlassesChatGPTCmd) {
    /**APP开始GPT问答*/
    CMD_START_GPT_6C             = 0x6C,
    /**Glass开始GPT录音*/
    CMD_START_GPT_RECORDING_6D   = 0x6D,
    /**Glass结束GPT录音*/
    CMD_END_GPT_RECORDING_6E     = 0x6E,
    /**APP设置GPT问题文字*/
    CMD_SET_GPT_QUESTION_TEXT_6F = 0x6F,
    /**APP设置GPT答案文字*/
    CMD_SET_GPT_ANSWER_TEXT_70   = 0x70,
    /**APP结束GPT问答*/
    CMD_END_GPT_71               = 0x71,
    /**APP语音识别结束通知眼镜端*/
    CMD_APP_NOTIFY_GPT_RECORD_STATUS_A9  = 0xA9,
    /**APP同步播报总时长*/
    CMD_SYNC_TEXT_BROADCAST_DURATION_B4 = 0xB4,
};


@interface MBGlassesChatGPTService : MBDeviceFrameService
/**Glass监听开始GPT录音*/
+ (void)addListenChatGPTStartRecoding:(void(^)(BOOL))listener;
/**Glass监听结束GPT录音*/
+ (void)addListenChatGPTEndRecoding:(void(^)(BOOL))listener;
/**Glass开始GPT录音*/
+ (void)requestChatGPTStartRecoding:(nullable void(^)(BOOL))completion;
/**Glass结束GPT录音*/
+ (void)requestChatGPTEndRecoding:(nullable void(^)(BOOL))completion;
/**APP开始GPT问答*/
+ (void)requestChatGPTStartDialogue:(nullable void(^)(BOOL))completion;

+ (void)addListenChatGPTStartDialogue:(void(^)(BOOL))listener;
/**APP语音识别结束通知眼镜端*/
+ (void)sendChatGPTStopByAPP:(BOOL)isOn completion:(nullable void(^)(BOOL))completion;

+ (void)requestChatGPTStartDialogueRsp:(nullable void(^)(BOOL))completion;
/**APP结束GPT问答*/
+ (void)requestChatGPTEndDialogue:(nullable void(^)(BOOL))completion;
/**APP设置GPT问题文字*/
+ (void)requestSendCPTAskContext:(NSString *)text
                       sessionId:(NSInteger)sessionId
                      completion:(nullable void(^)(BOOL))completion __attribute__((deprecated("Use syncAskContent:sessionId:")));
/**APP设置GPT答案文字*/
+ (void)requestSendCPTAnswerContext:(NSString *)text
                          sessionId:(NSInteger)sessionId
                         completion:(nullable void(^)(BOOL))completio __attribute__((deprecated("Use syncAnswerContent:sessionId:")));

+ (void)syncPlayDuration:(NSTimeInterval)duration completion:(nullable void(^)(BOOL))completion;

+ (MBBatchRequest *)syncAskContent:(NSString *)text sessionId:(NSInteger)sessionId;

+ (MBBatchRequest *)syncAnswerContent:(NSString *)text sessionId:(NSInteger)sessionId;

+ (void)removeListenChatGPTEndRecoding;

+ (void)removeListenChatGPTStartRecoding;
@end

NS_ASSUME_NONNULL_END
