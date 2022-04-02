/* 
 * File:   display.c
 * Author: Fabian
 *
 * Created on January 31, 2017, 3:47 PM
 */

#include "main.h"

//is true when display is enabled
bool disp_On = false;

//value for each digit of the 7segment display
char disp_digit_1 = 0x00;
char disp_digit_2 = 0x00;

//the values for each digit to send to the display
//Bit 0: decimal point, Bit 1: Segment A, Bit 2: Segment B, ..., Bit 7: Segment G
char disp_digit_values[10] = {
    0x7E,   //0
    0x0C,   //1
    0xB6,   //2
    0x9E,   //3
    0xCC,   //4
    0xDA,   //5
    0xFA,   //6
    0x0E,   //7
    0xFE,   //8
    0xDE    //9
};

/**
 * Switches the displayed digit (digit 1/digit 2)
 * Shall be called at a frequency of at least 30Hz
 */
void disp_Update(){
    //if display is turned off do nothing
    if (disp_On){
        //digit 1 will be displaying
        if (AFF_1_LAT == false){
            AFF_2_SetLow();         //turn off digit two
            LATC = disp_digit_1;    //the value for digit 1 is sent to the display
            AFF_1_SetHigh();         //turn on digit one
        }
        //digit 2 will be displaying
        else {
            AFF_1_SetLow();         //turn off digit one
            LATC = disp_digit_2;    //the value for digit 2 is sent to the display
            AFF_2_SetHigh();         //turn on digit one
        }
    }
}

/**
 * Display is turned on
 */
void disp_TurnOn(){
    disp_On = true;
}

/**
 * Display is turned off
 */
void disp_TurnOff(){
    disp_On = false;
    AFF_1_SetLow();
    AFF_2_SetLow();
}

/**
 * Sets the displayed value
 * @param num An integer between 0 and 99 (higher numbers are truncated to 99)
 * @return The displayed number (0 to 99)
 */
uint8_t disp_SetInt(uint8_t num){
    //truncate num to 99
    if (num > 99)
        num = 99;
    
    //digit one is the remainder of 10 of the input, keep the decimal point
    disp_SetRawRight(disp_digit_values[num % 10]);
    //digit two is the input divided by ten (digit for the tens), keep the decimal point
    disp_SetRawLeft(disp_digit_values[num / 10]);
    return num;
}

/**
 * Set the displayed value for the left digit (tens)
 * @param raw Value to be displayed
 */
void disp_SetRawLeft(char raw){
    //set the value for the left digit while keeping the decimal point
    disp_digit_1 = (raw & 0xFE)  | (disp_digit_1 & 0x01);
}

/**
 * Set the displayed value for the right digit (ones)
 * @param raw Value to be displayed
 */
void disp_SetRawRight(char raw){
    //set the value for the left digit while keeping the decimal point
    disp_digit_2 = (raw & 0xFE)  | (disp_digit_2 & 0x01);
}

/**
 * Controls the decimal point of the right digit
 * @param value Point will be turned on if true, otherwise turned off
 */
void disp_DecPointRight(bool value){
    if(value)
        disp_digit_2 |= 0x01;
    else
        disp_digit_2 &= 0xFE;
}

/**
 * Controls the decimal point of the left digit
 * @param value Point will be turned on if true, otherwise turned off
 */
void disp_DecPointLeft(bool value){
    if(value)
        disp_digit_1 |= 0x01;
    else
        disp_digit_1 &= 0xFE;
}