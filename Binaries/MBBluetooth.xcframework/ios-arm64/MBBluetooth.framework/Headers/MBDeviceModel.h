//
//  MBDeviceType.h
//  MBBluetooth
//
//  Created by baiwhte on 2023/10/26.
//

#ifndef MBDeviceModel_h
#define MBDeviceModel_h

NS_ASSUME_NONNULL_BEGIN

typedef NSString *MBDeviceModel NS_TYPED_ENUM;

UIKIT_EXTERN MBDeviceModel const MBDeviceModelGlasses;

/// 巴赫眼镜
UIKIT_EXTERN MBDeviceModel const MBDeviceModelBach;
/// 毕加索眼镜
UIKIT_EXTERN MBDeviceModel const MBDeviceModelPicasso;
/// 指环
UIKIT_EXTERN MBDeviceModel const MBDeviceModelRing;

static inline MBDeviceModel MBDeviceModelWithValue(NSString *) NS_SWIFT_NAME(MBDeviceModel(value:));
MBDeviceModel MBDeviceModelWithValue(NSString * value)
{
    if (value == nil || ![value isKindOfClass:NSString.class]) {
        return MBDeviceModelBach;
    }
    
    if ([value hasPrefix:@"0215"]) {
        value = [value substringFromIndex:4];
    }
    
    if (value.length != 4) {
        return MBDeviceModelBach;
    }
    
#if DEBUG
    NSArray *models = @[MBDeviceModelBach, MBDeviceModelPicasso, MBDeviceModelRing];
    if (![models containsObject:value]) {
        @throw  [NSException exceptionWithName:@"" reason:@"暂不支持的设备类型" userInfo:nil];
    }
#endif
    
    return (MBDeviceModel)value;
}

NS_ASSUME_NONNULL_END

#endif /* MBDeviceModel_h */
