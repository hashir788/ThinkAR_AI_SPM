//
//  MBBluetoothTask.h
//  MBTimeWheel
//
//  Created by baiwhte on 2023/6/22.
//

#import <Foundation/Foundation.h>
#import "MBBluetoothDevice.h"
#import "MBTimeout.h"

NS_ASSUME_NONNULL_BEGIN

@interface MBBluetoothTask: NSObject<NSCopying>

@property (nonatomic, copy ) NSString *identifier;

//@property (nonatomic, strong) id<MBFrameProtocol> frame;
@property(nonatomic, assign) UInt16 command;

@property (nonatomic, strong, nullable) MBTimeout *timeout;

@property(nonatomic, assign) MBTaskState state;

/// 待发送的数据
@property (nonatomic, strong) NSArray<NSData *> *datas;

/// CommonData的发送序号或普通命令出现分包时接收的回调次数
@property (nonatomic, assign) NSInteger index;

@property (nonatomic, strong) CBPeripheral *peripheral;

@property (nonatomic, assign) CBCharacteristicWriteType type;

@property (nonatomic, strong) CBCharacteristic *characteristic;

@property (nonatomic, copy , nullable) MBTaskCompletion completion;

@end

NS_ASSUME_NONNULL_END
