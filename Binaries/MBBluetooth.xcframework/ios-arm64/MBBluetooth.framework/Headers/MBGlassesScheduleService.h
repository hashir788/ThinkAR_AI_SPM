//
//  MBGlassesScheduleService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/8/1.
//

#import "MBDeviceFrameService.h"
#import "MBBatchRequest.h"
NS_ASSUME_NONNULL_BEGIN

/// 日程相关命令
@interface MBGlassesScheduleService : MBDeviceFrameService

/// 【获取全部日程key】
+ (void)requestAllSchedules:(nullable void(^)(NSArray<NSString *> *))completion;

+ (MBBatchRequest *)requestSchedulesWithKeys:(NSArray<NSString *> *)keys;

+ (NSDictionary<NSString *, id> *)praseResponse:(MBGlassesResponse *)response;

/// 【获取一条日程】
+ (void)requestScheduleByKey:(UInt16)key completion:(nullable void(^)(NSDictionary<NSString *, id> *))completion;

/// 【新增日程】
+ (void)addScheduleWithTitle:(NSString *)title
                   startDate:(NSDate *)startDate
                     endDate:(NSDate*)endDate
                  remindTime:(NSInteger)remindTime
                  completion:(nullable void(^)(NSInteger))completion;

/// 【修改日程】
+ (void)updateScheduleWithTitle:(NSString *)title
                      startDate:(NSDate *)startDate
                        endDate:(NSDate*)endDate
                     remindTime:(NSInteger)remindTime
                         taskId:(UInt16)taskId
                     completion:(nullable void(^)(BOOL))completion;

/// 【删除日程】
+ (void)deleteScheudleByKey:(UInt16)key completion:(nullable void(^)(BOOL))completion;

+ (void)syncAccessStatus:(BOOL)isOpen completion:(nullable void(^)(BOOL))completion;

@end

NS_ASSUME_NONNULL_END
