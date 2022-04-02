/* 
 * File:   cpu_time.h
 * Author: ulmerfa
 *
 * Created on 8. April 2016, 09:07
 */

#ifndef CPU_TIME_H
#define	CPU_TIME_H

typedef uint32_t cpu_time_t;

typedef uint8_t cpu_time_SubMs_t;

/**
 * Gets the current time since the last reset
 * The value is only approximate, one unit is actually 1.024ms
 * The counter starts over at 0 every hour
 * @return the number of ms since the last reset
 */
cpu_time_t cpu_time_Get();

/**
 * Calculates the time difference since a given time
 * The value is only approximate, one unit is actually 1.024ms
 * @param start The time to calculate the current difference from (in ms)
 * @return the difference (in ms)
 */
cpu_time_t cpu_time_Diff(cpu_time_t start);

/**
 * Get the sub ms part of the current time
 * Unit is not specified
 * @return the sub ms part of the current time
 */
cpu_time_SubMs_t cpu_time_GetSubMs();

/**
 * Checks if a desired time has already elapsed
 * @param start The time start time (it will be checked if enough time has elapsed since then)
 * @param duration The desired duration (this much time must elapse before true is returned)
 * @param startSubMs (optional) The sub milliseconds part of the start time. If omitted is set to 0
 * @return False if less time has passed, true if that much or more time has passed
 */
bool cpu_time_CheckElapsedSubMs(cpu_time_t start, cpu_time_t duration, cpu_time_SubMs_t startSubMs);

#endif	/* CPU_TIME_H */