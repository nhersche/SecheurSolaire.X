/* 
 * File:   display.h
 * Author: Fabian
 *
 * Created on January 31, 2017, 3:47 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

/**
 * Switches the displayed digit (digit 1/digit 2)
 * Shall be called at a frequency of at least 30Hz
 */
void disp_Update();

/**
 * Display is turned on
 */
void disp_TurnOn();

/**
 * Display is turned off
 */
void disp_TurnOff();

/**
 * Sets the displayed value
 * @param num An integer between 0 and 99 (higher numbers are truncated to 99)
 * @return The displayed number (0 to 99)
 */
uint8_t disp_SetInt(uint8_t num);

/**
 * Set the displayed value for the left digit (tens)
 * @param raw Value to be displayed
 */
void disp_SetRawLeft(char raw);

/**
 * Set the displayed value for the right digit (ones)
 * @param raw Value to be displayed
 */
void disp_SetRawRight(char raw);

/**
 * Controls the decimal point of the right digit
 * @param value Point will be turned on if true, otherwise turned off
 */
void disp_DecPointRight(bool value);

/**
 * Controls the decimal point of the left digit
 * @param value Point will be turned on if true, otherwise turned off
 */
void disp_DecPointLeft(bool value);

#endif	/* DISPLAY_H */

