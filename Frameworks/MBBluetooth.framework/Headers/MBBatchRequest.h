//
//  MBBatchFrames.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/7/27.
//

#import <Foundation/Foundation.h>
#import "MBFrameProtocol.h"
#import "MBBluetoothDevice.h"
NS_ASSUME_NONNULL_BEGIN

/// 假设有A,B,C,D 4个任务
/// 如果为链式请求，则下一个任务会等待上一个任务结束后再发送，即 A->B->C->D
/// 如果为非链式请求，则发送所有请求，即(A,B,C,D) -> 外设
/// - note: 当`MBBatchRequest`调用`-start:`后，再添加任务不会生效。
@class MBGlassesResponse;
@interface MBBatchRequest : NSObject

@property (nonatomic, strong, nullable) id<MBBluetoothDevice> device;

@property (nonatomic, copy, readonly) NSString *identifier;

/// 是否为链式发送请求
@property (nonatomic, assign, readonly) BOOL isChain;
/// 批量任务是否已完成
///
@property (nonatomic, assign, readonly) BOOL isFinished;

/// 当其中任务发生错误时是否继续下一个任务，默认NO;
@property (nonatomic, assign) BOOL isContinuAfterErrors;

/// 单个任务回调
@property (nonatomic, copy, nullable) void (^completion)(MBGlassesResponse *);

/// 所有任务完成时的统一回调
@property (nonatomic, copy, nullable) void (^completedHandler)(NSArray<MBGlassesResponse *> *);

- (instancetype)initWithDevice:(id<MBBluetoothDevice>)device isChain:(BOOL)isChain;

- (instancetype)initWithDevice:(id<MBBluetoothDevice>)device identifier:(NSString *)identifier isChain:(BOOL)isChain;

- (void)addFrame:(id<MBFrameProtocol>)frame;

- (void)addFrames:(NSArray<id<MBFrameProtocol>> *)frames;

- (void)startWithCompletion:(nullable void (^)(MBGlassesResponse *))completion;

- (void)stop;

@end

NS_ASSUME_NONNULL_END
