 /******************************************************************************
 *
 * Module: LDR sensor
 *
 * File Name: LDR.c
 *
 * Description: Source file for LDR sensor driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#include "LDR.h"
#include "adc.h"

uint8 LDR_getIntensity( void )
{
    uint8 intensity = 0 ;

    uint16 adc_value = 0 ;

    adc_value = ADC_readChannel (LDR_SENSOR_CHANNEL_ID);

    intensity = (uint8)((uint32)LDR_SENSOR_MAX_LIGHT_INTENSITY * adc_value * ADC_VREF_VALUE / (ADC_MAX_VALUE * LDR_SENSOR_MAX_VOLT));

    return intensity ;

}


