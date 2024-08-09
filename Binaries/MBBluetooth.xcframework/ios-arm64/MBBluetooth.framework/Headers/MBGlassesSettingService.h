//
//  MBGlassesSettingService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/8/16.
//

#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (UInt8, MBRemoteControlAction) {
    /** 触控条前滑 */
    MBRemoteControlActionTouchBarForward     = 0x00,
      /** 触控条后滑 */
    MBRemoteControlActionTouchBarbackward    = 0x01,
      /** 触控条单击 */
    MBRemoteControlActionTouchBarSingleClick = 0x02,
      /** 触控条长按 */
    MBRemoteControlActionTouchBarLongPress   = 0x03,
      /** 多功能键单击 */
    MBRemoteControlActionHomeSingleClick     = 0x04,
      /** 多功能键双击 */
    MBRemoteControlActionHomeDoubleClick     = 0x05,
      /** 多功能键长按 */
    MBRemoteControlActionHomeLongPress       = 0x06,
      /** 多功能键按下 */
    MBRemoteControlActionHomePress           = 0x07,
      /** 多功能键释放 */
    MBRemoteControlActionHomeReleased        = 0x08,
      /** 触摸条按下 */
    MBRemoteControlActionTouchBarPress       = 0x09,
      /** 触摸条释放 */
    MBRemoteControlActionTouchBarReleased    = 0x0A,
       /** 触控条双击 */
    MBRemoteControlActionTouchBarDoubleClick = 0x0B,
};

@interface MBGlassesSettingService : MBDeviceFrameService

+ (void)syncSimCardState:(BOOL)available completion:(nullable void(^)(BOOL))completion;

#pragma mark -- 桌面快捷菜单
/// 【同步使用的AI模型】(0:APP获取值 1: LLM(large language mode) 2: ChatGPT：3.GEMINI)
+ (void)syncAIModel:(NSInteger)fontIndex completion:(nullable void(^)(BOOL))completion;
+ (void)syncQuickDesktopSwitch:(BOOL)isOn completion:(nullable void(^)(BOOL))completion;
+ (void)requestQuickDesktopSwitch:(nullable void(^)(BOOL))completion;
+ (void)syncRemoteControlAction:(MBRemoteControlAction)action completion:(nullable void(^)(BOOL))completion;
+ (id<MBFrameProtocol>)buildFrameWithRemoteControlAction:(MBRemoteControlAction)action;
+ (void)requestQuickDesktopBrightnessState:(nullable void(^)(BOOL))completion;
#pragma mark - 佩戴检测
/// 【智能省电开关设置】
+ (void)syncSmartPowerSaving:(BOOL)isOn completion:(nullable void(^)(BOOL))completion;
/// 【智能省电开关获取】
+ (void)requestSmartPowerSaving:(nullable void(^)(BOOL))completion;
/// 【智能佩戴检测开关设置】
+ (void)syncWearCheck:(BOOL)isOn completion:(nullable void(^)(BOOL))completion;
/// 【智能佩戴检测开关获取】
+ (void)requestWearCheck:(nullable void(^)(BOOL))completion;
/// 【佩戴亮屏开关设置】
+ (void)syncWearBrightness:(BOOL)isOn completion:(nullable void(^)(BOOL))completion;
/// 【屏幕亮屏开关状态】
+ (void)requestQuickDesktopAppLightState:(nullable void(^)(BOOL))completion;
/// 【佩戴亮屏开关获取】
+ (void)requestWearBrightness:(nullable void(^)(BOOL))completion;
/// 【通知APP未佩戴超过10分钟】
+ (void)addNoWear:(NSString *)tag listener:(void(^)(void))listener;

#pragma mark - 同步QQ音乐授权状态

+ (void)syncQQMusicAuthentication:(BOOL)isAuthenticated completion:(nullable void(^)(BOOL))completion;

@end

NS_ASSUME_NONNULL_END
