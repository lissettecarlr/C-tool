#include "stdint.h"


uint32_t count_clock_interval(uint32_t currentTime,uint32_t currentTarget,uint32_t cycleTime)
{
    uint32_t interval=0;
    uint32_t timeTemp;//周期中的当前时刻
    uint32_t cycleTime=0; //周期中的发送时刻

    cycleTime = currentTarget%cycleTime;

    if(cycleTime ==0)
        cycleTime=1;

    timeTemp = currentTime%CYCLE_INTERVAL_S;

    if(timeTemp < cycleTime) //目标时间在当前时间之后
    {
        if((cycleTime - timeTemp)< WAKEP_MIN_TIME )//由于时钟偏差在目标时间之前醒来
        {
            interval = CYCLE_INTERVAL_S+(cycleTime - timeTemp); //1天加上偏差时间
        }else
        {
            interval = cycleTime - timeTemp;
        }
    }
    else //当目标时间和当前时间相等则 为 CYCLE_INTERVAL_S
    {
        interval = CYCLE_INTERVAL_S - (timeTemp-cycleTime);
    }
    return interval;
}

