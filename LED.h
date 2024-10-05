 /******************************************************************************
 *
 * Module: LEDs
 *
 * File Name: LEd.h
 *
 * Description: Header file for LEDs driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#ifndef LED_H
#define LED_H
#include "std_types.h"

/* LED configurations */
#define POS_LOGIC    1 
#define NEG_LOGIC    0

#define LED_1_PORT_ID       PORTB_ID
#define LED_1_PIN_ID        PIN5_ID
#define LED_1_CONN_LOGIC    POS_LOGIC

#define LED_2_PORT_ID       PORTB_ID
#define LED_2_PIN_ID        PIN6_ID
#define LED_2_CONN_LOGIC    POS_LOGIC

#define LED_3_PORT_ID       PORTB_ID
#define LED_3_PIN_ID        PIN7_ID
#define LED_3_CONN_LOGIC    POS_LOGIC

// LED ID enumeration for the Red, Green, and Blue LEDs
typedef enum 
{
    LED_RED,
    LED_GREEN,
    LED_BLUE
}  LED_ID ;


// Function prototypes
void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);

#endif // LED_DRIVER_H
