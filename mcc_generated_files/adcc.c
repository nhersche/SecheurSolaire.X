/**
  ADCC Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adcc.c

  @Summary
    This is the generated driver implementation file for the ADCC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  @Description
    This source file provides implementations for driver APIs for ADCC.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.26.1
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "adcc.h"
#include "mcc.h"

/**
  Section: ADCC Module APIs
*/

void ADCC_Initialize(void)
{
    // set the ADCC to the options selected in the User Interface
    // ADDSEN disabled; ADGPOL digital_low; ADIPEN disabled; ADPPOL VSS; 
    ADCON1 = 0x00;
    // ADCRS 0; ADMD Basic_mode; ADACLR disabled; ADPSIS ADFLTR; 
    ADCON2 = 0x00;
    // ADCALC First derivative of Single measurement; ADTMD disabled; ADSOI ADGO not cleared; 
    ADCON3 = 0x00;
    // ADACT TMR6; 
    ADACT = 0x08;
    // ADAOV ACC or ADERR not Overflowed; 
    ADSTAT = 0x00;
    // ADCCS FOSC/128; 
    ADCLK = 0x3F;
    // ADNREF VSS; ADPREF FVR; 
    ADREF = 0x03;
    // ADCAP 0; 
    ADCAP = 0x00;
    // ADPRE 0; 
    ADPRE = 0x00;
    // ADACQ 128; 
    ADACQ = 0x80;
    // ADPCH ANA0; 
    ADPCH = 0x00;
    // ADRPT 0; 
    ADRPT = 0x00;
    // ADLTHL 0; 
    ADLTHL = 0x00;
    // ADLTHH 0; 
    ADLTHH = 0x00;
    // ADUTHL 0; 
    ADUTHL = 0x00;
    // ADUTHH 0; 
    ADUTHH = 0x00;
    // ADSTPTL 0; 
    ADSTPTL = 0x00;
    // ADSTPTH 0; 
    ADSTPTH = 0x00;
    
    // ADGO stop; ADFM right; ADON enabled; ADCONT disabled; ADCS FRC; 
    ADCON0 = 0x94;
    
    // Clear the ADC interrupt flag
    PIR1bits.ADIF = 0;
    // Enabling ADCC interrupt.
    PIE1bits.ADIE = 1;

}

void ADCC_StartConversion(adcc_channel_t channel)
{
    // select the A/D channel
    ADPCH = channel;  
  
    // Turn on the ADC module
    ADCON0bits.ADON = 1;      

    // Start the conversion
    ADCON0bits.ADGO = 1;
}

bool ADCC_IsConversionDone()
{
    // Start the conversion
    return (!ADCON0bits.ADGO);
}

adc_result_t ADCC_GetConversionResult(void)
{
    // Return the result
    return ((ADRESH << 8) + ADRESL);
}

adc_result_t ADCC_GetSingleConversion(adcc_channel_t channel)
{
    // select the A/D channel
    ADPCH = channel;    

    // Turn on the ADC module
    ADCON0bits.ADON = 1;
	
    //Disable the continuous mode.
    ADCON0bits.ADCONT = 0;    

    // Start the conversion
    ADCON0bits.ADGO = 1;

    // Wait for the conversion to finish
    while (ADCON0bits.ADGO)
    {
    }

    // Conversion finished, return the result
    return ((ADRESH << 8) + ADRESL);
}

void ADCC_StopConversion(void)
{
	//Reset the ADGO bit.
	ADCON0bits.ADGO = 0;
}

void ADCC_SetStopOnInterrupt(void)
{
	//Set the ADSOI bit.
	ADCON3bits.ADSOI = 1;
}

void ADCC_DischargeSampleCapacitor(void)
{
	//Set the ADC channel to AVss.
	ADPCH = 0x3C;   
}

void ADCC_LoadAcquisitionRegister(uint8_t acquisitionValue)
{
	//Load the ADACQ register.
	ADACQ = acquisitionValue;   
}

