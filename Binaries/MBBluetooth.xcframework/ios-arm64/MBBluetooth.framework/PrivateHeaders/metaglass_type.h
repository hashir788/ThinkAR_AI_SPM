/******************************************************
 *
 * Copyright (C) 2021-2021 MetaBounds Corporation
 *
 * @Author: yuxuewen@meta-bounds.com
 * @Create Time: Wed 22 Dec 2021 04:03:19 PM CST
 * @File Name: metaglass_type.h
 * @Description:
 *
 ******************************************************/

#ifndef __META_GLASS_TYPE_H__
#define __META_GLASS_TYPE_H__

#include <stdint.h>

#include "platform.h"

#define META_CMD_MAGIC_REQ    0x4D45
#define META_CMD_MAGIC_RSP    0x424f
#define META_STREAM_MAGIC     0x4d53

enum meta_cmd_status{
    /** */
    STATUS_SUCCESS        = 0x00,
    /** 接收到包不完整,还有剩余没有收到, 返回已经收到的长度 */
    STATUS_LEFT           = 0x01,
    /** 不支持的命令 */
    ERR_MSG_UNSUPPORT     = 0x11,
    /** 接收到的包是错误的 */
    ERR_MSG               = 0x12,
    /** 已经被绑定用户 */
    ERR_BIND_USER_BINDED  = 0x13,
    /** 用户拒绝绑定 */
    ERR_BIND_USER_REFUSE  = 0x14,
    /** 解绑: 错误的用户 */
    ERR_UNBIND_ERROR_USER = 0x15,
    /** CRC校验错误 */
    ERR_CRC               = 0x16,
    /** 写flash错误 */
    ERR_WRITE_FLASH       = 0x17,
    /** size 错误 */
    ERR_SIZE              = 0x18,
    /** 流通道错误 */
    ERR_STREAM_CHANNEL    = 0x19,
    /** bt回连失败 */
    ERR_BTCONNECT_FAILED  = 0x1a,
    /** 应用未激活 */
    ERR_FEATURE_UNACTIVE  = 0x1b,
    /** 命令超时 */
    ERR_TIME_OUT          = 0x1c,
};

