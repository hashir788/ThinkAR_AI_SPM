//
//  MBGlassesAutocueService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2024/3/20.
//

#import <Foundation/Foundation.h>
#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN

@interface MBGlassesAutocueService : MBDeviceFrameService

/// 【MB-request-获取提词器显示区域尺寸】
+ (void)requestScreenSize:(nullable void(^)(CGSize))completion;

/// 【获取提词器支持字体尺寸列表】
+ (void)requestFontList:(nullable void(^)(NSArray<NSData *> *))completion;

/// 【获取提词器当前字体序号】
+ (void)requestCurrentFont:(nullable void(^)(NSInteger))completion;

/// 【设置提词器当前字体序号】
+ (void)syncFont:(NSInteger)fontIndex completion:(nullable void(^)(BOOL))completion;

+ (void)sendText:(NSString *)text pageIndex:(NSInteger)pageIndex totalSize:(NSInteger)totalSize completion:(nullable void(^)(BOOL))completion;

+ (void)addFlip:(NSString *)tag listener:(void(^)(NSInteger))listener;

+ (void)removeFlipListener:(NSString *)tag;

/// 【MB-request-提词器开始演讲】
+ (void)startSpeech:(nullable void(^)(BOOL))completion;

+ (void)addStartSpeech:(NSString *)tag listener:(void(^)(void))listener;

/// 【MB-request-提词器结束演讲】
+ (void)stopSpeech:(nullable void(^)(BOOL))completion;

/// 【MB-request-提词器结束演讲监听】
+ (void)addStopSpeech:(NSString *)tag listener:(void(^)(void))listener;

+ (void)removeStopSpeech:(NSString *)tag;

/// 【MB-request-获取演讲时间】
+ (void)requestSpeechTime:(nullable void(^)(NSInteger))completion;

@end

NS_ASSUME_NONNULL_END
