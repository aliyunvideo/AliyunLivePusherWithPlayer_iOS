//
//  AlivcLivePushConstants.h
//  AlivcLiveCaptureLib
//
//  Created by TripleL on 2017/9/25.
//  Copyright © 2017年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>



/**
 SDK log级别

 - AlivcLivePushLogLevelAll: 全部
 - AlivcLivePushLogLevelVerbose: 冗长
 - AlivcLivePushLogLevelDebug: 调试
 - AlivcLivePushLogLevelInfo: 提示
 - AlivcLivePushLogLevelWarn: 警告
 - AlivcLivePushLogLevelError: 错误
 - AlivcLivePushLogLevelFatal: 阻塞错误
 */
typedef NS_ENUM(NSInteger, AlivcLivePushLogLevel){
    AlivcLivePushLogLevelAll = 1,
    AlivcLivePushLogLevelVerbose,
    AlivcLivePushLogLevelDebug,
    AlivcLivePushLogLevelInfo,
    AlivcLivePushLogLevelWarn,
    AlivcLivePushLogLevelError,
    AlivcLivePushLogLevelFatal,
};

/**
 分辨率

 - AlivcLivePushResolution180P: 180P
 - AlivcLivePushResolution240P: 240P
 - AlivcLivePushResolution360P: 360P
 - AlivcLivePushResolution480P: 480P
 - AlivcLivePushResolution540P: 540P
 - AlivcLivePushResolution720P: 720P
 */
typedef NS_ENUM(NSInteger, AlivcLivePushResolution){
    AlivcLivePushResolution180P = 0,
    AlivcLivePushResolution240P,
    AlivcLivePushResolution360P,
    AlivcLivePushResolution480P,
    AlivcLivePushResolution540P,
    AlivcLivePushResolution720P,
};


/**
 推流模式

 - AlivcLivePushQualityModeResolutionFirst: 清晰度优先模式
 - AlivcLivePushQualityModeFluencyFirst: 流畅度优先模式
 - AlivcLivePushQualityModeCustom: 自定义模式
 */
typedef NS_ENUM(NSInteger, AlivcLivePushQualityMode){
    AlivcLivePushQualityModeResolutionFirst = 0,
    AlivcLivePushQualityModeFluencyFirst,
    AlivcLivePushQualityModeCustom,
};



typedef NS_ENUM(NSInteger, AlivcLivePushFPS) {
    AlivcLivePushFPS8  = 8,
    AlivcLivePushFPS10 = 10,
    AlivcLivePushFPS12 = 12,
    AlivcLivePushFPS15 = 15,
    AlivcLivePushFPS20 = 20,
    AlivcLivePushFPS25 = 25,
    AlivcLivePushFPS30 = 30,
};


/**
 推流屏幕方向

 - AlivcLivePushOrientationPortrait: 竖屏推流
 - AlivcLivePushOrientationLandscapeLeft: 横屏Left方向
 - AlivcLivePushOrientationLandscapeRight: 横屏Right方向
 */
typedef NS_ENUM(NSInteger, AlivcLivePushOrientation){
    AlivcLivePushOrientationPortrait = 0,
    AlivcLivePushOrientationLandscapeLeft,
    AlivcLivePushOrientationLandscapeRight,
};


/**
 摄像头方向

 - AlivcLivePushCameraTypeBack: 后置摄像头
 - AlivcLivePushCameraTypeFront: 前置摄像头
 */
typedef NS_ENUM(NSInteger, AlivcLivePushCameraType){
    AlivcLivePushCameraTypeBack = 0,
    AlivcLivePushCameraTypeFront,
};


/**
 缩放模式
 
 - AlivcLivePushScallingModeFit: 填充
 - AlivcLivePushScallingModeCrop: 裁剪
 */
typedef NS_ENUM(NSInteger, AlivcLivePushScallingMode){
    AlivcLivePushScallingModeFit = 0,
    AlivcLivePushScallingModeCrop,
};


/**
 视频编码模式
 
 - AlivcLivePushVideoEncoderModeHard: 硬编码
 - AlivcLivePushVideoEncoderModeSoft: 软编码
 */
typedef NS_ENUM(NSInteger, AlivcLivePushVideoEncoderMode){
    AlivcLivePushVideoEncoderModeHard = 0,
    AlivcLivePushVideoEncoderModeSoft,
};


/**
 音频编码格式

 - AlivcLivePushAudioEncoderProfile_AAC_LC: AAC_LC
 - AlivcLivePushAudioEncoderProfile_HE_AAC: HE_AAC
 - AlivcLivePushAudioEncoderProfile_HE_AAC_V2: HE_AAC_V2
 - AlivcLivePushAudioEncoderProfile_AAC_LD: AAC_LD
 */
typedef NS_ENUM(NSInteger, AlivcLivePushAudioEncoderProfile){
    AlivcLivePushAudioEncoderProfile_AAC_LC = 2,
    AlivcLivePushAudioEncoderProfile_HE_AAC = 5,
    AlivcLivePushAudioEncoderProfile_HE_AAC_V2 = 29,
    AlivcLivePushAudioEncoderProfile_AAC_LD = 29,
};


/**
 音频采样率
 
 - AlivcLivePushAudioSample32000: 32000Hz
 */
typedef NS_ENUM(NSInteger, AlivcLivePushAudioSampleRate){
    AlivcLivePushAudioSampleRate32000 = 32000,
    AlivcLivePushAudioSampleRate44100 = 44100,
};


/**
 声道数

 - AlivcLivePushAudioChannelOne: 单声道
 - AlivcLivePushAudioChannelTwo: 双声道
 */
typedef NS_ENUM(NSInteger, AlivcLivePushAudioChannel){
    AlivcLivePushAudioChannel_1 = 1,
    AlivcLivePushAudioChannel_2 = 2,
};


/**
 关键帧间隔

 - AlivcLivePushVideoEncodeGOP_1: 1s
 - AlivcLivePushVideoEncodeGOP_2: 2s
 - AlivcLivePushVideoEncodeGOP_3: 3s
 - AlivcLivePushVideoEncodeGOP_4: 4s
 - AlivcLivePushVideoEncodeGOP_5: 5s
 */
typedef NS_ENUM(NSInteger, AlivcLivePushVideoEncodeGOP){
    AlivcLivePushVideoEncodeGOP_1 = 1,
    AlivcLivePushVideoEncodeGOP_2 = 2,
    AlivcLivePushVideoEncodeGOP_3 = 3,
    AlivcLivePushVideoEncodeGOP_4 = 4,
    AlivcLivePushVideoEncodeGOP_5 = 5,
};


/**
 美颜模式

 - AlivcLivePushBeautyModeNormal: 普通版，不具备人脸识别功能
 - AlivcLivePushBeautyModeProfessional: 专业版，具备人脸识别功能。可以调节大眼瘦脸。
 */
typedef NS_ENUM(NSInteger, AlivcLivePushBeautyMode){
    AlivcLivePushBeautyModeNormal = 0,
    AlivcLivePushBeautyModeProfessional,
};



/**
 接口返回值错误码
 */
typedef NS_ENUM(NSInteger, AlivcPusherErrorCode){
    ALIVC_LIVE_PUSHER_INTERFACE_ERROR   = -1, // 接口调用内部错误
    ALIVC_LIVE_PUSHER_PARAM_ERROR       = -2, // 接口调用传入参数错误
    ALIVC_LIVE_PUSHER_UNKNOW_ERROR      = -3, // 接口调用未知错误
    ALIVC_LIVE_PUSHER_SEQUENCE_ERROR    = -4, // 接口调用顺序错误
};

