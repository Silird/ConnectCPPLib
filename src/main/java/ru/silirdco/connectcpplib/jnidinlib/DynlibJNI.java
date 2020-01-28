package ru.silirdco.connectcpplib.jnidinlib;

public class DynlibJNI {
    static {
        System.loadLibrary("Dynlib");
    }

    public native double getSqrt(double d);
}
