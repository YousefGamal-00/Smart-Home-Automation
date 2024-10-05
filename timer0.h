 /******************************************************************************
 *
 * Module: Timer0
 *
 * File Name: timer0.h
 *
 * Description: Header file for the timer0 driver
 *
 * Author: Yousef Gamal 
 *
 *******************************************************************************/

#ifndef TIMER0_H
#define TIMER0_H

#include "std_types.h"

/*
 * based on the Follwing Equation choose the prescaler 
 *   CLK_IO / (256*CLK_OCN_PWM)
 * options : 
 *      0 -> Stop the timer
 *      1 -> CLK_IO
 *      2 -> prescaler 8 
 *      3 -> prescaler 64
 *      4 -> prescaler 256
 *      5 -> prescaler 1024
 */
#define PRESCALER  5    

/* Define if the mode is PWM or not */
#define IS_MODE_PWM 1


/* Define the required Timer mode */
#define OVERFLOW_MODE  0
#define COMPARE_MODE   2
#define FAST_PWM_MODE  3
#define TIMER0_MODE    FAST_PWM_MODE


/* Compare mode Configurations */
/* options :
 * 		0 -> OC0_DISCONNECTED
 * 		1 -> TOGGLE_OC0
 * 		2 -> CLEAR_OC0
 * 		3 -> Set_OC0
 */
#define OC0_COMPARE_NON_PWM  0

/* PWM mode Configurations */
/* options :
 * 		0 -> OC0_DISCONNECTED
 * 		2 -> OC0_NON_INVERTING
 * 		3 -> OC0_INVERTING
 */
#define OC0_COMPARE_PWM   2

/*
* Description :
* Function to initialize the timer0 when the timer operates with PWM mode
*/
void Timer0_INIT_PWM( void ) ;

/*
* Description :
* Function to initialize the timer0 when the timer operates with Overflow mode
*/

void Timer0_INIT_OVF( void ) ;
/*
* Description :
* Function to initialize the timer0 when the timer operates with Compare mode
*/

void Timer0_INIT_COMP( uint8 comp_value ) ;

/*
* Description :
* Function to Set the required duty cycle
*/
void PWM_Timer0_Start(uint8 duty_cycle) ;

/*
* Description :
* Function to Set the required compare value when the Timer operates with Compare mode
*/
void COMP_Timer0_Start(uint8 COMP_VAL) ;

#endif