void ADCC_SetPrechargeTime(uint8_t prechargeTime)
{
	//Load the ADPRE register.
	ADPRE = prechargeTime;  
}

void ADCC_SetRepeatCount(uint8_t repeatCount)
{
	//Load the ADRPT register.
	ADRPT = repeatCount;   
}

uint8_t ADCC_GetCurrentCountofConversions(void)
{
	//Return the contents of ADCNT register
	return ADCNT;
}

void ADCC_ClearAccumulator(void)
{
	//Reset the ADCON2bits.ADACLR bit.
	ADCON2bits.ADACLR = 1;
}

uint16_t ADCC_GetAccumulatorValue(void)
{
	//Return the contents of ADACCH and ADACCL registers
	return ((ADACCH << 8) + ADACCL);
}

bool ADCC_HasAccumulatorOverflowed(void)
{
	//Return the status of ADSTATbits.ADAOV
	return ADSTATbits.ADAOV;
}

uint16_t ADCC_GetFilterValue(void)
{
	//Return the contents of ADFLTRH and ADFLTRL registers
	return ((ADFLTRH << 8) + ADFLTRL);
}

uint16_t ADCC_GetPreviousResult(void)
{
	//Return the contents of ADPREVH and ADPREVL registers
	return ((ADPREVH << 8) + ADPREVL);
}

void ADCC_DefineSetPoint(uint16_t setPoint)
{
	//Sets the ADSTPTH and ADSTPTL registers
	ADSTPTH = setPoint >> 8;
	ADSTPTL = setPoint;
}

void ADCC_SetUpperThreshold(uint16_t upperThreshold)
{
	//Sets the ADUTHH and ADUTHL registers
	ADUTHH = upperThreshold >> 8;
	ADUTHL = upperThreshold;
}

void ADCC_SetLowerThreshold(uint16_t lowerThreshold)
{
	//Sets the ADLTHH and ADLTHL registers
	ADLTHH = lowerThreshold >> 8;
	ADLTHL = lowerThreshold;
}

uint16_t ADCC_GetErrorCalculation(void)
{
	//Return the contents of ADERRH and ADERRL registers
	return ((ADERRH << 8) + ADERRL);
}

void ADCC_EnableDoubleSampling(void)
{
	//Sets the ADCON1bits.ADDSEN
	ADCON1bits.ADDSEN = 1;
}

void ADCC_EnableContinuousConversion(void)
{
	//Sets the ADCON0bits.ADCONT
	ADCON0bits.ADCONT = 1;
}

void ADCC_DisableContinuousConversion(void)
{
	//Resets the ADCON0bits.ADCONT
	ADCON0bits.ADCONT = 0;
}

bool ADCC_HasErrorCrossedUpperThreshold(void)
{
	//Returns the value of ADSTATbits.ADUTHR bit.
	return ADSTATbits.ADUTHR;
}

bool ADCC_HasErrorCrossedLowerThreshold(void)
{
	//Returns the value of ADSTATbits.ADLTHR bit.
	return ADSTATbits.ADLTHR;
}

uint8_t ADCC_GetConversionStageStatus(void)
{
	//Returns the contents of ADSTATbits.ADSTAT field.
	return ADSTATbits.ADSTAT;
}


void ADCC_ISR(void)
{
    // Clear the ADCC interrupt flag
    PIR1bits.ADIF = 0;
    
    extern adc_result_t read_point, read_hotAir;
    
    // depending on which channel has been read take actions
    switch(ADPCH){
        case Temp_A:
            // temperature inside drier has been read
            read_point = ADCC_GetConversionResult();
            
            // start reading of temperature in the heater
            ADCC_StartConversion(Temp_B);
            break;
            
        case Temp_B:
            // temperature in the heater has been read
            read_hotAir = ADCC_GetConversionResult();
            
            // reset channel to read temperature in the drier
            ADPCH = Temp_A;
            break;
            
        default:
            ADCC_StartConversion(Temp_A);
            break;
    }
}

/**
 End of File
*/
