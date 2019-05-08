#ifndef __tim___
#define __tim___

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class timer
{
    unsigned long currentMillis;
    unsigned long startMillis;
    unsigned long delta;
    bool  firstTimeFlag;

  public:
    timer();
    timer(unsigned long t);
    void setDelta(unsigned long t);
    int getDelta();
    void resetTimer();
    bool checkInterval();
};

#endif