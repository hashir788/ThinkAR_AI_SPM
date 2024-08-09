//
//  MBGlassesResponse.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/8/5.
//

#import <Foundation/Foundation.h>
#import "MBFrameProtocol.h"
NS_ASSUME_NONNULL_BEGIN

@interface MBGlassesResponse : NSObject<NSCopying>

@property (nonatomic, assign, readonly) UInt16 command;

@property (nonatomic, assign, readonly, getter=isSuccess) BOOL success;

@property (nonatomic, copy, readonly, nullable) NSData *data;

@property (nonatomic, strong, readonly, nullable) NSError *error;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithFrame:(nullable id<MBFrameProtocol>)frame error:(nullable NSError *)error;


@end

NS_ASSUME_NONNULL_END
