/**
  CLC2 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    clc2.h

  @Summary
    This is the generated header file for the CLC2 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for CLC2.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16F18856
        Driver Version    :  2.00
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

#ifndef _CLC2_H
#define _CLC2_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: CLC2 APIs
*/

/**
  @Summary
    Initializes the CLC2

  @Description
    This routine configures the CLC2 specific control registers

  @Preconditions
    None

  @Returns
    None

  @Param
    None

  @Comment
    

  @Example
    <code>
    CLC2_Initialize();
    </code>
*/
void CLC2_Initialize(void);

/**
  @Summary
    CLC2 Interrupt Service Routine

  @Description
    This is the CLC2 interrupt service routine called by the Interrupt Manager. Place your CLC2 interrupt code here.

  @Preconditions
    CLC2_Initialize() function should have been called before calling this function

  @Returns
    None

  @Param
    None

*/
void CLC2_ISR(void);
/**
  @Summary
    Returns output pin status of the CLC module.

  @Description
    This routine returns output pin status of the CLC module.

  @Param
    None.

  @Returns
    Output pin status
 
  @Example 
    <code>
    bool outputStatus;
    outputStatus = CLC2_OutputStatusGet();
    </code>
*/

bool CLC2_OutputStatusGet(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  // _CLC2_H
/**
 End of File
*/

