//
//  MBFrameProtocol.h
//  MBTimeWheel
//
//  Created by baiwhte on 2023/6/22.
//

#import <Foundation/Foundation.h>
@import CoreBluetooth;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MBFrameDirection) {
    MBFrameDirectionSend = 0,
    MBFrameDirectionReceive,
};

FOUNDATION_EXTERN NSString *const MBFrameProtocolErrorDomain;

/// Communication protocol frame definition
@protocol MBFrameProtocol <NSObject>

@required
@property (nonatomic, assign) UInt32 head;

@property (nonatomic, assign) UInt16 index;

@property (nonatomic, assign) UInt16 command;

@property (nonatomic, strong) NSData *payload;

/// Indicates whether the frame data is received or sent
@property (nonatomic, assign) MBFrameDirection direction;

- (instancetype)initWithIndex:(UInt16)index
                      command:(UInt16)command
                    direction:(MBFrameDirection)direction
                         data:(nullable NSData *)data;

@optional

@property (nonatomic, assign) UInt32 tail;

@property (nonatomic, assign) NSInteger priority;

/// /// for `Common_Data` header
@property (nonatomic, copy) NSArray<NSNumber *> *reserveds;

#pragma mark -- Send data channel

/// The CBService’s uuid
@property (nonatomic, copy  ) NSString *serviceId;

/// The characteristic containing the value to write.
@property (nonatomic, copy  ) NSString *characteristicId;

/// Specifies which type of write is to be performed on a CBCharacteristic.
/// Default's CBCharacteristicWriteWithoutResponse
@property (nonatomic, assign) CBCharacteristicWriteType type;

#pragma mark -- Retry strategy

/// The default timeout period is 10 seconds
@property (nonatomic, assign) NSInteger timeout;

/// The default retry times is 3
@property (nonatomic, assign) NSInteger retryLimit;

#pragma mark -------
- (instancetype)initWithIndex:(UInt16)index
                      command:(UInt16)command
                         head:(UInt32)head
                         data:(NSData *)data;

/// construct a complete protocol frame
/// - Note: This method and 'constructSubFrames:' must implement at least one
- (NSData *)constructAFrame;

/// construct a complete protocol frame
/// - Parameter maxSize: MTU
///
/// - Note: This method and 'constructAFrame' must implement at least one
- (NSArray<NSData *> *)constructSubFrames:(NSInteger)maxSize;

@end

NS_ASSUME_NONNULL_END
