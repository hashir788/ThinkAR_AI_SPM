//
//  MBGlassesFrame.h
//  MBTimeWheel
//
//  Created by baiwhte on 2023/6/22.
//

#import <Foundation/Foundation.h>
#import "MBFrameProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// 眼镜端协议帧
@interface MBGlassesFrame : NSObject<MBFrameProtocol>

- (instancetype)initWithCommand:(UInt16)command data:(nullable NSData *)data;

- (instancetype)initWithCommand:(UInt16)command direction:(MBFrameDirection)direction data:(nullable NSData *)data;

+ (nullable id)parsePayload:(NSData *)data
                    command:(UInt16)command
                      error:(NSError * __autoreleasing *)error;

+ (NSDictionary *)errorInfos;
@end

NS_ASSUME_NONNULL_END
