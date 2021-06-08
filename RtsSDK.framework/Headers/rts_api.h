/* Copyright (c) 2020 Alibaba Group Holding Limited
 *
 * main api file for rts sdk
 */

#if !defined(__ALI_RTS_API_H__)
#define __ALI_RTS_API_H__

#include "rts_messages.h"

#ifndef ARTC_STATE_DEFINE
#define ARTC_STATE_DEFINE

#define ARTC_VIDEO_CACHE_SIZE  1
#define ARTC_AUDIO_CACHE_SIZE  2
#define ARTC_NET_DOWNLOADSPEED 3
#endif

/* Example:
 * struct rts_glue_funcs *fs = get_rts_funcs(2);
 * if(fs != NULL) {
 *     fs->preconfig(...); // optional. must call before open. affect all instances
 *
 *     void *h = fs->open("artc://....", "r");
 *
 *     if(h != NULL) {
 *         while(1) {
 *             struct rts_frame *frm = NULL;

 *             int c = fs->read(&frm, h);
 *             if(c == 1) {
 *                 printf("got one frame\n");
 *                 assert(frm != NULL);
 *                 frm->free_ptr(frm);
 *                 frm = NULL;
 *             }
 *             else if(c == 0) {
 *                 assert(frm == NULL);
 *                 printf("try again\n");
 *             }
 *             else {
 *                 assert(frm == NULL);
 *                 printf("error\n");
 *                 break;
 *             }
 *         }
 *         fs->close(h);
 *     }
 * }
 */

#if defined(__cplusplus)
extern "C" {
#endif

// structure to store subscribed stream info
// use ioctl(..., "get_stream_info", ...) to fetch
struct rts_worker_demux_info
{
    // audio part
    int audio_flag; // 1 - following audio info is valid; 0 - invalid
    int audio_channels; // 1
    int audio_sample_rate; // 48000

    // video part
    int video_flag; // 1 - following video info is valid; 0 - invalid
    int video_codec;      // 1 - h264  2 - hevc
    int video_width;
    int video_height;
    int video_profile;
    int video_level;

    unsigned char spspps[10 * 1024]; // large enough
    int spspps_len; // actual bytes used in spspps
};

struct rts_worker_demux_info2
{
    unsigned int uid; // 0: unspecified

    // audio part
    int audio_flag; // 1 - following audio info is valid; 0 - invalid
    int audio_channels; // 1
    int audio_sample_rate; // 48000

    // video part
    int video_flag; // 1 - following video info is valid; 0 - invalid
    int video_codec;      // 1 - h264
    int video_width;
    int video_height;
    int video_profile;
    int video_level;

    unsigned char spspps[10 * 1024]; // large enough
    int spspps_len; // actual bytes used in spspps
};

// structure to store subscribed stream info
// use ioctl(..., "get_pub_info", ...) to fetch
// not implemented yet
struct rts_worker_mux_info {
    // audio part
    int audio_flag; // 1 - following audio info is valid; 0 - invalid

    // video part
    int video_flag; // 1 - following video info is valid; 0 - invalid
};

struct rts_frame {
    void *buf;              // where frame data is stored
    int size;               // size of frame data in bytes
    int is_audio;           // 1 for audio frame, 0 for video frame
    unsigned long long pts; // presentation time stamp, in ms
    unsigned long long dts; // decoding time stamp, in ms
    int flag;               // for video frame (is_audio == 0)
                            //     bit 0: key frame;
                            //     bit 1: corruption
                            //     bit 2: sps
                            //     bit 3: sps change
    int duration;           // in ms

    // use this function to free rts_frame object
    void (*free_ptr)(struct rts_frame *);

    unsigned int uid; // reserved. which user this stream attached
};

// file operation style functions
struct rts_glue_funcs {
    int api_version; // validation. must be 2

    /* configure globaly, before open is called
     * do not change values during an instance is running
     */
    int (* preconfig)(const char *key, const char *val);

    /* open a stream specified by url
     * url:   stream url. artc stream supported for now
     * mode:  "r" for subscribe, "w" for publish
     * return value: handle to the stream. NULL if open failed
     */
    void *(* open)(const char *url, const char *mode);

    /* close the stream
     * handle: returned by open
     */
    void (* close)(void *handle);

    /* runtime control (e.g. get/set parameters)
     * negative return value for error
     */
    long long (* ioctl)(void *handle, const char *cmd, void *arg);

    /* read one frame
     * caller need free the returned frame
     * return value: 1 for one frame read into '*frame'; 0 for try
     *               later; -1 for EOF; or other negative value for
     *               fatal error
     */
    int (* read)(struct rts_frame **frame, void *handle);

    /* write one frame. callee free the frame
     * return value: 1 for ok; 0 for try
     *               later; -1 for EOF; or other negative value for
     *               fatal error
     */
    int (* write)(struct rts_frame **frame, void *handle);
};

/* @brief Query file operation style functions
 * @param version    Specify compatible api version
 * @return Structure containing function pointers
 * @note Caller need check return value NULL or not
 */
#if defined(WIN32)
  #if defined(BUILDDLL)
    #define DLL_PUBLIC __declspec(dllexport)
  #else
    #define DLL_PUBLIC __declspec(dllimport)
  #endif
#else
  #if defined(BUILDDLL)
    #define DLL_PUBLIC __attribute__ ((visibility("default")))
  #else
    #define DLL_PUBLIC
  #endif
#endif
DLL_PUBLIC
const struct rts_glue_funcs *get_rts_funcs(int version);

#if defined(__cplusplus)
}
#endif

#endif  // __ALI_RTS_API_H__
