#include "DynlibJNI.h"
#include "dynamic.h"

JNIEXPORT jdouble JNICALL Java_ru_SilirdCo_ConnectCPPLib_jniDinlib_DynlibJNI_getSqrt
  (JNIEnv *, jobject, jdouble d) {
      return calcSqrt((double) d);
}