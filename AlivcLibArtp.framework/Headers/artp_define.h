#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#define ARTP_DLL_EXPORTS
#ifdef ARTP_DLL_EXPORTS
#define ARTP_API _declspec(dllexport)
#else
#define ARTP_API _declspec(dllimport)
#endif // ARTP_DLL_EXPORTS
#else
#define ARTP_API 
#endif

/*! \file */

#define ARTP_HANDLE_TYPE(_name) struct stru_##_name##__{ int iUnused; } *
#define ARTP_RET_TYPE(_name, _type) struct stru_##_name##_type {int iUnused; } *

// 函数返回值
typedef ARTP_RET_TYPE(_RET, _INT)  ARTP_RET;
#define ARTP_OK                   (ARTP_RET)0
#define ARTP_ERR                  (ARTP_RET)-1

// ARTP 出参标识
#define ARTP_OUT
    
#define MAX_NALU_NUM_PER_FRAME 8
    
// NTP时戳SEI
#ifndef DELAY_CALC
#define DELAY_CALC
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
