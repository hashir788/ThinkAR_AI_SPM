//
//  MBCommonData.h
//  MBBluetooth
//
//  Created by baiwhte on 2023/9/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MBFileDirection) {
    //App sends to peripherals, such as OTA
    MBFileDirectionSend = 0,
    //The App requests files from peripherals, such as Log, Screenshot
    MBFileDirectionRequest,
};

typedef NS_ENUM(UInt8, MBPacketType) {
    MBPacketTypeBegin = 0,
    MBPacketTypeMiddle,
    MBPacketTypeEnd,
};

@protocol MBFrameProtocol;
@interface MBCommonData : NSObject

/// 每次发送的最大包数
@property (nonatomic, assign) NSInteger maxPackets;

/// The property’s value is NO if initialized with '-initWithData:reserveds:'
/// YES if initialized with '-initWithPath:type:'
@property (nonatomic, assign, readonly) BOOL isFileReferenceData;

// Length of data to be sent or received
@property (nonatomic, assign, readonly) NSInteger length;
@property (nonatomic, assign) NSInteger offset;

@property (nonatomic, assign, readonly) MBFileDirection direction;

@property (nonatomic, assign, readonly) UInt16 command;
@property (nonatomic, assign, readonly) UInt8 type;

/// 当前处理的包序号
@property (nonatomic, assign, readonly) NSInteger index;

/// total packets
@property (nonatomic, assign, readonly) NSInteger count;

@property (nonatomic, assign) NSInteger mtu;

@property (nonatomic, copy, nullable) void(^progress)(UInt64 bytesLength);
@property (nonatomic, copy, nullable) void(^completion)(BOOL success, NSError * _Nullable error);

/// 构造函数
/// - Parameters:
///   - data: 待发送的数据
///   - reserveds: `CommonData`的头
///   - Note: `Common_Data`定义
///    `Common_Data`数据包定义meta_comm_data_head，共25个字节
///   __packed_struct meta_comm_data_head {
///       uint8_t bin_type;  //  bin文件类型，在 meta_bin_type 中定义
///       uint32_t len;
///       uint32_t crc;
///       uint32_t resvd1;
///       uint32_t resvd2;
///       uint32_t resvd3;
///      uint32_t resvd4;
///   };
- (instancetype)initWithData:(NSData *)data
                   reserveds:(NSArray<NSNumber *> *)reserveds;

/// 构造函数 -- 请求文件
/// - Parameters:
///   - path: 接收文件时保存路径
///   - command: 请求文件的命令
///   - type: bin文件类型，在 meta_bin_type 中定义
- (instancetype)initWithPath:(NSString *)path command:(UInt16)command type:(UInt8)type;

#pragma mark -- 发送CommonData数据
- (nullable NSData *)sendDataAtIndex:(NSInteger)index;

- (nullable NSArray <NSData *> *)sendDataFromIndex:(NSInteger)from length:(NSInteger)length;

- (nullable NSArray <NSData *> *)sendDataFromIndex:(NSInteger)from toIndex:(NSInteger)to;

- (nullable NSArray <NSData *> *)sendDataToIndex:(NSInteger)to;

#pragma mark -- 请求文件命令

- (id<MBFrameProtocol>)request;

- (id<MBFrameProtocol>)responseWithIndex:(UInt32)index command:(UInt16)command type:(UInt8)type;

- (void)writeData:(NSData *)data;

- (void)writeCompleted; 

@end

NS_ASSUME_NONNULL_END
