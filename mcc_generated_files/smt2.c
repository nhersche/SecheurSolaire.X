/**
  SMT2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    smt2.c

  @Summary
    This is the generated driver implementation file for the SMT2 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for SMT2.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16F18856
        Driver Version    :  1.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "smt2.h"

/**
  Section: SMT2 APIs
*/

void SMT2_Initialize(void)
{
    // WPOL high/rising edge enabled; STP rolls over to 24'h000000; SPOL high/rising edge enabled; SMT2EN enabled; SMT2PS 1:8 Prescaler; CPOL rising edge; 
    SMT2CON0 = 0x83;

    // REPEAT Repeat Data Acquisition; MODE Timer; SMT2GO disabled; 
    SMT2CON1 = 0x40;

    // SMT2CPWUP SMT2CPW2 update complete; SMT2CPRUP SMT2PR2 update complete; RST SMT2TMR2 update complete; 
    SMT2STAT = 0x00;

    // SMT2CSEL FOSC/4; 
    SMT2CLK = 0x00;

    // SMT2WSEL SMT2WINPPS; 
    SMT2WIN = 0x00;

    // SMT2SSEL SMT2SIGPPS; 
    SMT2SIG = 0x00;

    // SMT2PR 0; 
    SMT2PRU = 0x00;

    // SMT2PR 3; 
    SMT2PRH = 0x03;

    // SMT2PR 232; 
    SMT2PRL = 0xE8;

    // Enabling SMT2 overflow interrupt.
    PIE8bits.SMT2IE = 1;
    
    // Start the SMT module by writing to SMTxGO bit
    SMT2CON1bits.SMT2GO = 1;
    
}
        
void SMT2_DataAcquisitionEnable(void)
{
    // Start the SMT module by writing to SMTxGO bit
    SMT2CON1bits.SMT2GO = 1;
}

void SMT2_DataAcquisitionDisable(void)
{
    // Start the SMT module by writing to SMTxGO bit
    SMT2CON1bits.SMT2GO = 0;
}

void SMT2_HaltCounter(void)
{
    SMT2CON0bits.STP = 1;
}

void SMT2_SetPeriod(uint32_t periodVal)
{
    // Write to the SMT2 Period registers
    SMT2PRU = (periodVal >> 16);
    SMT2PRH = (periodVal >> 8);
    SMT2PRL = periodVal;
}

uint32_t SMT2_GetPeriod()
{
    return (SMT2PR);
}

void SMT2_SingleDataAcquisition(void)
{
    SMT2CON1bits.REPEAT = 0;
}

void SMT2_RepeatDataAcquisition(void)
{
    SMT2CON1bits.REPEAT = 1;
}

void SMT2_ManualPeriodBufferUpdate(void)
{
    SMT2STATbits.SMT2CPRUP = 1;
}

void SMT2_ManualPulseWidthBufferUpdate(void)
{
    SMT2STATbits.SMT2CPWUP = 1;
}

void SMT2_ManualTimerReset(void)
{
    SMT2STATbits.RST = 1;
}

bool SMT2_IsWindowOpen(void)
{
    return (SMT2STATbits.SMT2WS);
}

bool SMT2_IsSignalAcquisitionInProgress(void)
{
    return (SMT2STATbits.SMT2AS);
}

bool SMT2_IsTimerIncrementing(void)
{
    return (SMT2STATbits.SMT2TS);
}

uint32_t SMT2_GetCapturedPulseWidth()
{
    return (SMT2CPW);
}

uint32_t SMT2_GetCapturedPeriod()
{
    return (SMT2CPR);
}

uint32_t SMT2_GetTimerValue()
{
    return (SMT2TMR);
}

void SMT2_Overflow_ISR(void)
{
    extern void cpu_time_Update();
    cpu_time_Update();
    // Disabling SMT2 overflow interrupt flag bit.
    PIR8bits.SMT2IF = 0;
}
/**
 End of File
*/
