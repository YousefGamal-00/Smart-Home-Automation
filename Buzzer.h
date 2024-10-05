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


#ifndef BUZZER_H
#define BUZZER_H

#include "std_types.h"

#define BUZZER_PORT_ID  PORTD_ID
#define BUZZER_PIN_ID   PIN3_ID

/*
 * Description : Initializes the buzzer and turn of the Buzzer
 */
void Buzzer_init(void) ;

/*
 * Description : Activates the buzzer
 */
void Buzzer_on(void) ; 

/*
 * Description : De-activates the buzzer
 */
void Buzzer_off(void) ;  

#endif // BUZZER_H
