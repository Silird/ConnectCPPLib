package ru.silirdco.connectcpplib.main;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import ru.silirdco.connectcpplib.jni.HelloWorldJNI;
import ru.silirdco.connectcpplib.jnidinlib.DynlibJNI;

public class ConnectCPPLibMain {
    private static final Logger logger = LoggerFactory.getLogger(ConnectCPPLibMain.class);

    public static void main(String[] args) {
        new HelloWorldJNI().sayHello();
        DynlibJNI dynlibJNI = new DynlibJNI();
        double d = 100;
        System.out.println("sqrt: " + dynlibJNI.getSqrt(d));
    }
}
