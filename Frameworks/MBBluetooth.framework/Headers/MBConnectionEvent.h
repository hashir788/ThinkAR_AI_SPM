//
//  MBConnectionEvent.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/7/3.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "MBTimeout.h"
#import "MBConnectionOptions.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MBBrEdrConnectionEvent) {
    MBBrEdrConnectionEventUnspport = 0,
    MBBrEdrConnectionEventFromSystem,
    MBBrEdrConnectionEventStart,
    MBBrEdrConnectionEventFinished,
};

@interface MBConnectionEvent : NSObject

@property (nonatomic, copy ) NSString *identifier;

@property (nonatomic, strong, nullable) MBTimeout *timeout;

@property (nonatomic, strong, nullable) MBConnectionOptions *options;

/// BrEdr是否连接成功
@property (nonatomic, assign) MBBrEdrConnectionEvent bredrState;

///// 外设是否支持`BR/EDR`, 如果`supportClass`为YES，但是`classServiceUUIDs`为空数组，SDK忽略`BR/EDR`的连接
//@property (nonatomic, assign) BOOL supportClassic;

@property (nonatomic, copy  , nullable) NSDictionary<CBUUID *, NSArray<CBUUID *> *> *classicServicesCharacteristicsUUIDs;

@property (nonatomic, copy  , nullable) NSDictionary<CBUUID *, NSArray<CBUUID *> *> *servicesCharacteristicsUUIDs;

@property (nonatomic, copy  , readonly) NSArray<CBUUID *> *solicitedServices;

/// 外设是否支持连接L2CAP Channel,
@property (nonatomic, assign) BOOL enableL2CAP;

@property (nonatomic, copy  , nullable) void(^completion)(BOOL success, NSError *_Nullable error);

@end

@interface MBConnectionEvent (Deprecated)
//
///// 要连接`BR/EDR`的ServiceId
//@property (nonatomic, copy  , nullable) NSArray<CBUUID *> *classicServiceUUIDs __attribute__((deprecated("Use classicServicesCharacteristicsUUIDs")));
///// 要连接`BR/EDR`的CharacteristicsId
//@property (nonatomic, copy  , nullable) NSArray<CBUUID *> *classicCharacterServiceUUIDs __attribute__((deprecated("Use classicServicesCharacteristicsUUIDs")));
//
///// 要连接`BLE`的ServiceId
//@property (nonatomic, copy  , nullable) NSArray<CBUUID *> *serviceUUIDs __attribute__((deprecated("Use servicesCharacteristicsUUIDs")));
///// 要连接`BLE`的CharacteristicsId
//@property (nonatomic, copy  , nullable) NSArray<CBUUID *> *characteristicsUUIDs __attribute__((deprecated("Use servicesCharacteristicsUUIDs")));

@end

NS_ASSUME_NONNULL_END
