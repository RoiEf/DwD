#include "dwd.h"

timer::timer()
{
    delta = 1000;           // 1 sec delta
    firstTimeFlag = 0;
    startMillis = millis(); //initial start time for DwD
}
timer::timer(unsigned long t)
{
    delta = t;
    firstTimeFlag = 0;
    startMillis = millis(); //initial start time for DwD
}

void timer::setDelta(unsigned long t)
{
    delta = t;
}

int timer::getDelta()
{
    return int(delta / 6000);
}

void timer::resetTimer()
{
    startMillis = millis();
}

bool timer::checkInterval()
{
    currentMillis = millis();
    if (currentMillis - startMillis >= delta) //test whether the period has elapsed
    {
        return 1;
    }
    else
    {
        return 0;
    }
}