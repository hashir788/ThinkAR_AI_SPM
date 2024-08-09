//
//  MBDataStreamService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/9/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^MBDataStreamProgress)(UInt64 bytesReceived, UInt64 totalBytesLength);
typedef void(^MBDataStreamCompletion)(BOOL, NSError * _Nullable);

@class MBCommonData;
@interface MBDataStreamService : NSObject

@property (nonatomic, copy, readonly) NSString *path;

@property (readonly, getter=isCancelled) BOOL cancelled;
///// 执行中
//@property (readonly, getter=isExecuting) BOOL executing;
///// 完成
//@property (readonly, getter=isFinished)  BOOL finished;

@property (nonatomic, copy, nullable, readonly) MBDataStreamProgress   progress;
@property (nonatomic, copy, nullable, readonly) MBDataStreamCompletion completion;

@property (nonatomic, assign) UInt16 command;
@property (nonatomic, assign) UInt8  binType;

@property (nonatomic, strong, readonly) MBCommonData *commonData;

- (instancetype)initWithPath:(NSString *)path;

- (void)startWithProgress:(nullable MBDataStreamProgress)progress
               completion:(MBDataStreamCompletion)completion;

- (void)stop;

- (BOOL)hasMoreTask;

@end

NS_ASSUME_NONNULL_END
