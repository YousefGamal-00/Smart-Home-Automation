 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ADC driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#ifndef ADC_H
#define ADC_H

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAX_VALUE    1023
#define ADC_VREF_VALUE   2.56
/*
* options : 
    0 -> AREF
    1 -> AVCC
    3 -> internal 2.56
*/
#define Vref 3

/*
* options :
    1 -> prescaler 2
    2 -> prescaler 4
    3 -> prescaler 8
    4 -> prescaler 16
    5 -> prescaler 32
    6 -> prescaler 64
    7 -> prescaler 128
*/

#define ADC_prescaler 7


extern volatile uint16 Digital_value  ;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Discreption :
 * This Function initializes the ADC to operate with polling technique
 */
void ADC_init ( ) ;

/*
 * Discreption :
 * This Function returns the digital value of the required channel using polling technique
 */
uint16 ADC_readChannel ( uint8 Channel ) ;

/*
 * Discreption :
 * This Function returns the digital value of the required channel using interrupt technique
 */
void ADC_readChannel_INT ( uint8 Channel ) ;
#endif

