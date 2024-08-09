//
//  MBGlassesTranslateService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/8/1.
//

#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN
/// 翻译和提词器相关命令
@interface MBGlassesTranslateService : MBDeviceFrameService

/// 【提词器-发送文本】
+ (void)sendTeleprompterText:(NSString *)text
                   pageIndex:(NSInteger)pageIndex
                   totalSize:(NSInteger)totalSize
                  completion:(nullable void(^)(BOOL))completion;

/// 【提词器-下一页】
//+ (void)syncTeleprompterNextPage:(BOOL)isPageUp;

+ (void)addTeleprompterFlip:(NSString *)tag listener:(void(^)(NSInteger))listener;

+ (void)removeTeleprompterFlipListener:(NSString *)tag;

/// 【获取提词器支持字体尺寸列表】
+ (void)requestTeleprompterFontList:(nullable void(^)(NSArray<NSString *> *))completion;

/// 【获取提词器当前字体序号】
+ (void)requestTeleprompterFont:(nullable void(^)(NSInteger))completion;

/// 【设置提词器当前字体序号】
+ (void)syncTeleprompterFont:(NSInteger)fontIndex completion:(nullable void(^)(BOOL))completion;

/// 【MB-request-获取提词器显示区域尺寸】
+ (void)requestTeleprompterArea:(nullable void(^)(CGSize))completion;

/// 【MB-request-提词器开始演讲】
+ (void)teleprompterStartSpeech:(nullable void(^)(BOOL))completion;
+ (void)teleprompterStartSpeechRsp:(nullable void(^)(BOOL))completion;

+ (void)addTeleprompterStartSpeech:(nullable NSString *)tag listener:(void(^)(void))listener;

/// 【MB-request-提词器结束演讲】
+ (void)teleprompterStopSpeech:(nullable void(^)(BOOL))completion;
/// 【MB-request-提词器结束演讲监听】
+ (void)teleprompterStopSpeech:(NSString *)tag listener:(void(^)(void))listener;
+ (void)removeTeleprompterStopSpeech:(NSString *)tag;
/// 【MB-request-获取演讲时间】
+ (void)requestTeleprompterSpeechTime:(nullable void(^)(NSInteger))completion;

+ (void)requestOpenHFP:(nullable void(^)(BOOL))completion;

+ (void)startTranslation:(NSInteger)role language:(NSInteger)language completion:(nullable void(^)(BOOL))completion;

///【MB-request- 语音实时翻译结束】
+ (void)stopTranslation:(nullable void(^)(BOOL))completion;

/// 【MB-request- 指定讲话语言】
+ (void)syncTranslateLanguage:(NSInteger)language completion:(nullable void(^)(BOOL))completion;

/// 【MB-request- 翻译讲话使能】
+ (void)syncTranslationSpeak:(NSInteger)role completion:(nullable void(^)(BOOL))completion;

/// 【MB-request- 文本更新】
+ (void)updateTranslateTextRole:(NSInteger)role sessionId:(NSInteger)sessionId session:(NSString *)session completion:(nullable void(^)(BOOL))completion;

+ (void)syncTranslateTextRole:(NSInteger)role sessionId:(UInt8)sessionId session:(NSString *)session completion:(nullable void(^)(BOOL))completion;

/// 【MB-request-录音控制开关】
+ (void)addMicrophoneListener:(void(^)(BOOL))listener;

+ (void)addMicrophoneWithTag:(NSString *)tag listener:(void(^)(BOOL))listener;

+ (void)syncMicrophoneSwitch:(BOOL)isOn completion:(nullable void(^)(BOOL))completion;

+ (void)removeMicrophoneListener;

/// 【MB-request-翻译-结束】
+ (void)addEndSpeechListener:(void(^)(BOOL))listener;

+ (void)removeEndSpeechListener;

@end

NS_ASSUME_NONNULL_END
