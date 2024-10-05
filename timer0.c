 /******************************************************************************
 *
 * Module: Timer0
 *
 * File Name: timer0.c
 *
 * Description: Source file for the timer0 driver
 *
 * Author: Yousef Gamal 
 *
 *******************************************************************************/

#include "gpio.h"
#include "std_types.h"
#include "avr/io.h"
#include "common_macros.h"
#include <avr/interrupt.h>
#include "timer0.h"

#if (TIMER0_MODE == OVERFLOW_MODE)

ISR(TIMER0_OVF_vect)
{
	/* Add the functionality of ISR */
}
void Timer0_INIT_OVF( void )
{
	SET_BIT(TCCR0, 7);  // Ensure we clear the FOC0 bit for Non PWM mode
	CLEAR_BIT(TCCR0 , 6) ;
	CLEAR_BIT(TCCR0 , 3) ;

	#if (PRESCALER == 0)
	CLEAR_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif(PRESCALER == 1)
	SET_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif (PRESCALER == 2)
	CLEAR_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif (PRESCALER == 3)
	SET_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif (PRESCALER == 4)
	CLEAR_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	#elif (PRESCALER == 5)
	SET_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	#endif
    // Initialize timer and output compare register
    TCNT0 = 0;  // Reset timer count
    OCR0 = 0;   // Start with 0% duty cycle

    CLEAR_BIT( TIMSK , 1 ); /* clear compare mode interrupt enable */
      SET_BIT( TIMSK , 0 ); /* Set overflow mode interrupt enable */

}
#elif (TIMER0_MODE == COMPARE_MODE)

ISR(TIMER0_COMP_vect)
{
	/* Add the functionality of ISR */
}
void Timer0_INIT_COMP( uint8 comp_value )
{
	SET_BIT(TCCR0, 7);  // Ensure we clear the FOC0 bit for Non PWM mode
	CLEAR_BIT(TCCR0 , 6) ;
	SET_BIT(TCCR0 , 3) ;

	// Adjust the OC0 PIN
	#if(OC0_COMPARE_NON_PWM == 0)
	CLEAR_BIT(TCCR0, 4);
	CLEAR_BIT(TCCR0, 5);
	#elif(OC0_COMPARE_NON_PWM == 1)
	SET_BIT(TCCR0, 4);
	CLEAR_BIT(TCCR0, 5);
	#elif(OC0_COMPARE_NON_PWM == 2)
	CLEAR_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);
	#else
	SET_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);
	#endif

	#if (PRESCALER == 0)
	CLEAR_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif(PRESCALER == 1)
	SET_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif (PRESCALER == 2)
	CLEAR_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif (PRESCALER == 3)
	SET_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif (PRESCALER == 4)
	CLEAR_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	#elif (PRESCALER == 5)
	SET_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	#endif
    // Initialize timer and output compare register
    TCNT0 = 0;  // Reset timer count
    OCR0 = comp_value;   // Set the compare Value

	// Disable interrupts for compare and overflow
      SET_BIT( TIMSK , 1 ); /* clear compare mode interrupt enable */
    CLEAR_BIT( TIMSK , 0 ); /* clear overflow mode interrupt enable */

}

void COMP_Timer0_Start(uint8 COMP_VAL) 
{
    OCR0 = COMP_VAL ;  /* Add the compare value for the timer */

}

#elif (TIMER0_MODE == FAST_PWM_MODE)
void Timer0_INIT_PWM(void)
{

	CLEAR_BIT(TCCR0, 7);  // Ensure we clear the FOC0 bit for PWM mode
	TCCR0 |= (1<<3) | (1<<6) ; // Timer0 operates in Fast PWM mode

	// Adjust the OC0 PIN
	#if(OC0_COMPARE_PWM == 0)
	CLEAR_BIT(TCCR0, 4);
	CLEAR_BIT(TCCR0, 5);
	#elif(OC0_COMPARE_PWM == 2)
	CLEAR_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);
	#else
	SET_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);
	#endif

	#if (PRESCALER == 0)
	CLEAR_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif(PRESCALER == 1)
	SET_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif (PRESCALER == 2)
	CLEAR_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif (PRESCALER == 3)
	SET_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	CLEAR_BIT(TCCR0, 2);
	#elif (PRESCALER == 4)
	CLEAR_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	#elif (PRESCALER == 5)
	SET_BIT(TCCR0, 0);
	CLEAR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	#endif
    // Initialize timer and output compare register
    TCNT0 = 0;  // Reset timer count
    OCR0 = 0;   // Start with 0% duty cycle

	// Disable interrupts for compare and overflow
    CLEAR_BIT(TIMSK, OCIE0); // Clear compare mode interrupt enable
    CLEAR_BIT(TIMSK, TOIE0); // Clear overflow mode interrupt enable

    // Set the OC0 pin as output (usually PB3 on ATmega series)
    GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);
}

void PWM_Timer0_Start(uint8 duty_cycle)
{
    // Set duty cycle (0-100%) to OCR0
    OCR0 = (duty_cycle * 2.55);
}

#endif
