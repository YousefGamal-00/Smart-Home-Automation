 /******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.h
 *
 * Description: Header file motor driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#ifndef MOTOR_H
#define MOTOR_H

#include "std_types.h"

#define  MOTOR_PORT_ID   PORTB_ID
#define  MOTOR_IN1_PIN   PIN0_ID
#define  MOTOR_IN2_PIN   PIN1_ID
#define  MOTOR_EN1_PIN   PIN3_ID

typedef enum 
{
    STOP ,
    CW   ,   
    ACW
}  DcMotor_State ;

/*
 * Description: Initializes the DC motor
 */
void DcMotor_Init(void);

/*
 *  Description: Controls the motor's state and adjusts the speed
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif // MOTOR_H
