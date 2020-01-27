package ru.SilirdCo.ConnectCPPLib.jniDinlib;

public class DynlibJNI {
    static {
        System.loadLibrary("Dynlib");
    }

    public native double getSqrt(double d);
}
