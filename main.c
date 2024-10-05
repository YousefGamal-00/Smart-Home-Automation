#include "main.h"

int main ( void )
{
    uint8 LDR_intensity = 0 ;
    uint8 LM35_Temperature = 0 ;

    SET_BIT(SREG , 7) ; /* set the global interrupts enable */

    DcMotor_Init();
    ADC_init();
    LCD_init();
    Buzzer_init();
    FlameSensor_init();
    LEDS_init();

    LCD_displayStringRowColumn(0,0,"Fan is  ");
    LCD_displayStringRowColumn(1,0,"Temp=   LDR=    ");


    for(;;)
    {

        LDR_intensity = LDR_getIntensity() ;
        LM35_Temperature = LM35_getTemperature();
        /* Set the max Temperature to 99 */
        LM35_Temperature = (LM35_Temperature>99)? 99 : LM35_Temperature ;

        /* LEDs controller */
        if(LDR_intensity <= 15 )
        {
            LED_on( LED_RED   );
            LED_on( LED_GREEN );
            LED_on( LED_BLUE  );
        }
        else if (LDR_intensity <= 50)
        {
            LED_on ( LED_RED   );
            LED_on ( LED_GREEN );
            LED_off( LED_BLUE  );
        }
        else if (LDR_intensity <= 70)
        {
            LED_on ( LED_RED   );
            LED_off( LED_GREEN );
            LED_off( LED_BLUE  );
        }
        else
        {
            LED_off( LED_RED   );
            LED_off( LED_GREEN );
            LED_off( LED_BLUE  );
        }

        /* Fan controller */
        if(LM35_Temperature >= 40)
        {
            DcMotor_Rotate( CW , 100 );
        }
        else if (LM35_Temperature >= 35)
        {
            DcMotor_Rotate( CW , 75 );
        }
        else if (LM35_Temperature >= 30)
        {
            DcMotor_Rotate( CW , 50 );
        }
        else if (LM35_Temperature >= 25)
        {
            DcMotor_Rotate( CW , 25 );
        }
        else
        {
            DcMotor_Rotate( STOP , 0 );
        }

        LCD_moveCursor(1 , 5);
        LCD_intgerToString( (uint32) LM35_Temperature) ;
        LCD_displayStringRowColumn(1,7," ");
        if( LM35_Temperature < 25 )
        {
            LCD_displayStringRowColumn( 0 , 7 , "OFF" );
        }
        else
        {
            LCD_displayStringRowColumn( 0 , 7 , "ON " );
        }

        LCD_moveCursor(1,12);
        if(LDR_intensity == 100 )
        {
            LCD_intgerToString( (uint32)LDR_intensity ) ;
        }
        else
        {
            LCD_intgerToString( (uint32)LDR_intensity ) ;
            LCD_displayCharacter(' ');
        }
        LCD_moveCursor(1,15);
        LCD_displayCharacter('%');

        if (FlameSensor_getValue() )
        {
            LCD_clearScreen();
            LCD_displayString("Critical alert!");
            Buzzer_on();
            while (FlameSensor_getValue() );  /* wait until the flame is off */
            Buzzer_off();
            LCD_clearScreen() ;
            LCD_displayStringRowColumn(0,0,"Fan is  ");
            LCD_displayStringRowColumn(1,0,"Temp=   LDR=    ");
            LCD_moveCursor(1 , 5);
            LCD_intgerToString( (uint32) LM35_Temperature );
            LCD_moveCursor(1 , 12);
            LCD_intgerToString( (uint32) LDR_intensity );
            LCD_moveCursor(1 , 15);
            LCD_displayCharacter('%');


        }


    }
    return 0 ;
}