enum meta_cmd_type{
    /** 绑定 */
    CMD_BIND              = 0x00,
    /** 解绑 */
    CMD_UNBIND            = 0x01,
    /** 查询fw版本号 */
    CMD_GET_VERSION       = 0x02,
    /** 提词器文本 */
    CMD_AUTOCUE_TEXT      = 0x03,
    /** 提词器设置页 */
    CMD_AUTOCUE_PAGE      = 0x04,
    /** 短消息通知使能 */
    CMD_SMS_ENABLE        = 0x05,
    /** 来电提醒使能 */
    CMD_CALL_ENABLE       = 0x06,
    /** 消息通知 */
    CMD_MSG_NOTI          = 0x07,
    /** 消息答复 */
    CMD_MSG_REPLY         = 0x08,
    /** 获取配置 */
    CMD_GET_CONFIG        = 0x09,
    /** 设置配置 */
    CMD_SET_CONFIG        = 0x0a,
    /** 媒体信息 */
    CMD_AUDIO_INFO        = 0x0b,
    /** 媒体控制 */
    CMD_AUDIO_CTL         = 0x0c,
    /** 媒体订阅 */
    CMD_AUDIO_SUBSCRIBE   = 0x0d,
    /** 来电信息 */
    CMD_CALL_INFO         = 0x0e,
    /** 来电控制 */
    CMD_CALL_CTL          = 0x0f,
    /** 电池信息获取 */
    CMD_GET_BATT_INFO     = 0x10,
    /** 设置系统时间 */
    CMD_SET_SYS_TIME      = 0x11,
    /** IMU数据订阅 */
    CMD_IMU_SUBSCRIBE     = 0x12,
    /** IMU查询配置 */
    CMD_IMU_GET_CONFIG    = 0x13,
    /** IMU查询配置 */
    CMD_IMU_SET_CONFIG    = 0x14,
    /** IMU数据信息 */
    CMD_IMU_INFO          = 0x15,
    /** GPS数据订阅 */
    CMD_GPS_SUBSCRIBE     = 0x16,
    /** GPS数据包 */
    CMD_GPS_PACKET        = 0x17,
    /** 设置蓝牙名称 */
    CMD_SET_BT_NAME       = 0x18,
    /** 获取蓝牙地址 */
    CMD_GET_BT_ADDRESS    = 0x19,
    /** 数据包 */
    CMD_BINARY_PACKET     = 0x1a,
    /** 重启命令 */
    CMD_REBOOT            = 0x1b,
    /** 查询启动模式 */
    CMD_GET_BOOT_MODE     = 0x1c,
    /** 获取屏幕坐标 */
    CMD_GET_SCREEN_COORD  = 0x1d,
    /** 设置屏幕坐标 */
    CMD_SET_SCREEN_COORD  = 0x1e,
    /** 设置屏幕亮度模式 */
    CMD_SET_BRIGHTNESS_MODE  = 0x1f,
    /** 查询屏幕亮度模式 */
    CMD_GET_BRIGHTNESS_MODE  = 0x20,
    /** 设置屏幕亮度值 */
    CMD_SET_BRIGHTNESS_VALUE = 0x21,
    /** 查询屏幕亮度值 */
    CMD_GET_BRIGHTNESS_VALUE = 0x22,
    /** 勿扰模式使能 */
    CMD_DND_ENABLE        = 0x23,
    /** 状态同步 */
    CMD_STATE_SYNC        = 0x24,
    /** 查询屏幕坐标调节方式 */
    CMD_GET_SCREEN_COORD_ADJUST_MODE = 0x25,
    /** 设置屏幕坐标调节方式 */
    CMD_SET_SCREEN_COORD_ADJUST_MODE = 0x26,
    /** 获取蓝牙名称 */
    CMD_GET_BT_NAME       = 0x27,
    /** 按键事件 */
    CMD_KEY_EVENT         = 0x28,
    /** 查询版本号列表 */
    CMD_GET_VERSION_LIST  = 0x29,
    /** 查询设备类型 */
    CMD_GET_DEV_TYPE      = 0x2a,
    /** 更新用户保护数据 */
    CMD_SET_UPD           = 0x2b,
    /** 天气使能 */
    CMD_WEATHER_ENABLE    = 0x2c,
    /** 天气更新 */
    CMD_WEATHER_UPDATE    = 0x2d,
    /** 握手命令 */
    CMD_HAND_SHAKE        = 0x2e,
    /** 录音控制 */
    CMD_MIC_CTRL          = 0x2f,
    /** 语音实时翻译开始 */
    CMD_VOICE_RTT_ENTER   = 0x30,
    /** 语音实时翻译结束 */
    CMD_VOICE_RTT_EXIT    = 0x31,
    /** 指定讲话语言 */
    CMD_VOICE_RTT_LANG    = 0x32,
    /** 文本 */
    CMD_VOICE_RTT_TEXT    = 0x33,
    /** 翻译讲话使能 */
    CMD_VOICE_RTT_SPEAK   = 0x34,
    /** 屏幕对齐开始 */
    CMD_SCREEN_CALIB_ENTER= 0x35,
    /** 屏幕对齐结束 */
    CMD_SCREEN_CALIB_EXIT = 0x36,
    /** 屏幕点亮方式获取 */
    CMD_SCREEN_LIGHT_MODE_GET = 0x37,
    /** 屏幕点亮方式设置 */
    CMD_SCREEN_LIGHT_MODE_SET = 0x38,
    /** 使能bt回连 */
    CMD_BTCONNECT_BACK_ENABLE = 0x39,
    /** bt连接状态report */
    CMD_REPORT_BT_STATUS      = 0x3a,
    /** 查询自动息屏时间 */
    CMD_GET_SCREEN_OFF_TIME   = 0x3b,
    /** 设置自动息屏时间 */
    CMD_SET_SCREEN_OFF_TIME   = 0x3c,
    /** 查询低电量处理方式*/
    CMD_GET_LOWPOWER_OPT      = 0x3d,
    /** 设置低电量处理方式*/
    CMD_SET_LOWPOWER_OPT      = 0x3e,
    /** 开始导航 */
    CMD_NAVIGATION_START     = 0x3f,
    /** 结束导航 */
    CMD_NAVIGATION_END       = 0x40,
    /** 用户确认关机 */
    CMD_USER_POWER_DOWN       = 0x41,
    /** 汇顶透传 */
    CMD_GOODIX_TRANSLATE      = 0x42,
    /** 获取支持字体尺寸列表 */
    CMD_GET_FONT_SIZE_LIST    = 0x43,
    /** 获取提词器当前字体序号 */
    CMD_AUTOCUE_GET_FONT      = 0x44,
    /** 设置提词器当前字体序号 */
    CMD_AUTOCUE_SET_FONT      = 0x45,
    /** 获取提词器显示区域尺寸 */
    CMD_AUTOCUE_GET_AREA      = 0x46,
    /** 提词器开始演讲 */
    CMD_AUTOCUE_START_SPEECH  = 0x47,
    /** 提词器结束演讲 */
    CMD_AUTOCUE_STOP_SPEECH   = 0x48,
    /** 工厂指令 */
    CMD_AT_TRANSLATE          = 0x49,
    /** 查询sn */
    CMD_GET_SN                = 0x4a,
    /** 设置语音传输通道 */
    CMD_SET_VOICE_CHANNEL     = 0x4b,
    /** RTT/UART切换开关 */
    CMD_RTT_UART_SWITCH       = 0x4c,
    /** 读取二进制数据 */
    CMD_READ_COMM_DATA        = 0x4d,
    /** 播放提示音 */
    CMD_PLAY_TONE             = 0x4e,
    /** 停止播放提示音 */
    CMD_STOP_TONE             = 0x4f,
    /** 查询支持的语言列表 */
    CMD_GET_LANGUAGE_LIST     = 0x50,
    /** 查询当前的语言 */
    CMD_GET_LANGUAGE_CURRENT  = 0x51,
    /** 设置当前的语言 */
    CMD_SET_LANGUAGE_CURRENT  = 0x52,
    /** 提示音使能 */
    CMD_TONE_ENABLE           = 0x53,
    /** 音量调节 */
    CMD_VOLUME_ADJUST         = 0x54,
    /** 佩戴检测订阅 */
    CMD_CAPTOUCH_SUBSCRIBE    = 0x55,
    /** 佩戴检测上报 */
    CMD_CAPTOUCH_REPORT       = 0x56,
    /** 联系人设置 */
    CMD_CONTACTS_SET          = 0x57,
    /** 联系人获取 */
    CMD_CONTACTS_GET          = 0x58,
    /** 拨打电话 */
    CMD_CALL_DIAL_INFO        = 0x59,
    /** 获取联系人数量 */
    CMD_CONTACTS_COUNT_GET    = 0x5a,
    /** 拨号提醒 */
    CMD_DIAL_REMIND                    = 0x5b,
    /** 获取提词器时间 */
    CMD_AUTOCUE_GET_TIME               = 0x5c,
    /** 获取IMU工作参数 */
    CMD_GET_IMU_PARM                   = 0x5d,
    /** 设置IMU工作参数 */
    CMD_SET_IMU_PARM                   = 0x5e,
    /** 获取IMU算法数据 */
    CMD_GET_IMU_ALGO_DATA              = 0x5f,
    /** 设置导航时屏幕常亮开关 */
    CMD_SET_NAVIGATION_KEEP_BRIGHT     = 0x60,
    /** 获取导航时屏幕常亮开关 */
    CMD_GET_NAVIGATION_KEEP_BRIGHT     = 0x61,
    /** 添加新日程 */
    CMD_SCHEDULE_ADD                   = 0x62,
    /** 日程获取全部信息 */
    CMD_SCHEDULE_GET                   = 0x63,
    /** 删除一个日程 */
    CMD_SCHEDULE_REMOVE_ONE            = 0x64,
    /** 修改一个日程 */
    CMD_SCHEDULE_UPDATE_ONE            = 0x65,
    /** 获取日程全部键值 */
    CMD_SCHEDULE_GET_KEYS              = 0x66,
    /** 获取手机系统型号 */
    CMD_SET_PHONE_TYPE                 = 0x67,
    /** 同步配对状态 */
    CMD_PAIR_STATE_SYNC                = 0x68,
    /** 订阅光线传感器 */
    CMD_ALS_SUBSCRIBE                  = 0x69,
    /** 上报光线传感器数据 */
    CMD_ALS_INFO                         = 0x6a,
    /** 设置光线传感器上报频率 */
    CMD_ALS_FREQUENCY                   = 0x6b,
    /**APP开始GPT问答 */
    CMD_START_GPT                      = 0x6c,
    /**Glass开始GPT录音 */
    CMD_START_GPT_RECORDING            = 0x6d,
    /**Glass结束GPT录音 */
    CMD_END_GPT_RECORDING              = 0x6e,
    /**APP设置GPT问题文字 */
    CMD_SET_GPT_QUESTION_TEXT          = 0x6f,
    /**APP设置GPT答案文字 */
    CMD_SET_GPT_ANSWER_TEXT            = 0x70,
    /**APP结束GPT问答 */
    CMD_END_GPT                        = 0x71,
    /**恢复出厂设置 */
    CMD_FACTORY_RESET                  = 0x72,
    /**断开BT蓝牙 */
    CMD_DISCONN_BT                     = 0x73,
    /**进入导航 */
    CMD_NAVIGATION_ENTER               = 0x74,
    /**导航更新速度 */
    CMD_NAVIGATION_UPDATE_SPEED        = 0x75,
    /**导航更新前进方向  */
    CMD_NAVIGATION_UPDATE_DIR          = 0x76,
    /**导航更新路线经纬度与当前位置信息 */
    CMD_NAVIGATION_UPDATE_LON_LAT_INFO = 0x77,
    /**恢复出厂设置下发重启 */
    CMD_FACTORY_REBOOT                 = 0x78,
    /**算法在眼镜端进入绘制*/
    CMD_ALGO_DRAW_ENTER                = 0x79,
    /**算法在眼镜端退出绘制*/
    CMD_ALGO_DRAW_EXIT                 = 0x7A,
    /**OTA开始升级*/
    CMD_OTA_UPDATE_START               = 0x7B,
    /**OTA升级失败*/
    CMD_OTA_UPDATE_FAILED              = 0x7C,
    /**设置眼镜为OTA启动模式*/
    CMD_OTA_SET_OTA_MODE               = 0x7D,
    /**APP取消OTA升级*/
    CMD_OTA_CANCELED                   = 0x7E,
    /**IOS退出登录*/
    CMD_IOS_LOGOUT                     = 0x7F,
    
