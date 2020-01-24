#include <iostream>
#include "ru_SilirdCo_ConnectCPPLib_jni_HelloWorldJNI.h"

JNIEXPORT void JNICALL Java_ru_SilirdCo_ConnectCPPLib_jni_HelloWorldJNI_sayHello(JNIEnv *, jobject) {
    std::cout << "Hello from C++!" << std::endl;
}