 /******************************************************************************
 *
 * Module: Flame sensor
 *
 * File Name: Flame_Sensor.h
 *
 * Description: Header file for Flame sensor driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

#include "std_types.h"

#define FLAME_SENSOR_PORT_ID  PORTD_ID
#define FLAME_SENSOR_PIN_ID   PIN2_ID

/*
* Discerption :  Initializes the flame sensor 
*/
void FlameSensor_init(void); 

/*
* Discerption : Reads the value from the flame sensor and returns it. 
*/
uint8 FlameSensor_getValue(void); 

#endif // FLAME_SENSOR_H
