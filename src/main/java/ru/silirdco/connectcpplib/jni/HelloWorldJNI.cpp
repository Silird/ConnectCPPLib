#include <iostream>
#include "HelloWorldJNI.h"

JNIEXPORT void JNICALL Java_ru_silirdco_connectcpplib_jni_HelloWorldJNI_sayHello
  (JNIEnv *, jobject) {
    std::cout << "Hello from C++!" << std::endl;
}
