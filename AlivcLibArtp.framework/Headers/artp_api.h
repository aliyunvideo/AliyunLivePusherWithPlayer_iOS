#pragma once

#include "artp_type.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*! \file */

	/**
	 * @brief 初始化artp推流模块
	 * @param pLiveInfo      artp推流初始化所需的参数   入参
	 * @param phARTPService  artp推流模块句柄           出参
	 * @return  ARTP_OK 成功  ARTP_ERR 失败
	 */
	ARTP_API ARTP_RET artp_init_media_transporter(ST_ARTP_LIVE_INFO pLiveInfo, ARTP_OUT _HARTPSERVICE *phARTPService);

	/**
     * @brief 开启推流模块，建立推流连接
     * @param phARTPService  artp模块句柄     入参
	 * @attention 该方法只是发起推流请求，该过程是异步的，推流连接的状态根据 EN_ARTP_LIVE_STAT 回调类型进行判断
	 * @return  ARTP_OK 发起推流请求成功  ARTP_ERR 发起推流请求失败
     */
	ARTP_API ARTP_RET artp_start_media_transporter(_HARTPSERVICE phARTPService);
 
	/**
	 * @brief 设置回调接口，用于接收推流过程中的消息回调
	 * @param phARTPService    artp模块句柄    入参
	 * @param pUserHandler     用户的推流实例  入参
	 * @params pCallbacks      状态回调集      入参
	 * @return  ARTP_OK 成功  ARTP_ERR 失败
	 */
	ARTP_API ARTP_RET artp_set_stat_callbacks(_HARTPSERVICE phARTPService, void *pUserHandler, ST_ARTP_STAT_CALLBACKS *pCallbacks);

	/**
	 * @brief 发送SPS/PPS，无需startcode
	 * @param phARTPService  artp模块句柄       入参
	 * @param sps_data       SPS数据            入参
	 * @param sps_size       SPS长度            入参
	 * @param pps_data       PPS数据            入参
	 * @param pps_size       PPS长度            入参
     * @param vps_data       VPS数据            入参，H265推流时非空
     * @param vps_size       VPS长度            入参，H265推流时非0
	 * @return  ARTP_OK 成功  ARTP_ERR 失败
	 */
	ARTP_API ARTP_RET artp_send_video_conf_info(_HARTPSERVICE phARTPService, uint8_t *sps_data, int32_t sps_size,
                                                uint8_t *pps_data, int32_t pps_size, uint8_t *vps_data, int32_t vps_size);

	/**
	 * @brief 发送音频配置信息
	 * @param phARTPService   artp模块句柄
	 * @param audioInfo       音频信息
	 * @return  ARTP_OK 成功  ARTP_ERR 失败
	 */
	ARTP_API ARTP_RET artp_send_audio_conf_info(_HARTPSERVICE phARTPService, ST_ARTP_AUDIO_INFO audioInfo);

	/**
	 * @brief 发送视频数据包，无需startcode
	 * @param phARTPService    artp模块句柄
	 * @param data             视频包数据
	 * @param length           视频包数据长度
	 * @param timestamp        当前视频帧的采集时间戳
     * @param pts              pts
     * @param videoNaluInfo    多slice发送时使用该参数，单nal模式下传NULL即可
     * @param is_h265          是否是H265推流
	 * @attention 调用该方法前，必须先调用artp_send_video_conf_info()方法.
	 * @return  ARTP_OK 成功  ARTP_ERR 失败
	 */
	ARTP_API ARTP_RET artp_send_video_mediadata(_HARTPSERVICE phARTPService, uint8_t *data, int length,
                                                uint64_t timestamp, uint32_t pts,
                                                ST_ARTP_VideoNaluInfo *videoNaluInfo, uint8_t is_h265);

	/**
	 * @brief 发送音频数据包
	 * @param phARTPService artp模块句柄
	 * @param data       音频包数据
	 * @param length     音频包数据长度
	 * @param timestamp  当前音频帧的采集时间戳
	 * @note 调用该方法前，必须先调用artp_send_audio_conf_info()方法.
	 */
	ARTP_API ARTP_RET artp_send_audio_mediadata(_HARTPSERVICE phARTPService, uint8_t *data, int length, uint64_t timestamp);

	/**
	 * @brief 停止ARTP推流
	 * @param phARTPService  artp模块句柄
	 * @return  ARTP_OK 成功  ARTP_ERR 失败
	 */
	ARTP_API ARTP_RET artp_stop_media_transpoter(_HARTPSERVICE phARTPService);

	/**
	 * @brief 释放ARTP相关资源
	 * @param phARTPService  artp模块句柄
	 * @return  ARTP_OK 成功  ARTP_ERR 失败
	 */
	ARTP_API ARTP_RET artp_release_media_transporter(_HARTPSERVICE phARTPService);

	/**
	 * @brief 获取统计数据
	 * @param phARTPService artp模块句柄
	 * @param stats_str  统计数据
	 * @param max_length 每次获取数据的最大长度
	 * @return  ARTP_OK 成功  ARTP_ERR 失败
	 */
	ARTP_API ARTP_RET artp_get_statistics(_HARTPSERVICE phARTPService, ARTP_OUT char *stats_str, int max_length);

#ifdef __cplusplus
}
#endif // __cplusplus
