 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ADC driver
 *
 * Author: Yousef Gamal 
 *
 *******************************************************************************/


#include "std_types.h"
#include "mem_mapped.h"
#include "common_macros.h"
#include <avr/interrupt.h>
#include "adc.h"
/*******************************************************************************
 *                      Global  Variables                                       *
 *******************************************************************************/
volatile uint16 Digital_Value = 0;


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init ( )
{

/*  set reference voltage and left adjustment */
	#if(Vref == 0)
	CLEAR_BIT(ADMUX , 6) ;
	CLEAR_BIT(ADMUX , 7) ;
	#elif(Vref == 1)
	SET_BIT(ADMUX , 6) ;
	CLEAR_BIT(ADMUX , 7) ;
	#else
	SET_BIT(ADMUX , 6) ;
	SET_BIT(ADMUX , 7) ;
	#endif


	CLEAR_BIT(ADMUX , 5);  /* Left adjustment for ADC */
    SET_BIT(ADCSRA , 7);   /* Enable the ADC circuits */

/* set the prescaler value */
	#if(ADC_prescaler == 1)
		SET_BIT(ADCSRA, 0);
		CLEAR_BIT(ADCSRA, 1);
		CLEAR_BIT(ADCSRA, 2);
	#elif(ADC_prescaler == 2)
		CLEAR_BIT(ADCSRA, 0);
		SET_BIT(ADCSRA, 1);
		CLEAR_BIT(ADCSRA, 2);
	#elif(ADC_prescaler == 3)
		SET_BIT(ADCSRA, 0);
		SET_BIT(ADCSRA, 1);
		CLEAR_BIT(ADCSRA, 2);
	#elif(ADC_prescaler == 4)
		CLEAR_BIT(ADCSRA, 0);
		CLEAR_BIT(ADCSRA, 1);
		SET_BIT(ADCSRA, 2);
	#elif(ADC_prescaler == 5)
		SET_BIT(ADCSRA, 0);
		CLEAR_BIT(ADCSRA, 1);
		SET_BIT(ADCSRA, 2);
	#elif(ADC_prescaler == 6)
		CLEAR_BIT(ADCSRA, 0);
		SET_BIT(ADCSRA, 1);
		SET_BIT(ADCSRA, 2);
	#elif(ADC_prescaler == 7)
		SET_BIT(ADCSRA, 0);
		SET_BIT(ADCSRA, 1);
		SET_BIT(ADCSRA, 2);
	#endif

    CLEAR_BIT(ADCSRA , 3); /* Clear the ADC interrupt Enable */
    CLEAR_BIT(ADCSRA , 5); /* Clear the auto trigger  Enable */
}

/*
 * Description :
 * This Function returns the digital value of the required channel
 */

uint16 ADC_readChannel ( uint8 Channel ) 
{
    Channel &= 0X07 ;                     /* Set the max value of channel to be 7 */
    ADMUX = (ADMUX & 0XE0) | (Channel) ;  /* insert the channel number in first 5-bits of ADMUX */
    SET_BIT(ADCSRA , 6) ;                 /* Start conversion */
    while( BIT_IS_CLEAR(ADCSRA , 4) ) ;   /* wait until the ADC end the conversion process */
    SET_BIT(ADCSRA , 4) ;                 /* clear the ADC flag */

    return ADC ;
}

ISR(ADC_vect)
{
    Digital_Value = ADC;
}

void ADC_readChannel_INT ( uint8 Channel )
{
    Channel &= 0X07 ;                     /* Set the max value of channel to be 7 */
    ADMUX = (ADMUX & 0XE0) | (Channel) ;  /* insert the channel number in first 5-bits of ADMUX */

    SET_BIT(ADCSRA , 3);     /* SET the ADC interrupt Enable */
    SET_BIT(ADCSRA , 6) ;    /* Start conversion */

    return ;
}
