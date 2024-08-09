//
//  MBStreamService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/9/19.
//

#import <Foundation/Foundation.h>
#import "MBFrameProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// 数据流协议
@protocol MBDataStream <NSObject>

- (void)stop;

- (void)didReceivedFrameData:(id<MBFrameProtocol>)frame;

@end

NS_ASSUME_NONNULL_END
