//
//  MBDataChannelProtocol.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/8/28.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MBDataChannelProtocol <NSObject>

@property (nonatomic, copy) NSArray<CBUUID *> *characteristics;

/// 接收到数据
/// - Parameter characteristic: 接收到数据的特征
- (void)didReceivedForCharacteristic:(CBCharacteristic *)characteristic;

@end

NS_ASSUME_NONNULL_END