    /**接收戒指手势和传感数据*/
    CMD_RING_GESTURE_AND_DATA          = 0x80,
    /**APP通知网络断开*/
    CMD_NET_DISCONNECT                 = 0x81,
    /**（语音助手）APP打开(关闭长按2S唤醒开关)*/
    CMD_SET_VOICE_ASSISTANT_WAKE_SWITCH    = 0x82,
    /**（语音助手）APP获取(关闭长按2S唤醒开关)的状态*/
    CMD_GET_VOICE_ASSISTANT_WAKE_SWITCH    = 0x83,
    /**（语音助手）设置状态（双向指令）*/
    CMD_VOICE_ASSISTANT_SET_STATUS         = 0x84,
    /**（语音助手）是否在语音应用内的状态（固件发送）*/
    CMD_VOICE_ASSISTANT_IN_APP             = 0x85,
    /**传输IMU标定参数*/
    CMD_IMU_CALI_PARA_SET                  = 0x86,
    /**读取IMU标定参数*/
    CMD_IMU_CALI_PARA_GET                  = 0x87,
    /**指环数据订阅*/
    CMD_RING_DATA_SUBSCRIBE                = 0x88,
    /**指环数据当前订阅查询*/
    CMD_RING_DATA_CUR_SUBSCRIBE_GET        = 0x89,
    /**指环数据订阅能力查询*/
    CMD_RING_DATA_SUBSCRIBE_ABILITY_GET    = 0x8A,

