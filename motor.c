 /******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.c
 *
 * Description: Source file motor driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#include "motor.h"
#include "gpio.h"
#include "timer0.h"

void DcMotor_Init(void)
{
    // Set up the GPIO pins for the motor control
    GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_IN1_PIN, PIN_OUTPUT);
    GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_IN2_PIN, PIN_OUTPUT);
    GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_EN1_PIN, PIN_OUTPUT);
    Timer0_INIT_PWM();
}

void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
    // Set the motor direction based on the state
    switch (state)
    {
        case STOP:
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN1_PIN, LOGIC_LOW);
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN2_PIN, LOGIC_LOW);
            PWM_Timer0_Start(speed);
            break;

        case CW:
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN1_PIN, LOGIC_LOW);
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN2_PIN, LOGIC_HIGH);
            PWM_Timer0_Start(speed);
            break;

        case ACW:
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN1_PIN, LOGIC_HIGH);
            GPIO_writePin(MOTOR_PORT_ID, MOTOR_IN2_PIN, LOGIC_LOW);
            PWM_Timer0_Start(speed);
            break;
    }
}
