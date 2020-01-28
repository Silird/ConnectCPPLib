package ru.silirdco.connectcpplib.jni;

public class HelloWorldJNI {
    static {
        System.loadLibrary("Hello");
    }

    public native void sayHello();
}
