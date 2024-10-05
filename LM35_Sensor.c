 /******************************************************************************
 *
 * Module: LM35 Sensor
 *
 * File Name: LLM35_Sensor.c
 *
 * Description: Source file LM35 Sensor driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#include "LM35_Sensor.h"
#include "adc.h"
#include <avr/delay.h>

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void) /* return signed */
{
	uint8 tempreture_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel( SENSOR_CHANNEL_ID );

	/* Calculate the temperature from the ADC value*/
	tempreture_value = (uint8)( ((uint32) adc_value * SENSOR_MAX_TEMPERATURE * ADC_VREF_VALUE ) / (ADC_MAX_VALUE * SENSOR_MAX_VOLT_VALUE) );

	return (tempreture_value) ;
}

