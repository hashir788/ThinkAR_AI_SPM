//
//  MBAdvertisementData.h
//  MBTimeWheel
//
//  Created by chenxiuwu on 2023/6/19.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface MBAdvertisementData : NSObject
/// A Boolean value that indicates whether the advertising event type is connectable.
@property (nonatomic, assign, readonly) BOOL isConnectable;
@property (nonatomic, assign, readonly) double txPowerLevel;
@property (nonatomic, copy  , readonly, nullable) NSString *localName;
@property (nonatomic, copy  , readonly) NSArray<CBUUID *> *serviceUUIDs;
@property (nonatomic, strong, readonly) NSData *serviceData;
@property (nonatomic, strong, readonly, nullable) NSData *manufacturerData;
@property (nonatomic, copy  , readonly) NSArray<CBUUID *> *solicitedServiceUUIDs;
@property (nonatomic, copy  , readonly) NSArray<CBUUID *> *overflowServiceUUIDs;

- (instancetype)initWithDictionary:(NSDictionary<NSString *,id> *)advertisementData;
@end

NS_ASSUME_NONNULL_END
