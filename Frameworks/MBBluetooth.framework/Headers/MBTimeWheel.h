//
//  MBTimeWheel.h
//  MBTimeWheel
//
//  Created by chenxiuwu on 2023/6/16.
//

#import <Foundation/Foundation.h>
#import "MBTimeout.h"

NS_ASSUME_NONNULL_BEGIN

@interface MBTimeWheel : NSObject

/// event default mainQueue
@property (nonatomic, strong) dispatch_queue_t dispatchQueue;

@property (nonatomic, assign, readonly) int64_t tickDuration;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

/// 初始化一个时间轮结构
/// - Parameters:
///   - ticks: the size of the time wheel, 如果传入的不是2的N次方，则会调整为大于等于该参数的第一个2的N次方，好处是可以优化hash值的计算
///   - tickDuration: the duration between tick
///   - maxPendingTimeouts: 最大的pending数量（时间轮中任务的最大数量），超过这个值之后调用将抛出异常，0或者负数表示没有限制，默认为-1
///   - taskQueue: 时间轮执行任务所在串行队列
- (instancetype)initWithTicks:(int64_t)ticks
                 tickDuration:(int64_t)tickDuration
           maxPendingTimeouts:(int64_t)maxPendingTimeouts
                    taskQueue:(nullable dispatch_queue_t)taskQueue;

- (void)addTimeout:(MBTimeout *)timeout;

- (MBTimeout *)addTask:(NSString *)identifier retryLimit:(NSInteger)retryLimit timeout:(int64_t)timeout completedHandler:(dispatch_block_t)handler;

- (void)removeTimeout:(MBTimeout *)timeout;

- (void)removeAll;

- (void)stop;

@end

NS_ASSUME_NONNULL_END
