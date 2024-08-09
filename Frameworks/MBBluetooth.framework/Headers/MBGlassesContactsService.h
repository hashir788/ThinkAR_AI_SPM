//
//  MBGlassesContactsService.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/8/1.
//

#import "MBDeviceFrameService.h"

NS_ASSUME_NONNULL_BEGIN

@interface MBGlassesContactsService : MBDeviceFrameService

/// 【MB-request-通讯录设备端联系人个数】
+ (void)requestContactsCount:(nullable void(^)(NSInteger))completion;

/// 【MB-request-通讯录上传联系人】
+ (void)syncContacts:(NSArray *)contacts completion:(nullable void(^)(BOOL))completion;

+ (id<MBFrameProtocol>)frameContactsAtIndex:(NSInteger)index;

/// 【MB-request-通讯录获取所有联系人】//待联调
+ (void)requestContactsAtIndex:(NSInteger)index completion:(nullable void(^)(NSArray<NSDictionary<NSString *, id> *> *))completion;

+ (NSArray<NSDictionary<NSString*, NSString *> *> *)parseContacts:(nullable NSData *)data;

+ (void)syncContactName:(NSString *)name telephone:(NSString *)telephone completion:(nullable void(^)(BOOL))completion;

+ (void)syncAccessStatus:(BOOL)isOpen completion:(nullable void(^)(BOOL))completion;

@end

NS_ASSUME_NONNULL_END