    /** 作用不清楚，等AT优化后修改*/
    CMD_POWER_CONSUMPTION_CONTROL          = 0xCF,
    
    
    /** 提供给测试调用 */
    CMD_TEST_FUNC_CMD                      = 0xd0,
    
    /**SIM状态指示*/
    CMD_SIM_STATUS                         = 0xD1,

    /**获取当前工作模式*/
    CMD_CURRENT_MODE_GET                   = 0xD2,

    /**设置当前工作模式*/
    CMD_CURRENT_MODE_SET                   = 0xD3,

    /**获取老化测试状态*/
    CMD_AGING_TEST_STATE_GET               = 0xD4,

    /**设置老化测试状态*/
    CMD_AGING_TEST_STATE_SET               = 0xD5,

    /**获取MMI测试状态*/
    CMD_MMI_TEST_STATE_GET                 = 0xD6,

    /**设置MMI测试状态*/
    CMD_MMI_TEST_STATE_SET                 = 0xD7,

    /**获取老化测试错误码*/
    CMD_AGING_TEST_ERROR_CODE_GET          = 0xD8,

    /**设置老化测试错误码*/
    CMD_AGING_TEST_ERROR_CODE_SET          = 0xD9,

    /**获取MMI测试错误码*/
    CMD_MMI_TEST_ERROR_CODE_GET            = 0xDA,

