#pragma once

#include "artp_define.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \file */

// ARTP 模块句柄
typedef ARTP_HANDLE_TYPE(_HARTPSERVICE) _HARTPSERVICE;

// 网络连接状态
typedef enum enum_ARTP_LIVE_CONN_STAT {
	EN_ARTP_CONN_STAT_NOUSE = 0,   //!< 未初始化
	EN_ARTP_CONN_STAT_INIT,        //!< 开始建立连接
	EN_ARTP_CONN_STAT_READY,       //!< 网络连接建立成功
	EN_ARTP_CONN_STAT_CLOSED,      //!< 网络连接关闭
	EN_ARTP_CONN_STAT_ERROR        //!< 网络连接出错
} EN_ARTP_LIVE_CONN_STAT;

// 直播状态
typedef enum enum_ARTP_LIVING_STAT {
	EN_ARTP_LIVING_STAT_UNINIT = 0,      //!< 未初始化状态
	EN_ARTP_LIVING_STAT_INIT,            //!< artp模块初始化完成
	EN_ARTP_LIVING_STAT_SUCCESS,         //!< 推流连接建立成功
	EN_ARTP_LIVING_STAT_FAILED,          //!< 推流连接建立失败
	EN_ARTP_LIVING_STAT_AVDATA_ERROR,    //!< 发送数据失败
	EN_ARTP_LIVING_STAT_STOPPED          //!< 推流断开
} EN_ARTP_LIVE_STAT;

// artp 日志级别
typedef enum enum_ARTP_LOG_LEVEL {
	EN_ARTP_LOG_VERBOSE = 0,   //!< 全部输出
	EN_ARTP_LOG_DEBUG,         //!< 调试信息
	EN_ARTP_LOG_INFO,          //!< Info信息
	EN_ARTP_LOG_WARN,          //!< 警告信息
	EN_ARTP_LOG_ERROR,         //!< 错误信息
	EN_ARTP_LOG_SILENT         //!< 不输出
} EN_ARTP_LOG_LEVEL;

// 错误码
typedef enum enum_ARTP_ERROR_CODE {
	EN_RECV_HEARTBEAT_TIMEOUT = 610, //!< 接收服务器心跳超时
	EN_START_PUSH_TIMEOUT     = 611, //!< 开始推流响应超时
	EN_SEND_SPSPPS_TIMEOUT    = 612, //!< 发送SPS/PPS超时
	EN_SEN_AACCONF_TIMEOUT    = 613  //!< 发送AAC Conf超时
} EN_ARTP_ERROR_CODE;

// artp初始化所需参数信息
typedef struct struct_ARTP_LIVE_INFO {
	//audio 
	uint32_t    sampleRate;    //!< 音频采样率
	uint32_t    channels;      //!< 音频通道数
	uint32_t    sampleSize;    //!< 每个采样点的字节数
	uint32_t    audioBitrate;  //!< 音频码率(单位kbps)

	//video
	uint32_t    frameRate;        //!< 视频帧率
	uint32_t    width;            //!< 视频宽度
	uint32_t    height;           //!< 视频高度
	uint32_t    videoBitrate;     //!< 视频码率(单位kbps)
	uint32_t    minVideoBitrate;  //!< 对应分辨率下最小的视频码率(单位kbps)
	uint32_t    maxVideoBitrate;  //!< 对应分辨率下最大的视频码率(单位kbps)

	//config
	uint32_t    disable_bwe;        //!< 是否关闭带宽估计，1：关闭 其它：不关闭
	uint32_t    disable_video_fec;  //!< 是否关闭视频fec，1：关闭 其它：不关闭
	uint32_t    video_fec_type;     //!< 视频fec类型, 0:ulpfec, 1:rsfec

	//transport
	char       *pushUrl;      //!< 推流地址
	char       *remoteIP;     //!< 推流服务器IP
	int         remotePort;   //!< 推流服务器端口

	// 日志级别
	EN_ARTP_LOG_LEVEL loglevel;  //!< 日志级别
} ST_ARTP_LIVE_INFO;

// 音频参数信息
typedef struct struct_ARTP_AUDIO_INFO {
	uint32_t samplerate;  //!< 采样率
	uint32_t channels;    //!< 通道数
} ST_ARTP_AUDIO_INFO;
    
typedef struct struct_ARTP_VideoNaluInfo {
    //nalu 个数
    uint32_t nalu_num;
    //每个 nalu 的长度.不需要包含 start code/两字节的起始码的长度.
    uint32_t nalu_len[MAX_NALU_NUM_PER_FRAME];
    //每个 nalu 的头部偏移长度
    //4字节 start_code = 4, 3字节 start_code = 3, 长度起始码 = 2, 没有头部 = 0.
    uint32_t nalu_offset[MAX_NALU_NUM_PER_FRAME];
} ST_ARTP_VideoNaluInfo;

/**
 * @param pUserHandler  推流实例句柄
 * @param stat          直播状态
 */
typedef void(*OnLiveLivingStat)(void *pUserHandler, EN_ARTP_LIVE_STAT stat);

/**
 * @param pUserHandler  推流实例句柄
 * @param stat          网络连接状态
 * @param errCode       错误码，只在状态为error时有效.
 */
typedef void(*OnLiveConnectStat)(void *pUserHandler, EN_ARTP_LIVE_CONN_STAT stat, EN_ARTP_ERROR_CODE errCode);

/**
 * @param pUserHandler  推流实例句柄
 * @param bitrate_bps   实时网络带宽
 */
typedef void(*OnLiveBWEResponse)(void *pUserHandler, uint32_t bitrate_bps);

// 状态回调集
typedef struct struct_ARTP_STAT_CALLBACKS {
	OnLiveConnectStat on_live_connect_stat;  //!< 网络连接状态回调
	OnLiveLivingStat  on_live_living_stat;   //!< 直播状态回调
	OnLiveBWEResponse on_live_bwe_response;  //!< 实时带宽反馈
} ST_ARTP_STAT_CALLBACKS;

#ifdef __cplusplus
}
#endif // __cplusplus
