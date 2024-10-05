 /******************************************************************************
 *
 * Module: LM35 Sensor
 *
 * File Name: LLM35_Sensor.h
 *
 * Description: Header file LM35 Sensor driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_PORT_ID 			  PORTA_ID
#define SENSOR_PIN_ID 			  PIN1_ID

#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150
#define SENSOR_MIN_TEMPERATURE    0

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 * return value from Zero to 150
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */


