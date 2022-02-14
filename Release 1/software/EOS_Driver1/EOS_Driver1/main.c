/*
 * main.c
 *
 * Created: 11/4/2021 9:51:41 AM
 *  Author: rsmit
 */ 

#include <xc.h>
#include "lib/TinyI2CMaster.h" 


volatile uint16_t time_now = 0;

void __interrupt(TIM1_COMPA_vect_num) isrTim1CompA(void)
{
	TCNT1 = 0;				// Reset counter value
	time_now++;
}

void delay_init(void)
{
	// Setup Timer1
	TCCR1B |= 0x02;				// Set clock prescaler to 8
	TCNT1 = 0;					// Reset counter value
	OCR1A = 100;				// Set compare register A
	TIMSK1 |= (1 << OCIE1A);		// Enable register A compare interrupt
}



int main(void)
{
	uint16_t time_delay = 0;
	
    // Set inputs and outputs
    DDRA |= (1 << PA0);
	DDRA |= (1 << PA2);
	DDRA &= ~(1 <<PA3);

	// Enable Global Interrupts
	SREG |= (1 << SREG_I);
	
	//delay_init();
	time_delay = 10000;
	
	
    while(1)
    {		
		//if (time_now >= (time_delay))
		//{
			//// Toggle PA0 and PA2 with XOR
			//PORTA ^= (1 << PA0);
			//if ((PINA & 0x08))
			//{
				//PORTA ^= (1 << PA2);
			//}
		// time_now = 0;
		//}
		
}
