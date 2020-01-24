package ru.SilirdCo.ConnectCPPLib.jni;

public class HelloWorldJNI {
    static {
        System.loadLibrary("Hello");
    }

    public native void sayHello();
}
