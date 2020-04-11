#include <Arduino.h>    //  Using PlatformIO. This si required
#include <dwd.hpp>

#define halfSecond 500
#define second 1000
#define minute 60000

timer timer1(1, halfSecond);
timer timer2(45, second);
int flag;

void setup()
{
    flag = 0;
}

void loop()
{
    if (timer1.checkInterval())
    {

        if (flag == 0)
        {
            flag = 1;
            timer1.setDelta(1, minute);
        }

        /* Do some stuff here */
        /* First time immediately. then every minute */

        timer1.resetTimer();
    }
    if (timer2.checkInterval())
    {

        /* Do some stuff here */
        /* every 45 seconds */

        timer2.resetTimer();
    }
}
