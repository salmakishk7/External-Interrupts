#include <avr/io.h>
#include <avr/interrupt.h>

/********************** Global Variables *********************/

static char clk = 0;
static char centimeter_1st_digit = 0;
static char centimeter_2nd_digit = 0;
static char meter = 0;

/* External INT0 Interrupt Service Routine */
ISR(INT0_vect)
{
	 clk++; 		// every clock form the encoder increase the clk by one
	 if(clk == 4)	// 4 clk = 1 centimeter
	 {
		 clk = 0;
		 centimeter_1st_digit++;
	 }
	 if(centimeter_1st_digit == 10)
	 {
		 centimeter_1st_digit = 0;
		 centimeter_2nd_digit++;
	 }
	 if(centimeter_2nd_digit == 10)
	 {
	 	 centimeter_2nd_digit = 0;
	 	 meter++;
	 }

}

/* External INT0 enable and configuration function */
void INT0_Init(void)
{
	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}

/*  */

void SEG_INT(void)
{
	DDRC |= 0; // configure first four pins of PORTC as output pins
	DDRA |= 0; // configure first four pins of PORTC as output pins
	DDRB |= 0; // configure first four pins of PORTC as output pins

	PORTC &= 0xFF; // 2nd
	PORTA &= 0xFF; // 1st
	PORTB &= 0xFF; // 3rd
}


/* seg_pins_numbeer function take the actual number for seven segment and convert it into
 * the output pins for seven segment */
int seg_pins_number(int numb)
{
	if(numb == 0)
	{

	}
	else if(numb == 1)
	{

	}
	else if(numb == 2)
	{

	}
	else if(numb == 3)
	{

	}
	else if(numb == 4)
	{

	}
	else if(numb == 5)
	{

	}
	else if(numb == 6)
	{

	}
	else if(numb == 7)
	{

	}
	else if(numb == 8)
	{

	}
	else if(numb == 9)
	{

	}
}


int main(void)
{
	INT0_Init();              // Enable external INT0
	SEG_INT();				  // Enable 7 Seg pins
	

    while(1)
    {
    	PORTA = seg_pins_number(centimeter_1st_digit);
    	PORTC = seg_pins_number(centimeter_2nd_digit);
    	PORTB = seg_pins_number(meter);

	}					
}
