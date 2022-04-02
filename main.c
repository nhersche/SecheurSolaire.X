/* 
 * File:   main.h
 * Author: Fabian
 *
 * Created on January 30, 2017, 5:23 PM
 */

#include "main.h"

/**
 * PID_SETTINGS
 * Configuration values of PID.
 * TODO: Adjust Ti and Td
 */
PID_SETTINGS pid_params = {
    0,                  /* static gain K, calculated dynamically --> see constant PID_GAIN_MAX, line 97*/
    120,30,             /* integrative and derivative time Ti and Td*/
    0.1,                /* sampling step */
    5,                  /* derivative sensibility (usually 1<x<10) */
    1,                  /* set point proportional weight (usually 0<x<1) */
    1,                  /* set point derivative weight (usually 0<x<1) */
    1023,0              /* anti-windup values, control signal max/min */
};

// the desired temperature in °C (preserved by a value in EEPROM) and the corresponding value that would be read at the ADC module
uint8_t set_temp;
__eeprom uint8_t set_temp_eeprom = 40;// the start temperature after programming
adc_result_t set_point;

// holds the result of every new ADC conversion for the inside of the drier and the corresponding value in °C
adc_result_t read_point = 0;
uint8_t read_temp;

// holds the result of every new ADC conversion for the heater zone
adc_result_t read_hotAir = 0;

// holds the current mode
enum {
    MODE_SET, // used to set a new target temperature, target temp is displayed
    MODE_RUN  // the actual temperature is displayed
} mode = MODE_SET;

//holds the time of the last user input
cpu_time_t time_last_input; 

/**
 * Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    // initialize the PID controller
    pid_init(&pid_params);
    
    // TMR2 is used for multiplexing the two digits of the display, assign it's update function
    TMR2_SetInterruptHandler(disp_Update);

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    // set the channel for the ADC module
    ADCC_StartConversion(Temp_A);
    
    // the fan for the air circulation is always on, full speed
    // Todo: Adjust speed for air circulation (0-1023)
    fan_circ_speed(1023);
    
    // read the last temp from eeprom, calculate the value for the set_point
    set_temp = set_temp_eeprom;
    set_point = temp_celsiusToAd(set_temp);
    
    while (1)
    {        
        /**
         * If a new ADC conversion has finished, pass it to the PID controller
         * Update the fan speed with its output
         */
        if(read_hotAir){
            // reset adc_result, so it can hold the next conversion result
            adc_result_t temp = read_point,
                    hotAir = read_hotAir;
            read_hotAir = 0;
            
            /**
             * EXPERIMENTAL: calculate the gain for the PID with the difference
             * in temperature between the hot air channel and the temperature 
             * inside the drier. That way, if the temperature in the hot air 
             * channel is not high enough, the air flow is reduced, so that the
             * still can be heated.
             * The gain is also limited, it would start to oscillate if the gain
             * is too high. If the system starts to oscillate, reduce this
             * PID_GAIN_MAX
             * TODO: Adjust K (PID_GAIN_MAX)
             */
#define     PID_GAIN_MAX 10
            pid_params.K = (temp - hotAir) / 20.;
            if(pid_params.K > PID_GAIN_MAX) pid_params.K = PID_GAIN_MAX;
            else if(pid_params.K < -PID_GAIN_MAX) pid_params.K = -PID_GAIN_MAX;
            
            // update the fan speed with the new PID output
            // Don't write values below 10% duty cycle (not good for fan motor)
            uint16_t output = (uint16_t) pid_data(set_point, (float)temp);
            if(output < 100) output = 0;
            fan_hot_speed(output);
            
            // update the actual temperature in °C
            read_temp = temp_adToCelsius(temp);
        }
        
        // if any user input has occurred, process it
        if(ADJ_VALUE || OK_PRESSED || MENU_PRESSED){
            time_last_input = cpu_time_Get();
            
            // input occurred, change the set temperature
            if(ADJ_VALUE){
                mode = MODE_SET;
                
                set_temp += ADJ_VALUE;
                ADJ_VALUE = 0;

                // limit the value of the set temperature, between 10 and 80
                set_temp = (set_temp<10)?10:(set_temp>80)?80:set_temp;
            }
            
            //button has been pressed, switch mode
            else {
                OK_PRESSED = MENU_PRESSED = 0;
                
                switch(mode){
                    case MODE_SET:
                        // confirm the adjusted temperature, recalculate the setpoint
                        set_point = temp_celsiusToAd(set_temp);

                        // update the temperature in eeprom
                        set_temp_eeprom = set_temp;

                        mode = MODE_RUN;
                        break;
                        
                    case MODE_RUN:
                    default:
                        mode = MODE_SET;
                        break;
                }
            }
        }
        
        // either a button has been pressed or 10s have elapsed since the last user input -> accept the new temperature
        if(cpu_time_Diff(time_last_input) > 10000){
            // confirm the adjusted temperature, recalculate the setpoint
            set_point = temp_celsiusToAd(set_temp);
            
            // update the temperature in eeprom
            set_temp_eeprom = set_temp;
            
            mode = MODE_RUN;
        }
        
        // the display is handled
        switch(mode){
            case MODE_SET:
                disp_DecPointLeft(0);
                disp_DecPointRight(0);
                disp_SetInt(set_temp);
                if(cpu_time_Get() % 500 < 350)
                    disp_TurnOn();
                else
                    disp_TurnOff();
                break;
                
            case MODE_RUN:
            default:
                disp_TurnOn();
                disp_SetInt(read_temp);
                if(read_temp - set_temp > 2){
                    disp_DecPointLeft(1);
                    disp_DecPointRight(0);
                } else if(set_temp - read_temp > 2){
                    disp_DecPointLeft(0);
                    disp_DecPointRight(1);
                } else {
                    disp_DecPointLeft(0);
                    disp_DecPointRight(0);
                }
                break;
        }
    }
}

/**
 End of File
*/