/* 
 * File:   cpu_time.c
 * Author: ulmerfa
 *
 * Created on 8. April 2016, 09:01
 */

#include "main.h"

/*
 * Functions to retrieve the time since the last reset
 */

/**
 * Holds the time since the last startup
 * Unit is milliseconds
 */
cpu_time_t cpu_Time = 0;

/**
 * Gets the current time since the last reset
 * Unit is milliseconds
 * The counter starts over at 0 every hour
 * @return the number of ms since the last reset
 */
cpu_time_t cpu_time_Get(){
    return cpu_Time;
}

/**
 * Calculates the time difference since a given time
 * Unit is milliseconds
 * @param start The time to calculate the current difference from (in ms)
 * @return the difference (in ms)
 */
cpu_time_t cpu_time_Diff(cpu_time_t start){
    return cpu_time_Get() - start;
}

/**
 * Get the sub ms part of the current time
 * Unit is not specified
 * @return the sub ms part of the current time
 */
cpu_time_SubMs_t cpu_time_GetSubMs(){
    return (cpu_time_SubMs_t) SMT2_GetTimerValue();
}

/**
 * Checks if a desired time has already elapsed
 * @param start The time start time (it will be checked if enough time has elapsed since then)
 * @param duration The desired duration (this much time must elapse before true is returned)
 * @param startSubMs The sub milliseconds part of the start time.
 * @return False if less time has passed, true if that much or more time has passed
 */
bool cpu_time_CheckElapsedSubMs(cpu_time_t start, cpu_time_t duration, cpu_time_SubMs_t startSubMs){
    cpu_time_t diff = cpu_time_Diff(start);
    if(diff < duration)
        return false;
    else if(diff > duration)
        return true;
    else if(startSubMs < cpu_time_GetSubMs())
        return false;
    else
        return true;
}

/**
 * Shall be called every millisecond.
 * Increments cpu_Time
 */
void cpu_time_Update(){
    cpu_Time++;
}