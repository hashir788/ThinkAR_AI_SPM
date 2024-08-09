//
//  MBGlassesNotificateService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/8/1.
//

#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString *MBAppBundleIdentifer NS_STRING_ENUM;

UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferPhone;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferMessages;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferMain;

UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferWechat;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferDindTalk;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferFeishu;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferMeituan;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferWeCom;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferQQ;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferEleme;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferHema;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferPpcs;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferDingdong;

UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferTemu;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferSHEIN;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferTikTok;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferWhatsApp;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferInstagram;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferLine;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferTelegram;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferSnapchat;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferFacebook;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferCashApp;

UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferSoul;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferSinaweibo;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferThreads;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferUCBrower;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferNewsDypay;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferTwitter;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferAMIHexin;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferFzzqxf;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferRobinhood;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferTradingview;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferTodayHabit;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferOffscreen;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferHabify;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferProductive;
UIKIT_EXTERN MBAppBundleIdentifer const MBAppBundleIdentiferNextdoor;

@interface MBAppNotification : NSObject

/// 包名
@property (nonatomic, copy) MBAppBundleIdentifer bundleIdentifier;

/// 第三方App的URL scheme
@property (nonatomic, copy) NSString *scheme;

@property (nonatomic, copy) NSString *appName;

@property (nonatomic, copy) NSString *imageName;

@property (nonatomic, copy) NSString *sortKey;

/// 消息通知的开关是否打开
@property (nonatomic, assign) BOOL isOn;

/// 第三方App是否安装在手机上
@property (nonatomic, assign) BOOL isInstalled;

@property (nonatomic, assign) BOOL isEnabled;

- (instancetype)initWithData:(NSData *)data;

@end

/// 消息通知开关状态相关命令
@interface MBGlassesNotificateService : MBDeviceFrameService

+ (void)syncAppSwitch:(MBAppBundleIdentifer)identifer isOn:(BOOL)isOn completion:(nullable void(^)(BOOL))completion;

+ (void)requestAllSwitchs:(nullable void(^)(NSArray<MBAppNotification*>*))completion;


@end

NS_ASSUME_NONNULL_END
