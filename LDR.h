 /******************************************************************************
 *
 * Module: LDR sensor
 *
 * File Name: LDR.h
 *
 * Description: Header file for LDR sensor driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#ifndef LDR_H
#define LDR_H

#include "std_types.h"

#define LDR_SENSOR_MAX_VOLT                2.56
#define LDR_SENSOR_CHANNEL_ID              0  
#define LDR_SENSOR_MIN_LIGHT_INTENSITY     0
#define LDR_SENSOR_MAX_LIGHT_INTENSITY     100

/*
 * Description :
 * Function responsible for calculate the intensity from the ADC digital value.
 */
uint8 LDR_getIntensity( void );


#endif // LDR_H
