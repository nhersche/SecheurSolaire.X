/* 
 * File:   MCP9701A.h
 * Author: Fabian
 *
 * Created on January 30, 2017, 4:24 PM
 */

#ifndef MCP9701A_H
#define	MCP9701A_H

#include <stdint.h>

/**
 * Converts a ADC value to an integer value representing the temperature
 * Doesn't handle temperatures below 0°C.
 * @param read The tension at the AD input (0°C=400mV, 19.5mV/°C, 4mV/LSB)
 * @return The corresponding temperature, rounded to the closest integer. For temperatures below 0°C returns 0, for 
 */
uint8_t temp_adToCelsius(adc_result_t read);

/**
 * Converts a the temperature to an integer value representing ADC value
 * @param read The desired temperature in °C
 * @return The corresponding value that would be read from the ADC for this temperature
 */
adc_result_t temp_celsiusToAd(uint8_t temp);

/**
 * Gets the temperature from temperature sensor A
 * @return An integer representing the temperature at sensor A (from 0 to 255)
 */
uint8_t temp_GetA();

/**
 * Gets the temperature from temperature sensor B
 * @return An integer representing the temperature at sensor B (from 0 to 255)
 */
uint8_t temp_GetB();

#endif	/* MCP9701A_H */

