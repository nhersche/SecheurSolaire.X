/**
  Generated Interrupt Manager Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.c

  @Summary:
    This is the Interrupt Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.26.1
        Device            :  PIC16F18856
        Driver Version    :  1.02
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

#include "interrupt_manager.h"
#include "mcc.h"

void __interrupt() INTERRUPT_InterruptManager (void)
{
    // interrupt handler
    if(INTCONbits.PEIE == 1 && PIE5bits.CLC2IE == 1 && PIR5bits.CLC2IF == 1)
    {
        CLC2_ISR();
    }
    else if(INTCONbits.PEIE == 1 && PIE8bits.SMT1PWAIE == 1 && PIR8bits.SMT1PWAIF == 1)
    {
        SMT1_PW_ACQ_ISR();
    }
    else if(INTCONbits.PEIE == 1 && PIE8bits.SMT1IE == 1 && PIR8bits.SMT1IF == 1)
    {
        SMT1_Overflow_ISR();
    }
    else if(INTCONbits.PEIE == 1 && PIE8bits.SMT1PRAIE == 1 && PIR8bits.SMT1PRAIF == 1)
    {
        SMT1_PR_ACQ_ISR();
    }
    else if(INTCONbits.PEIE == 1 && PIE1bits.ADIE == 1 && PIR1bits.ADIF == 1)
    {
        ADCC_ISR();
    }
    else if(INTCONbits.PEIE == 1 && PIE4bits.TMR2IE == 1 && PIR4bits.TMR2IF == 1)
    {
        TMR2_ISR();
    }
    else if(INTCONbits.PEIE == 1 && PIE8bits.SMT2IE == 1 && PIR8bits.SMT2IF == 1)
    {
        SMT2_Overflow_ISR();
    }
    else
    {
        //Unhandled Interrupt
    }
}
/**
 End of File
*/
