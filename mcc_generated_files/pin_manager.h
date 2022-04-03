/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.85.1
        Device            :  PIC16F18856
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set OUT_1 aliases
#define OUT_1_TRIS               TRISAbits.TRISA0
#define OUT_1_LAT                LATAbits.LATA0
#define OUT_1_PORT               PORTAbits.RA0
#define OUT_1_WPU                WPUAbits.WPUA0
#define OUT_1_OD                ODCONAbits.ODCA0
#define OUT_1_ANS                ANSELAbits.ANSA0
#define OUT_1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define OUT_1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define OUT_1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define OUT_1_GetValue()           PORTAbits.RA0
#define OUT_1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define OUT_1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define OUT_1_SetPullup()      do { WPUAbits.WPUA0 = 1; } while(0)
#define OUT_1_ResetPullup()    do { WPUAbits.WPUA0 = 0; } while(0)
#define OUT_1_SetPushPull()    do { ODCONAbits.ODCA0 = 1; } while(0)
#define OUT_1_SetOpenDrain()   do { ODCONAbits.ODCA0 = 0; } while(0)
#define OUT_1_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define OUT_1_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set OUT_2 aliases
#define OUT_2_TRIS               TRISAbits.TRISA1
#define OUT_2_LAT                LATAbits.LATA1
#define OUT_2_PORT               PORTAbits.RA1
#define OUT_2_WPU                WPUAbits.WPUA1
#define OUT_2_OD                ODCONAbits.ODCA1
#define OUT_2_ANS                ANSELAbits.ANSA1
#define OUT_2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define OUT_2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define OUT_2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define OUT_2_GetValue()           PORTAbits.RA1
#define OUT_2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define OUT_2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define OUT_2_SetPullup()      do { WPUAbits.WPUA1 = 1; } while(0)
#define OUT_2_ResetPullup()    do { WPUAbits.WPUA1 = 0; } while(0)
#define OUT_2_SetPushPull()    do { ODCONAbits.ODCA1 = 1; } while(0)
#define OUT_2_SetOpenDrain()   do { ODCONAbits.ODCA1 = 0; } while(0)
#define OUT_2_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define OUT_2_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA6 procedures
#define RA6_SetHigh()    do { LATAbits.LATA6 = 1; } while(0)
#define RA6_SetLow()   do { LATAbits.LATA6 = 0; } while(0)
#define RA6_Toggle()   do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define RA6_GetValue()         PORTAbits.RA6
#define RA6_SetDigitalInput()   do { TRISAbits.TRISA6 = 1; } while(0)
#define RA6_SetDigitalOutput()  do { TRISAbits.TRISA6 = 0; } while(0)
#define RA6_SetPullup()     do { WPUAbits.WPUA6 = 1; } while(0)
#define RA6_ResetPullup()   do { WPUAbits.WPUA6 = 0; } while(0)
#define RA6_SetAnalogMode() do { ANSELAbits.ANSA6 = 1; } while(0)
#define RA6_SetDigitalMode()do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set RA7 procedures
#define RA7_SetHigh()    do { LATAbits.LATA7 = 1; } while(0)
#define RA7_SetLow()   do { LATAbits.LATA7 = 0; } while(0)
#define RA7_Toggle()   do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define RA7_GetValue()         PORTAbits.RA7
#define RA7_SetDigitalInput()   do { TRISAbits.TRISA7 = 1; } while(0)
#define RA7_SetDigitalOutput()  do { TRISAbits.TRISA7 = 0; } while(0)
#define RA7_SetPullup()     do { WPUAbits.WPUA7 = 1; } while(0)
#define RA7_ResetPullup()   do { WPUAbits.WPUA7 = 0; } while(0)
#define RA7_SetAnalogMode() do { ANSELAbits.ANSA7 = 1; } while(0)
#define RA7_SetDigitalMode()do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set AFF_1 aliases
#define AFF_1_TRIS               TRISBbits.TRISB0
#define AFF_1_LAT                LATBbits.LATB0
#define AFF_1_PORT               PORTBbits.RB0
#define AFF_1_WPU                WPUBbits.WPUB0
#define AFF_1_OD                ODCONBbits.ODCB0
#define AFF_1_ANS                ANSELBbits.ANSB0
#define AFF_1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define AFF_1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define AFF_1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define AFF_1_GetValue()           PORTBbits.RB0
#define AFF_1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define AFF_1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define AFF_1_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define AFF_1_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define AFF_1_SetPushPull()    do { ODCONBbits.ODCB0 = 1; } while(0)
#define AFF_1_SetOpenDrain()   do { ODCONBbits.ODCB0 = 0; } while(0)
#define AFF_1_SetAnalogMode()  do { ANSELBbits.ANSB0 = 1; } while(0)
#define AFF_1_SetDigitalMode() do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set AFF_2 aliases
#define AFF_2_TRIS               TRISBbits.TRISB1
#define AFF_2_LAT                LATBbits.LATB1
#define AFF_2_PORT               PORTBbits.RB1
#define AFF_2_WPU                WPUBbits.WPUB1
#define AFF_2_OD                ODCONBbits.ODCB1
#define AFF_2_ANS                ANSELBbits.ANSB1
#define AFF_2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define AFF_2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define AFF_2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define AFF_2_GetValue()           PORTBbits.RB1
#define AFF_2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define AFF_2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define AFF_2_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define AFF_2_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define AFF_2_SetPushPull()    do { ODCONBbits.ODCB1 = 1; } while(0)
#define AFF_2_SetOpenDrain()   do { ODCONBbits.ODCB1 = 0; } while(0)
#define AFF_2_SetAnalogMode()  do { ANSELBbits.ANSB1 = 1; } while(0)
#define AFF_2_SetDigitalMode() do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()    do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()   do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()   do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()         PORTBbits.RB2
#define RB2_SetDigitalInput()   do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()  do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()     do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()   do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode() do { ANSELBbits.ANSB2 = 1; } while(0)
#define RB2_SetDigitalMode()do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set Temp_B aliases
#define Temp_B_TRIS               TRISBbits.TRISB4
#define Temp_B_LAT                LATBbits.LATB4
#define Temp_B_PORT               PORTBbits.RB4
#define Temp_B_WPU                WPUBbits.WPUB4
#define Temp_B_OD                ODCONBbits.ODCB4
#define Temp_B_ANS                ANSELBbits.ANSB4
#define Temp_B_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define Temp_B_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define Temp_B_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define Temp_B_GetValue()           PORTBbits.RB4
#define Temp_B_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define Temp_B_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define Temp_B_SetPullup()      do { WPUBbits.WPUB4 = 1; } while(0)
#define Temp_B_ResetPullup()    do { WPUBbits.WPUB4 = 0; } while(0)
#define Temp_B_SetPushPull()    do { ODCONBbits.ODCB4 = 1; } while(0)
#define Temp_B_SetOpenDrain()   do { ODCONBbits.ODCB4 = 0; } while(0)
#define Temp_B_SetAnalogMode()  do { ANSELBbits.ANSB4 = 1; } while(0)
#define Temp_B_SetDigitalMode() do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set Temp_A aliases
#define Temp_A_TRIS               TRISBbits.TRISB5
#define Temp_A_LAT                LATBbits.LATB5
#define Temp_A_PORT               PORTBbits.RB5
#define Temp_A_WPU                WPUBbits.WPUB5
#define Temp_A_OD                ODCONBbits.ODCB5
#define Temp_A_ANS                ANSELBbits.ANSB5
#define Temp_A_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define Temp_A_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define Temp_A_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define Temp_A_GetValue()           PORTBbits.RB5
#define Temp_A_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define Temp_A_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define Temp_A_SetPullup()      do { WPUBbits.WPUB5 = 1; } while(0)
#define Temp_A_ResetPullup()    do { WPUBbits.WPUB5 = 0; } while(0)
#define Temp_A_SetPushPull()    do { ODCONBbits.ODCB5 = 1; } while(0)
#define Temp_A_SetOpenDrain()   do { ODCONBbits.ODCB5 = 0; } while(0)
#define Temp_A_SetAnalogMode()  do { ANSELBbits.ANSB5 = 1; } while(0)
#define Temp_A_SetDigitalMode() do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()    do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()   do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()   do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()         PORTBbits.RB7
#define RB7_SetDigitalInput()   do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()  do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()     do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()   do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode() do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()    do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()   do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()   do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()         PORTCbits.RC3
#define RC3_SetDigitalInput()   do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()  do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()     do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()   do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode() do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()do { ANSELCbits.ANSC3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/