    /**设置MMI测试错误码*/
    CMD_MMI_TEST_ERROR_CODE_SET            = 0xDB,

    /**获取老化测试重启错误码*/
    CMD_AGING_REBOOT_ERROR_CODE_GET        = 0xDC,

    /**获取老化测试重启次数*/
    CMD_AGING_REBOOT_COUNT_GET             = 0xDD,




};

/**
 * 1bit filed, can only be 0x00 or 0x01
 */
enum meta_cmd_packet_type{
    /** 起始包, 当value总长度(total_len)大于当前包value长度(value_len)时，应该有子包 */
    PACKET_BEGIN          = 0x00,
    /** 后续子包 */
    PACKET_LEFT           = 0x01,
};

enum meta_autocue_page_type{
    /** 上一页 */
    AUTOCUE_PAGE_UP       = 0x00,
    /** 下一页 */
    AUTOCUE_PAGE_DN       = 0x01,
};

enum meta_layload_type{
    /** 消息通知负载title */
    PL_MSG_TITLE          = 0x00,
    /** 消息通知负载text */
    PL_MSG_TEXT           = 0x01,
    /** Audio title */
    PL_AUDIO_TITLE        = 0x02,
    /** Audio text */
    PL_AUDIO_TEXT         = 0x03,
    /** Audio duration */
    PL_AUDIO_DURATION     = 0x04,
    /** Audio position */
    PL_AUDIO_POSITION     = 0x05,
    /** Audio artist */
    PL_AUDIO_ARTIST       = 0x06,
    /** Audio app */
    PL_AUDIO_APP          = 0x07,

    /** 导航信息 */
    PL_NAVIGATION_GUIDE_INFO = 0x10,
    /** 导航剩余时间 */
    PL_NAVIGATION_TIME_INFO  = 0x11,
    /** 导航剩余距离 */
    PL_NAVIGATION_DST_INFO   = 0x12,
    /** 导航类型 */
    PL_NAVIGATION_FLAG       = 0x13,
    /** 导航高亮 */
    PL_NAVIGATION_WORD_LIGHT = 0x14,
    /** 导航图标 */
    PL_NAVIGATION_ICON       = 0x15,
    /** 导航前进方向 */
    PL_NAVIGATION_HEADING    = 0x16,
    /** 导航最大经纬度 */
    PL_NAVIGATION_MAX_LON_LAT = 0x17,
    /** 导航最小经纬度 */
    PL_NAVIGATION_MIN_LON_LAT = 0x18,
    /** 导航当前位置经纬度*/
    PL_NAVIGATION_LOCATION_LON_LAT         = 0x19,
    /** 导航路线地点经纬度总数*/
    PL_NAVIGATION_LON_LAT_TOTAL_NUM        = 0x1A,
    /**导航路线总路段 */
    PL_NAVIGATION_TOTAL_ROUTE_SEG          = 0x1B,
    /**导航每条路段经纬度点数*/
    PL_NAVIGATION_PER_SEG_LON_LAT_NUM      = 0x1C,
    /**导航路线经纬度集合 */
    PL_NAVIGATION_ROUTE_LON_LAT_PACK       = 0x1D,
    /**导航全路线经纬度集合 */
    PL_NAVIGATION_GOBAL_ROUTE_LON_LAT_PACK = 0x1E,
    /** 天气类型 */
    PL_WEATHER_TYPE          = 0x20,
    /** 天气区域 */
    PL_WEATHER_LOCATION      = 0x21,


