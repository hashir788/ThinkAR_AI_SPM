//
//  MBGlassesInfoService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/7/28.
//

#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(UInt8, MBGlassesLanguage) {
    MBGlassesLanguageCN,
    MBGlassesLanguageEN
};

/// AR眼镜通用服务
/// 发送设备信息相关命令
@interface MBGlassesInfoService : MBDeviceFrameService

/// 【获取设备信息】
+ (void)requestDeviceInfo:(nullable void(^)(BOOL, BOOL))completion;

/// 【设置外设语言】
/// - Parameter language: 设置语言
+ (void)syncAppLanguage:(UInt8)language completion:(nullable void(^)(BOOL))completion;

/// 【设置系统时间】
+ (void)syncSystemTime:(nullable void(^)(BOOL))completion;

/// 【设置为iOS系统】
+ (void)syncPhoneModel:(nullable void(^)(BOOL))completion;

/// 【设置勿扰模式】
+ (void)syncDNDModel:(BOOL)isQuiet completion:(nullable void(^)(BOOL))completion;

+ (void)syncBluetoothName:(NSString *)name completion:(nullable void(^)(BOOL))completion;

#pragma mark -- 眼镜屏幕亮度相关命令
/// 获取眼镜屏幕亮度
+ (void)requestScreenBrightness:(nullable void(^)(NSInteger))completion;

+ (void)syncScreenBrightnessListener:(void(^)(NSInteger))listener;

+ (void)removeScreenBrightnessListener;
/// 设置
/// - Parameter value: 屏幕亮度值
+ (void)syncScreenBrightness:(NSInteger)value completion:(nullable void(^)(BOOL))completion;

/// 【查询自动息屏时间】
+ (void)requestScreenOffTime:(nullable void(^)(NSInteger))completion;

/// 【设置自动息屏时间】
+ (void)syncScreenOffTime:(NSInteger)value completion:(nullable void(^)(BOOL))completion;

/// 【查询屏幕亮度模式】
+ (void)requestScreenBrightnessMode:(nullable void(^)(BOOL))completion;

/// 【设置屏幕亮度模式】
+ (void)syncScreenBrightnessMode:(BOOL)isAuto completion:(nullable void(^)(BOOL))completion;

/// 【查询屏幕点亮方式】 0x01:左眼， 0x02:右眼 0x00:关闭单眼模式（自动打开双眼模式）
+ (void)requestScreenLighten:(nullable void(^)(NSInteger))completion;

/// 【屏幕点亮方式设置】0x01:左眼， 0x02:右眼 0x00:关闭单眼模式（自动打开双眼模式）
+ (void)syncScreenLighten:(NSInteger)value completion:(nullable void(^)(BOOL))completion;
/// 【查询设备语言】
+ (void)getDeviceCurrentLanguage:(nullable void(^)(NSInteger))completion;

+ (void)addGlassLanguageListener:(void(^)(NSInteger))listener;
#pragma mark -- BT状态
/// 【查询bt状态】
+ (void)requestBTState:(nullable void(^)(BOOL))completion;

/// 【关闭bt状态】
+ (void)syncDisconnectBT:(nullable void(^)(BOOL))completion;

+ (void)requestReconnectBT:(nullable void(^)(BOOL))completion;

/// 【监听bt状态】
+ (void)addBTStateListener:(void(^)(BOOL))listener;

+ (void)removeBTStateListener;

#pragma mark -【恢复出厂设置】

/// 【恢复出厂设置】
+ (void)requestFactoryReset:(nullable void(^)(BOOL))completion;

/// 【恢复出厂设置-重启】
+ (void)requestFactoryReboot:(nullable void(^)(BOOL))completion;

/// 【退出登录】
+ (void)syncLogout:(nullable void(^)(BOOL))completion;

#pragma mark - 外设电量
/// 【MB-request-查询电量】
+ (void)requestBatteryInfo:(nullable void(^)(NSInteger, BOOL))completion;

/// 【MB-request-虚拟电量】
+ (void)requestVirtualPower:(NSData *)data completion:(nullable void(^)(BOOL isSuccess, BOOL state, NSUInteger level))completion;
/// 【MB-request-日志切换】
/// - Parameters:
///   - data: 设置data=nil时命令为get，否则命令为set
+ (void)requestLogSourceCompletion:(void (^)(BOOL isSuccess, Byte state))completion;
+ (void)setupLogSourceWithData:(NSData *)data completion:(void (^)(BOOL isSuccess))completion;

/// 【MB--notify--电池电量监听】
+ (void)addBatteryListener:(void(^)(NSInteger, BOOL))listener;

+ (void)addBatteryListenerByTag:(NSString *)tag listener:(void(^)(NSInteger, BOOL))listener;

+ (void)removeBatteryListener;

+ (void)removeBatteryListenerForTag:(NSString *)tag;

/// 【查询低电量处理方式】
+ (void)requestLowBatteryModel:(nullable void(^)(BOOL))completion;

///【MB-request-设置低电量模式】
+ (void)syncLowBatteryModel:(BOOL)model completion:(nullable void(^)(BOOL))completion;

@end

NS_ASSUME_NONNULL_END
