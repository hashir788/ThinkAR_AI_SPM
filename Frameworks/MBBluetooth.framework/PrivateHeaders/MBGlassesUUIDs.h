//
//  MBGlassesUUIDs.h
//  MBBluetooth
//
//  Created by chenxiuwu on 2023/8/28.
//

#ifndef MBGlassesUUIDs_h
#define MBGlassesUUIDs_h

//MARK: 巴赫眼镜的服务ids和characteristicIds
static NSString *const MBGlassesServiceId = @"00010000-0000-1000-8000-00805F9B5A6B";
static NSString *const MBGlassesWriteCharacteristicId  = @"00010001-0000-1000-8000-00805F9B5A6B";
static NSString *const MBGlassesNotifyCharacteristicId = @"00010002-0000-1000-8000-00805F9B5A6B";
static NSString *const MBGlassesTokenCharacteristicId  = @"00010003-0000-1000-8000-00805F9B5A6B";

static NSString *const MBGlassesStreamServiceId = @"00030000-0000-1000-8000-00805F9B5A6B";
static NSString *const MBGlassesStreamWriteCharacteristicId  = @"00030001-0000-1000-8000-00805F9B5A6B";
static NSString *const MBGlassesStreamNotifyCharacteristicId = @"00030002-0000-1000-8000-00805F9B5A6B";

static NSString *const MBGlassesFileWriteCharacteristicId = @"00010001-0000-1000-8000-00805F9B5A6B";
static NSString *const MBGlassesFileNotifyCharacteristicId = @"00010002-0000-1000-8000-00805F9B5A6B";

static NSString *const MBGlassesBREEDRServiceId = @"5052494D-2DAB-0341-6972-6F6861424C45";
static NSString *const MBGlassesBREEDRNotifyCharacteristicId = @"43484152-2DAB-3141-6972-6F6861424C45";
static NSString *const MBGlassesBREEDRWriteCharacteristicId  = @"43484152-2DAB-3241-6972-6F6861424C45";


#endif /* MBGlassesUUIDs_h */
