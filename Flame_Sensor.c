 /******************************************************************************
 *
 * Module: Flame sensor
 *
 * File Name: Flame_Sensor.c
 *
 * Description: Source file for Flame sensor driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#include "Flame_Sensor.h"
#include "gpio.h"
#include "mem_mapped.h"
#include <util/delay.h>


void FlameSensor_init(void)
{
    /* configure the sensor pin as input */
    GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID , FLAME_SENSOR_PIN_ID , PIN_INPUT) ;
} 

uint8 FlameSensor_getValue(void)
{
    
    uint8 flameSensorValue = 0 ;

    flameSensorValue = GPIO_readPin( FLAME_SENSOR_PORT_ID , FLAME_SENSOR_PIN_ID )  ;

    return flameSensorValue ;
}

