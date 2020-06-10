package ru.silirdco.connectcpplib.jniComplicated;

import java.util.List;

public class WearVideoExtract {
    static {
        System.loadLibrary("WearVideoExtract");
    }

    public native boolean extractWearImage(String imageFileName, long pos, int size, String imageName);

    public native String extractWearTrace(String traceFileName, List<Long> tracePos, List<Integer> traceSize);
}
