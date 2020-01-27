package ru.SilirdCo.ConnectCPPLib.Main;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import ru.SilirdCo.ConnectCPPLib.jni.HelloWorldJNI;
import ru.SilirdCo.ConnectCPPLib.jniDinlib.DynlibJNI;

public class ConnectCPPLibMain {
    private static final Logger logger = LoggerFactory.getLogger(ConnectCPPLibMain.class);

    public static void main(String[] args) {
//        System.loadLibrary("Hello");
        new HelloWorldJNI().sayHello();
        DynlibJNI dynlibJNI = new DynlibJNI();
        double d = 100;
        System.out.println("sqrt: " + dynlibJNI.getSqrt(d));

    }
}