    /** 来电号码 */
    PL_CALL_NUMBER           = 0x30,
    /** 来电名称 */
    PL_CALL_NAME             = 0x31,
    /** 联系人名 */
    PL_CONTACTS_NAME         = 0x40,
    /** 联系人电话 */
    PL_CONTACTS_NUMER        = 0x41,
    /** 日程名称 */
    PL_SCHEDULE_NAME         = 0x50,
    /** 日程开始时间 */
    PL_SCHEDULE_START_TIME   = 0x51,
    /** 日程结束时间 */
    PL_SCHEDULE_END_TIME     = 0x52,
    /** 日程提醒时间*/
    PL_SCHEDULE_REMIND_TIME  = 0x53,
    /** 日程全部键值 */
    PL_SCHEDULE_KEYS         = 0x54,
    
    PL_ALGO_DRAW_CANVAS      = 0x60,
    
    PL_VOICE_ASSISTANT_CONTENT = 0x61,
};

enum meta_msg_id{
    /** 短信 */
    MSG_ID_SMS            = 0x00,
    /** 微信 */
    MSG_ID_WC             = 0x01,
    /** QQ */
    MSG_ID_QQ             = 0x02,
    /** 飞书 */
    MSG_ID_FS             = 0x03,
    /** 其他 */
    MSG_ID_OTHER          = 0xFF,
};

enum meta_audio_ctl{
    /** 停止 */
    AUDIO_CTL_STOP        = 0x00,
    /** 播放 */
    AUDIO_CTL_START       = 0x01,
    /** 下一首 */
    AUDIO_CTL_NEXT        = 0x02,
    /** 上一首 */
    AUDIO_CTL_PREV        = 0x03,
};

enum meta_subscribe{
    /** 取消订阅 */
    META_UNSUBSCRIBE      = 0x00,
    /** 订阅 */
    META_SUBSCRIBE        = 0x01,
};

enum meta_call_ctl{
    /** 挂断 */
    CALL_CTL_HANG_UP      = 0x00,
    /** 接听 */
    CALL_CTL_ANSWER       = 0x01,
    /** 静音 */
    CALL_CTL_MUTE         = 0x02,
};

enum meta_dial_remind {
    /** 拨号成功 */
    DIAL_REMIND_SUCCESS   = 0x00,
    /** 拨号失败 */
    DIAL_REMIND_FAILED    = 0x01,
};

enum meta_imu_type{
    /** 加速度计 */
    IMU_ACCEL             = 0x00,
    /** 陀螺仪 */
    IMU_GYROS             = 0x01,
    /** 磁力计 */
    IMU_MAGNE             = 0x02,
    /** 算法结果 */
    ALGORITHM_RESULT      = 0x03,
};

enum meta_bin_type{
    /** master app bin */
    MASTER_APP_BIN        = 0x10,
    /** master res bin */
    MASTER_RES_BIN        = 0x11,
    /** master font bin */
    MASTER_FONT_BIN       = 0x12,
    /** master pt */
    MASTER_PT_BIN         = 0x13,
    /** master bootloader */
    MASTER_BL_BIN         = 0x14,

    /** slave app bin */
    SLAVE_APP_BIN         = 0x20,
    /** slave dsp bin */
    SLAVE_DSP_BIN         = 0x21,
    /** slave ROFS bin */
    SLAVE_ROFS_BIN        = 0x22,
    /** slave pt */
    SLAVE_PT_BIN          = 0x23,
    /** slave bl bin */
    SLAVE_BL_BIN          = 0x24,
    /** slave nv bin */
    SLAVE_NV_BIN          = 0x25,

    /** raw image */
    COMM_DATA_RAW_IMAGE   = 0x30,
    /** 小说文本 */
    COMM_DATA_NOVEL_TEXT  = 0x31,
    /** 提词器文本 */
    COMM_DATA_AUTOCUE     = 0x32,
    /** 导航数据 */
    COMM_DATA_NAVIGATION  = 0x33,
    /** 导航经纬度信息 */
    COMM_INFO_LAT_LON     = 0x34,
    
    
    /** master log */
    COMM_LOG_MASTER       = 0x40,
    /** slave log str */
    COMM_LOG_SLAVE        = 0x41,
    /**算法眼镜端绘制数据*/
    COMM_DATA_ALGO_DRAW   = 0x50,
    
