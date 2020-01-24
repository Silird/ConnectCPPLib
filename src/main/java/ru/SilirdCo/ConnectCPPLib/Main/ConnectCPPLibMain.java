package ru.SilirdCo.ConnectCPPLib.Main;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import ru.SilirdCo.ConnectCPPLib.jni.HelloWorldJNI;

public class ConnectCPPLibMain {
    private static final Logger logger = LoggerFactory.getLogger(ConnectCPPLibMain.class);

    public static void main(String[] args) {
//        System.loadLibrary("Hello");
        new HelloWorldJNI().sayHello();
    }
}
