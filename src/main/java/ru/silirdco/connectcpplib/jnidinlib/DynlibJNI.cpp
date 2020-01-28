#include "DynlibJNI.h"
#include "dynamic.h"

JNIEXPORT jdouble JNICALL Java_ru_silirdco_connectcpplib_jnidinlib_DynlibJNI_getSqrt
  (JNIEnv *, jobject, jdouble d) {
      return calcSqrt((double) d);
}
