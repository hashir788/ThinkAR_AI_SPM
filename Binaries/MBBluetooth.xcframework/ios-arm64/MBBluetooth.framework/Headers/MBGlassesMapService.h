//
//  MBGlassesMapService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/7/31.
//

#import <UIKit/UIKit.h>
#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString *MBMapNavigationPageName NS_STRING_ENUM;
/// 语音搜索地址或选择常用地址
UIKIT_EXTERN MBMapNavigationPageName const MBMapNavigationPageNameSearchAddress;
/// 选择导航方式：`步行`或`骑行`
UIKIT_EXTERN MBMapNavigationPageName const MBMapNavigationPageNameSelectTraffic;
/// 提醒用户设置常用地址`回家`和`公司`地址
UIKIT_EXTERN MBMapNavigationPageName const MBMapNavigationPageNameRemaindSetAddress;
/// 从地址列表中选择地址
UIKIT_EXTERN MBMapNavigationPageName const MBMapNavigationPageNameAddresses;
/// 回到App首页
UIKIT_EXTERN MBMapNavigationPageName const MBMapNavigationPageNameHomepage;
/// 正在导航界面
UIKIT_EXTERN MBMapNavigationPageName const MBMapNavigationPageNameNavigation;
/// 用户未同意高德地图隐私协议
UIKIT_EXTERN MBMapNavigationPageName const MBMapNavigationPageNameUnAuthenticated;

UIKIT_EXTERN MBMapNavigationPageName const MBMapNavigationPageNameCalibration;

UIKIT_EXTERN MBMapNavigationPageName const MBMapNavigationPageNameChatGPT;

/// 地图导航相关命令
@interface MBGlassesMapService : MBDeviceFrameService

/// 【进入导航】
+ (void)syncEnterNavigation:(nullable void(^)(BOOL))completion;

/// 【开始导航】
+ (void)syncStartNavigation:(nullable void(^)(BOOL))completion;

/// 【结束导航】
+ (void)syncStopNavigation:(nullable void(^)(BOOL))completion;

///// 【获取导航时屏幕常亮】
//+ (void)requestNavigationKeepBright;

/// 【设置导航时屏幕常亮】
+ (void)syncNavigationKeepBrightState:(BOOL)isOn completion:(nullable void(^)(BOOL))completion;

/// 【导航下发页面枚举值】
+ (void)syncNavigationPageName:(MBMapNavigationPageName)pageName
                    completion:(nullable void(^)(BOOL))completion ;

/// `UIImage`转化为l4格式数据
/// - Parameter image: 待转换的图片
+ (nullable NSData *)image2L4Data:(UIImage *)image;

/// 同步导航数据
/// - Parameters:
///   - guideInfo: 导航信息
///   - timeRemaing: 导航剩余时间
///   - flag: 导航类型
///   - highlighted: 导航高亮
///   - image: 导航图标
+ (void)syncAmapBinaryPacket:(NSString *)guideInfo
                 timeRemaing:(NSString *)timeRemaing
                        flag:(UInt32)flag
                 highlighted:(NSString *)highlighted
                       image:(UIImage *)image
                  completion:(nullable void(^)(BOOL))completion ;

/// 获取地图导航标定结果
+ (void)requestCalibStatus:(nullable void(^)(BOOL))completion;

/// 添加开始导航监听
+ (void)addStartNavigationListener:(void(^)(void))listener;

/// 添加地图导航标定结果监听
+ (void)addCalibStatusListener:(void(^)(BOOL))listener;

+ (void)addFlipListener:(void(^)(NSString * _Nullable, NSInteger))listener ;

+ (void)addPageGestureListener:(void(^)(NSString * _Nullable, NSInteger))listener;

@end

NS_ASSUME_NONNULL_END
