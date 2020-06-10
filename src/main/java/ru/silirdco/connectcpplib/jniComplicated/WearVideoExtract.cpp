#include "WearVideoExtract.h"
#include "extractWearData.h"
#include <iostream>
#include <vector>

std::string jstring2string(JNIEnv *env, jstring jStr);
jstring string2jstring(JNIEnv *env, const std::string &nativeString);
jint getSize(JNIEnv *env, jobject tracePos);
int getGetListInt(JNIEnv *env, jobject tracePos, jint index);
long getGetListLong(JNIEnv *env, jobject tracePos, jint index);

JNIEXPORT jboolean JNICALL Java_msd_sprut_service_video_wear_jni_WearVideoExtract_extractWearImage
  (JNIEnv *env, jobject, jstring imageFileName, jlong pos, jint size, jstring imageName) {
    std::string imageFileNameCPP = jstring2string(env, imageFileName);
    uint64_t posCPP = (uint64_t) pos;
    uint32_t sizeCPP = (uint32_t) size;
    std::string imageNameCPP = jstring2string(env, imageName);

    std::cout << "imageFileNameCPP: " << imageFileNameCPP << std::endl;
    std::cout << "posCPP: " << posCPP << std::endl;
    std::cout << "sizeCPP: " << sizeCPP << std::endl;
    std::cout << "imageNameCPP: " << imageNameCPP << std::endl;

    return extractWearImage(imageFileNameCPP, posCPP, sizeCPP, imageNameCPP);
}

JNIEXPORT jstring JNICALL Java_msd_sprut_service_video_wear_jni_WearVideoExtract_extractWearTrace
  (JNIEnv *env, jobject, jstring traceFileName, jobject tracePos, jobject traceSize) {

    std::string traceFileNameCPP = jstring2string(env, traceFileName);
    jint size = getSize(env, tracePos);
    std::vector<uint64_t> tracePosVector = {};
    for (jint i = 0; i < size; i++) {
        uint64_t el = (uint64_t) getGetListLong(env, tracePos, i);
        tracePosVector.push_back(el);
    }
    size = getSize(env, traceSize);
    std::vector<uint32_t> traceSizeVector = {};
    for (jint i = 0; i < size; i++) {
        uint32_t el = (uint32_t) getGetListInt(env, traceSize, i);
        traceSizeVector.push_back(el);
    }

    std::cout << "traceFileNameCPP: " << traceFileNameCPP << std::endl;
    std::cout << "tracePosVector: ";
    for (uint64_t el : tracePosVector) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    std::cout << "traceSizeVector: ";
    for (uint32_t el : traceSizeVector) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return string2jstring(env, extractWearTrace(traceFileNameCPP, tracePosVector, traceSizeVector));
}

std::string jstring2string(JNIEnv *env, jstring jStr) {
    const char *charStr = env->GetStringUTFChars(jStr, 0);
    std::string str(charStr);
    return str;
}

jstring string2jstring(JNIEnv *env, const std::string &nativeString) {
    return env->NewStringUTF(nativeString.c_str());
}

jint getSize(JNIEnv *env, jobject list) {
    const jclass listClass = env->GetObjectClass(list);
    const jmethodID size = env->GetMethodID(listClass, "size", "()I");
    jint result = (jint) env->CallIntMethod(list, size);

    env->DeleteLocalRef(listClass);

    return result;
}

int getGetListInt(JNIEnv *env, jobject list, jint index) {
    const jclass listClass = env->GetObjectClass(list);
    const jmethodID getMethod = env->GetMethodID(listClass, "get", "(I)Ljava/lang/Object;");
    jobject objInt = env->CallObjectMethod(list, getMethod, index);
    env->DeleteLocalRef(listClass);

    const jclass objIntClass = env->GetObjectClass(objInt);
    const jmethodID intValueMethod = env->GetMethodID(objIntClass, "intValue", "()I");
    int result = (int) env->CallIntMethod(objInt, intValueMethod);
    env->DeleteLocalRef(objIntClass);
    env->DeleteLocalRef(objInt);

    return result;
}

long getGetListLong(JNIEnv *env, jobject list, jint index) {
    const jclass listClass = env->GetObjectClass(list);
    const jmethodID getMethod = env->GetMethodID(listClass, "get", "(I)Ljava/lang/Object;");
    jobject objLong = env->CallObjectMethod(list, getMethod, index);
    env->DeleteLocalRef(listClass);

    const jclass objLongClass = env->GetObjectClass(objLong);
    const jmethodID longValueMethod = env->GetMethodID(objLongClass, "longValue", "()J");
    long result = (long) env->CallLongMethod(objLong, longValueMethod);
    env->DeleteLocalRef(objLongClass);
    env->DeleteLocalRef(objLong);

    return result;
}