    COMM_DATA_VOICE_ASSISTANT_CONTENT = 0x60,
};

enum meta_packet_type{
    META_PACKET_BEGIN     = 0x00,
    META_PACKET_MIDDLE    = 0x01,
    META_PACKET_END       = 0x02,
};

/** 启动模式 */
enum meta_boot_mode{
    META_BOOTNULL         = 0x00,
    META_BOOTSYSTEM       = 0x01,
    META_BOOTLOADER       = 0x02,
};

enum meta_screen_type{
    SCREEN_LEFT           = 0x00,
    SCREEN_RIGHT          = 0x01,
};

enum meta_screen_coord_adjust_mode{
    /** 软件调节 */
    ADJUST_SOFT           = 0x00,
    /** 硬件调节 */
    ADJUST_HARDWARE       = 0x01,
};

/** 屏幕亮度模式 */
enum meta_brightness_mode{
    /** 自动亮度 */
    BRIGHTNESS_AUTO       = 0x00,
    /** 手动亮度 */
    BRIGHTNESS_MANUAL     = 0x01,

};

enum meta_key_event{
    /** home键单击 */
    HOME_KEY_CLICK        = 0x00,
    /** home键双击 */
    HOME_KEY_DOUBLE_CLICK = 0x01,
    /** home键长按 */
    HOME_KEY_LONG_PRESS   = 0x02,
    /** captouch佩戴 */
    CAPTOUCH_KEY_WEAR     = 0x03,
    /** captouch摘下 */
    CAPTOUCH_KEY_DROP     = 0x04,
};

enum meta_tone_index {
    /** 单击事件 */
    ACTION_SINGLE_CLICK      = 0x0000,
    /** 双击事件 */
    ACTION_DOUBLE_CLICK      = 0x0001,
    /** 滑动事件 */
    ACTION_SWIPE             = 0x0002,
    /** 低电量事件 */
    ACTION_LOW_BATTERY       = 0x0003,
};

enum meta_stream_type{
    /** pcm */
    META_STREAM_PCM       = 0x30,

};

enum meta_language {
    /** 中文 */
    META_LANGUAGE_CN      = 0x00,
    /** 英文 */
    META_LANGUAGE_EN      = 0x01,
};


enum meta_role {
    /** 眼镜 */
    META_ROLE_DEVICE      = 0x00,
    /** 手机 */
    META_ROLE_HOST        = 0x10,

};

enum meta_screen_light_mode {
    /** 点亮两个屏幕 */
    SCREEN_LIGHT_BOTH     = 0x00,
    /** 点亮左屏幕 */
    SCREEN_LIGHT_LEFT     = 0x01,
    /** 点亮右屏幕 */
    SCREEN_LIGHT_RIGHT    = 0x02,

};

enum meta_test_func_cmd_type {
    /** 触控条前滑 */
    TEST_FUNC_TOUCH_BAR_FORWARD         = 0x00,
    /** 触控条后滑 */
    TEST_FUNC_TOUCH_BAR_BACKWARD        = 0x01,
    /** 触控条单击 */
    TEST_FUNC_TOUCH_BAR_SINGLE_CLICKED  = 0x02,
    /** 触控条长按 */
    TEST_FUNC_TOUCH_BAR_LONG_PRESSED    = 0x03,
    /** 多功能键单击 */
    TEST_FUNC_HOME_SINGLE_CLICKED       = 0x04,
    /** 多功能键双击 */
    TEST_FUNC_HOME_DOUBLE_CLICKED       = 0x05,
    /** 多功能键长按 */
    TEST_FUNC_HOME_LONG_PRESSED         = 0x06,
    /** 多功能键按下 */
    TEST_FUNC_HOME_PRESSED              = 0x07,
    /** 多功能键释放 */
    TEST_FUNC_HOME_RELEASED             = 0x08,
    /** 触摸条按下 */
    TEST_FUNC_TOUCH_BAR_PRESSED         = 0x09,
    /** 触摸条释放 */
    TEST_FUNC_TOUCH_BAR_RELEASED        = 0x0A,
    
};

enum meta_lowpower_opt {
    /** 低电量无处理 */
    LOWPOWER_OPT_NULL     = 0x00,
    /** 低电量关左光机 */
    LOWPOWER_OPT_SCREEN_L_OFF = 0x01,
    /** 低电量关右光机 */
    LOWPOWER_OPT_SCREEN_R_OFF = 0x02,
};

