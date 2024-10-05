 /******************************************************************************
 *
 * Module: LEDs
 *
 * File Name: LEd.c
 *
 * Description: Source file for LEDs driver
 *
 * Author: Yousef Gamal
 *
 *******************************************************************************/

#include "LED.h"
#include "gpio.h"  

// Initializes the LED driver, configures pins, and turns off all LEDs
void LEDS_init(void) 
{
    // Set direction as output and turn off all LEDs
    GPIO_setupPinDirection(LED_1_PORT_ID , LED_1_PIN_ID , PIN_OUTPUT) ;
    GPIO_setupPinDirection(LED_2_PORT_ID , LED_2_PIN_ID , PIN_OUTPUT) ;
    GPIO_setupPinDirection(LED_3_PORT_ID , LED_3_PIN_ID , PIN_OUTPUT) ;

    #if( LED_1_CONN_LOGIC == POS_LOGIC )
    GPIO_writePin(LED_1_PORT_ID , LED_1_PIN_ID , LOGIC_LOW ) ;
    #else
    GPIO_writePin(LED_1_PORT_ID , LED_1_PIN_ID , LOGIC_HIGH ) ;
    #endif

    #if( LED_2_CONN_LOGIC == POS_LOGIC )
    GPIO_writePin(LED_2_PORT_ID , LED_2_PIN_ID , LOGIC_LOW ) ;
    #else
    GPIO_writePin(LED_2_PORT_ID , LED_2_PIN_ID , LOGIC_HIGH ) ;
    #endif

    #if( LED_3_CONN_LOGIC == POS_LOGIC )
    GPIO_writePin(LED_3_PORT_ID , LED_3_PIN_ID , LOGIC_LOW ) ;
    #else
    GPIO_writePin(LED_3_PORT_ID , LED_3_PIN_ID , LOGIC_HIGH ) ;
    #endif

}

// Turns on the specified LED, based on its logic type
void LED_on(LED_ID id) 
{
    if( id == LED_RED)
    {
        #if( LED_1_CONN_LOGIC == POS_LOGIC )
        GPIO_writePin(LED_1_PORT_ID , LED_1_PIN_ID , LOGIC_HIGH ) ;
        #else
        GPIO_writePin(LED_1_PORT_ID , LED_1_PIN_ID , LOGIC_LOW ) ;
        #endif        
    }
    else if ( id == LED_GREEN)
    {
        #if( LED_2_CONN_LOGIC == POS_LOGIC )
        GPIO_writePin(LED_2_PORT_ID , LED_2_PIN_ID , LOGIC_HIGH ) ;
        #else
        GPIO_writePin(LED_2_PORT_ID , LED_2_PIN_ID , LOGIC_LOW ) ;
        #endif        

    }
    else if ( id == LED_BLUE )
    {
        #if( LED_3_CONN_LOGIC == POS_LOGIC )
        GPIO_writePin(LED_3_PORT_ID , LED_3_PIN_ID , LOGIC_HIGH ) ;
        #else
        GPIO_writePin(LED_3_PORT_ID , LED_3_PIN_ID , LOGIC_LOW ) ;
        #endif                
    }
}

// Turns off the specified LED, based on its logic type
void LED_off(LED_ID id) 
{
    if( id == LED_RED)
    {
        #if( LED_1_CONN_LOGIC == POS_LOGIC )
        GPIO_writePin(LED_1_PORT_ID , LED_1_PIN_ID , LOGIC_LOW ) ;
        #else
        GPIO_writePin(LED_1_PORT_ID , LED_1_PIN_ID , LOGIC_HIGH ) ;
        #endif        
    }
    else if ( id == LED_GREEN)
    {
        #if( LED_2_CONN_LOGIC == POS_LOGIC )
        GPIO_writePin(LED_2_PORT_ID , LED_2_PIN_ID , LOGIC_LOW ) ;
        #else
        GPIO_writePin(LED_2_PORT_ID , LED_2_PIN_ID , LOGIC_HIGH ) ;
        #endif        

    }
    else if ( id == LED_BLUE )
    {
        #if( LED_3_CONN_LOGIC == POS_LOGIC )
        GPIO_writePin(LED_3_PORT_ID , LED_3_PIN_ID , LOGIC_LOW ) ;
        #else
        GPIO_writePin(LED_3_PORT_ID , LED_3_PIN_ID , LOGIC_HIGH ) ;
        #endif                
    }
}
