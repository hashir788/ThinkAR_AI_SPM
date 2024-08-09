//
//  MBTanGoService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2024/3/26.
//

#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN

@interface MBTanGoService : MBDeviceFrameService

+ (void)syncAuthorizationStatus:(BOOL)isAuthorization completion:(nullable void(^)(BOOL))completion;

+ (void)addAuthorizationListener:(BOOL(^)(void))listener;

+ (void)addAccessStatusListener:(void(^)(BOOL))listener;

/// 同步健康数据
/// - Parameters:
///   - heartRate: 心率
///   - activity: 活动
///   - perspiration: 出汗
///   - calories: 卡路里
///   - temperature: 体温
///   - gsr: 皮肤电反应值
///   - completion: 同步结果回调
+ (void)syncHeartRate:(NSInteger)heartRate
             activity:(NSInteger)activity
         perspiration:(NSString *)perspiration
             calories:(NSInteger)calories
          temperature:(NSInteger)temperature
                  gsr:(NSInteger)gsr
           completion:(nullable void(^)(BOOL))completion;

@end

NS_ASSUME_NONNULL_END
