//
//  MBTimeout.h
//  MBTimeWheel
//
//  Created by chenxiuwu on 2023/6/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^MBTimeoutTask)(BOOL isCancelled);

@interface MBTimeout : NSObject<NSCopying>

/// 任务唯一标志
@property (nonatomic, copy  , readonly) NSString *identifer;

/// The total number of times the request is allowed to be retried.
@property (nonatomic, assign, readwrite) NSInteger retryLimit;

@property (nonatomic, assign, readonly) int64_t interval;

@property (nonatomic, assign, readwrite) int64_t remainingRounds;

@property (nonatomic, assign, readonly) BOOL isCancelled;

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

/// 初始化超时任务
/// - Parameters:
///   - interval: 超时时间
///   - workTask: 超时后执行的任务
/// - Note:
///    identifer: 默认为[NSUUID uuid]
///    retryLimit: 默认为3
- (instancetype)initWithInterval:(int64_t)interval workTask:(dispatch_block_t)workTask;


/// 初始化超时任务
/// - Parameters:
///   - interval: 超时时间
///   - identifer: 任务id
///   - retryLimit: 任务超时后重试次数
///   - workTask: 超时后执行的任务
- (instancetype)initWithInterval:(int64_t)interval
                       identifer:(NSString *)identifer
                      retryLimit:(NSInteger)retryLimit
                        workTask:(dispatch_block_t)workTask NS_DESIGNATED_INITIALIZER;

- (void)perform;

- (void)cancel;

@end

NS_ASSUME_NONNULL_END
