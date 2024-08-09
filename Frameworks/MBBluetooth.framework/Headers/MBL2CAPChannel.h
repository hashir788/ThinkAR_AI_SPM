//
//  MBL2CAPChannel.h
//  MBTimeWheel
//
//  Created by chenxiuwu on 2023/6/19.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface MBL2CAPChannel : NSObject<NSStreamDelegate>

- (instancetype)initWithChannel:(CBL2CAPChannel *)channel;

@end

NS_ASSUME_NONNULL_END