__packed_struct meta_packet_req_head{
    /** bin文件类型，在 meta_bin_type 中定义 */
    uint8_t bin_type;
    /** packet类型，在 meta_packet_type 中定义 */
    uint8_t packet_type;
    /** packet crc */
    uint32_t crc;
    /** packet index */
    uint32_t index;
};

__packed_struct meta_packet_rsp{
    /** bin文件类型，在 meta_bin_type 中定义 */
    uint8_t bin_type;
    /** packet index */
    uint32_t index;
};

__packed_struct meta_comm_data_head {
    /** bin文件类型，在 meta_bin_type 中定义 */
    uint8_t bin_type;
    uint32_t len;
    uint32_t crc;
    uint32_t resvd1;
    uint32_t resvd2;
    uint32_t resvd3;
    uint32_t resvd4;
};

__packed_struct meta_boot_param{
    uint8_t  slave_mode:4;
    uint8_t  master_mode:4;
};

__packed_struct meta_imu_config{
    uint8_t accel_freq;
    uint8_t gyros_freq;
    uint8_t magne_freq;
};

__packed_struct meta_imu_info{
    /** 类型 */
    uint8_t type;
    /** 时间戳 */
    uint64_t timestamp;
    float x;
    float y;
    float z;
};

__packed_struct meta_batt_info{
    /** 电量 0-100 */
    uint8_t value;
    /** 电池状态 1-充电 */
    uint8_t state;

};

__packed_struct meta_screen_coordinate{
    /** 屏幕类型 */
    uint8_t screen_type;
    /** coordinate x */
    int16_t x;
    /** coordinate y */
    int16_t y;
};

__packed_struct meta_version{
    /** 主版本号 */
    uint8_t major;
    /** 子版本号 */
    uint8_t minor;
    /** 修订版本号 */
    uint8_t revision;
    /** 保留字段 */
    uint8_t reserve;
};

__packed_struct meta_weather{
    /** 天气状况，参考README */
    //uint8_t weather;
    /** 风向 */
    uint8_t winddirection;
    /** 风力 */
    uint8_t windpower;
    /** 湿度 */
    uint8_t humidity;
    /** 温度 */
    int16_t temperature;
    /** 最低温度 */
    int16_t temperature_min;
    /** 最高温度 */
    int16_t temperature_max;
    /** 空气质量 */
    uint16_t air_quality;
};

__packed_struct meta_font_size {
    uint8_t w0;
    uint8_t h0;
    uint8_t w1;
    uint8_t h1;
};

__packed_struct meta_rtt_text_head{
    /** 角色 */
    uint8_t role;
    /** 分段用 */
    uint8_t id;
};

__packed_struct meta_cmd_head{
    uint16_t magic;
    /** cmd类型: meta_cmd_type */
    uint16_t  type;
    /** value总长度 */
    uint16_t total_len;
    /** 包类型:meta_cmd_packet_type */
    uint8_t  packet_type:1;
    /** 当前包value长度 */
    uint16_t value_len:15;
};

__packed_struct meta_stream_head{
    uint16_t magic;
    /** cmd类型: meta_cmd_type */
    uint16_t  type;
    /** 流序号 */
    uint16_t index;
    /** 当前包value长度 */
    uint16_t value_len;
};

__packed_struct meta_captouch_adc{
    /** 佩戴检测通道0数值 */
    int16_t adc_ch0;
    /** 佩戴检测通道1数值 */
    int16_t adc_ch1;
};



//__packed_struct meta_cmd_rsp{
//    uint8_t status;
//    uint8_t data[META_CMD_MAX_PACKET_SIZE - 1];
//};
//
//__packed_struct meta_cmd_value{
//    __packed_union
//    {
//        uint8_t _data[META_CMD_MAX_PACKET_SIZE];
//        struct meta_cmd_rsp rsp;
//    }data;
//};
//
//__packed_struct meta_cmd_msg{
//    struct meta_cmd_head head;
//    struct meta_cmd_value value;
//};

/** tlv define **/
__packed_struct meta_payload_tlv{
    uint8_t type;
    uint16_t len;
};

#endif

