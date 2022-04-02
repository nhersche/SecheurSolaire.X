/* 
 * File:   fan.h
 * Author: Fabian
 *
 * Created on April 24, 2017, 4:21 PM
 */

#ifndef FAN_H
#define	FAN_H

#include "mcc_generated_files/pwm6.h"
#include "mcc_generated_files/pwm7.h"

#define fan_hot_speed PWM6_LoadDutyValue
#define fan_circ_speed PWM7_LoadDutyValue

#endif	/* FAN_H */

