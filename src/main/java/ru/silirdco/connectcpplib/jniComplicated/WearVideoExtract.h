#pragma once

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class msd_sprut_service_video_wear_jni_WearVideoExtract */

#ifdef JNI_EXPORTS
#define JNI_API __declspec(dllexport)
#else
#define JNI_API __declspec(dllimport)
#endif

#ifndef _Included_msd_sprut_service_video_wear_jni_WearVideoExtract
#define _Included_msd_sprut_service_video_wear_jni_WearVideoExtract
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     msd_sprut_service_video_wear_jni_WearVideoExtract
 * Method:    extractWearImage
 * Signature: (Ljava/lang/String;IILjava/lang/String;)Z
 */
JNIEXPORT JNI_API jboolean JNICALL Java_msd_sprut_service_video_wear_jni_WearVideoExtract_extractWearImage
  (JNIEnv *, jobject, jstring, jlong, jint, jstring);

/*
 * Class:     msd_sprut_service_video_wear_jni_WearVideoExtract
 * Method:    extractWearTrace
 * Signature: (Ljava/lang/String;Ljava/util/List;Ljava/util/List;)Ljava/lang/String;
 */
JNIEXPORT JNI_API jstring JNICALL Java_msd_sprut_service_video_wear_jni_WearVideoExtract_extractWearTrace
  (JNIEnv *, jobject, jstring, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
