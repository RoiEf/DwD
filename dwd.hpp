#pragma once
//#ifndef __tim301___
//#define __tim301___

#include <Arduino.h>  // This is required for use with PlatformIO

class TIMER {
    unsigned long currentMillis;
    unsigned long startMillis;
    unsigned long delta;
    bool firstTimeFlag = true;

   public:
    TIMER() {
        delta = 1000;  // 1 sec delta
        firstTimeFlag = 0;
        startMillis = millis();  //initial start time for DwD
    }
    TIMER(unsigned long t) {
        delta = t;
        firstTimeFlag = 0;
        startMillis = millis();  //initial start time for DwD
    }

    void setDelta(unsigned long t) {
        delta = t;
    }

    int getDelta() {
        return (int)delta;
    }

    void resetTimer() {
        startMillis = millis();
    }

    bool checkInterval() {
        currentMillis = millis();
        if (currentMillis - startMillis >= delta)  //test whether the period has elapsed
        {
            return 1;
        } else {
            return 0;
        }
    }
    bool checkInterval(bool reset) {
        currentMillis = millis();
        if (currentMillis - startMillis >= delta) {  //test whether the period has elapsed
            if (reset)
                resetTimer();
            return 1;
        } else
            return 0;
    }
    bool getFirst() {
        if (firstTimeFlag) {
            firstTimeFlag = false;
            return true;
        } else
            return false;
    }
};

//#endif
