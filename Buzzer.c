 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: Buzzer.h
 *
 * Description: Header file for the Buzzer driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#include "Buzzer.h"
#include "gpio.h"

void Buzzer_init(void) 
{
    /*  Set up the GPIO pin for the buzzer */
    GPIO_setupPinDirection(BUZZER_PORT_ID , BUZZER_PIN_ID , PIN_OUTPUT);
    GPIO_writePin(BUZZER_PORT_ID , BUZZER_PIN_ID , LOGIC_LOW);
}

void Buzzer_on(void) 
{
    /*  Turn on the buzzer */
    GPIO_writePin(BUZZER_PORT_ID , BUZZER_PIN_ID , LOGIC_HIGH); 
}

void Buzzer_off(void) 
{
    /* Turn off the buzzer */
    GPIO_writePin(BUZZER_PORT_ID , BUZZER_PIN_ID , LOGIC_LOW);

}
