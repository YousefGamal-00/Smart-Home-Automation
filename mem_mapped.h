 /******************************************************************************
 *
 *
 * File Name: mem_mapped.h
 *
 * Description: Header file for Mapped registers of AVR
 *
 * Author: Yousef Gamal 
 *
 *******************************************************************************/


#ifndef MEM_MAPPED_H
#define MEM_MAPPED_H

#include "std_types.h" 

#define DDRA_ADD        0X3A
#define DDRB_ADD        0X37
#define DDRC_ADD        0X34
#define DDRD_ADD        0X31
#define PORTA_ADD       0X3B
#define PORTB_ADD       0X38
#define PORTC_ADD       0X35
#define PORTD_ADD       0X32
#define PINA_ADD        0X39
#define PINB_ADD        0X36
#define PINC_ADD        0X33
#define PIND_ADD        0X30
#define MCUCR_ADD       0X55
#define GICR_ADD        0X5B
#define GIFR_ADD        0X5A
#define SFIOR_ADD       0X50
#define ADMUX_ADD       0X27
#define ADCSRA_ADD      0X26
#define ADCH_ADD        0X25
#define ADCL_ADD        0X24
#define TCCR0_ADD       0x53
#define TCNT0_ADD       0x52
#define  OCR0_ADD       0x5C 
#define TIMSK_ADD       0X59
#define  TIFR_ADD       0X58
#define  SREG_ADD       0X5F

#define SREG         (*( (volatile uint8 * const) (SREG_ADD))          )

#define DDRA         (*( (volatile uint8 * const) (DDRA_ADD))          )
#define DDRB         (*( (volatile uint8 * const) (DDRB_ADD))          )
#define DDRC         (*( (volatile uint8 * const) (DDRC_ADD))          )
#define DDRD         (*( (volatile uint8 * const) (DDRD_ADD))          )

#define PORTA         (*( (volatile uint8 * const) (PORTA_ADD) )       )
#define PORTB         (*( (volatile uint8 * const) (PORTB_ADD) )       )
#define PORTC         (*( (volatile uint8 * const) (PORTC_ADD) )       )
#define PORTD         (*( (volatile uint8 * const) (PORTD_ADD) )       )

#define PINA         (*( (volatile const uint8 * const) (PINA_ADD) )   )
#define PINB         (*( (volatile const uint8 * const) (PINB_ADD) )   )
#define PINC         (*( (volatile const uint8 * const) (PINC_ADD) )   )
#define PIND         (*( (volatile const uint8 * const) (PIND_ADD) )   )

#define TCCR0    	 ( *(volatile uint8 * const) (TCCR0_ADD)           )
#define TCNT0   	 ( *(volatile uint8 * const) (TCNT0_ADD)           )
#define OCR0   	     ( *(volatile uint8 * const) (OCR0_ADD )           )
#define TIMSK    	 ( *(volatile uint8 * const) (TIMSK_ADD)           )
#define TIFR     	 ( *(volatile uint8 * const) (TIFR_ADD )           )

#define ADMUX        ( * (volatile uint8 * const)        (ADMUX_ADD)   )
#define ADCSRA       ( * (volatile uint8 * const)        (ADCSRA_ADD)  )
#define SFIOR        ( * (volatile uint8 * const)        (SFIOR_ADD)   )
#define ADCH         ( * (volatile const uint8  * const) (ADCH_ADD)    )
#define ADCL         ( * (volatile const uint8  * const) (ADCL_ADD)    )
#define ADC          ( * (volatile const uint16 * const) (ADCL_ADD)    )

#define MCUCR        (*(volatile uint8* const)  (MCUCR_ADD)            )
#define GICR         (*(volatile uint8* const)  (GICR_ADD)             )
#define GIFR         (*(volatile uint8* const)  (GIFR_ADD)             )


#endif // MEM_MAPPED_H
