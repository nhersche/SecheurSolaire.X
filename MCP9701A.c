/* 
 * File:   MCP9701A.h
 * Author: Fabian
 *
 * Created on January 30, 2017, 4:24 PM
 */

#include "mcc_generated_files/mcc.h"
#include "MCP9701A.h"

/**
 * Converts a ADC value to an integer value representing the temperature
 * Doesn't handle temperatures below 0°C.
 * @param read The tension at the AD input (0°C=400mV, 19.5mV/°C, 4mV/LSB)
 * @return The corresponding temperature, rounded to the closest integer. For temperatures below 0°C returns 0, for 
 */
uint8_t temp_adToCelsius(adc_result_t read){
    //handle temperatures below 0°C
    if (read < 100)
        return 0;
    
    //result will exceed the 255
    if (read > 1340)
        return UINT8_MAX;
    
    //subtract the offset for 0°C, do the division through 19.5mV/°C while rounding to the closest integer
    //the calculation is: ((read LSB * 4mV/LSB) - 400mV) * 2 + 1) / 39mV/°C
    uint8_t temp =  ((((read - 100) * 8) + 1) / 39);
    return temp;
}

/**
 * Converts a the temperature to an integer value representing ADC value
 * @param read The desired temperature in °C
 * @return The corresponding value that would be read from the ADC for this temperature
 */
adc_result_t temp_celsiusToAd(uint8_t temp){
    return (400 + temp * 19 + temp / 2) / 4;
}

/**
 * Gets the temperature from temperature sensor A
 * @return An integer representing the temperature at sensor A (from 0 to 255)
 */
uint8_t temp_GetA(){
    return temp_adToCelsius(ADCC_GetSingleConversion(Temp_A));
}

/**
 * Gets the temperature from temperature sensor B
 * @return An integer representing the temperature at sensor B (from 0 to 255)
 */
uint8_t temp_GetB(){
    return temp_adToCelsius(ADCC_GetSingleConversion(Temp_B));
}