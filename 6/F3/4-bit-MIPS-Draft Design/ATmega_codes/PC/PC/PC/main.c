/*
 * PC.c
 *
 * Created: 13/2/2023 10:05:50 am
 * Author : Reyazul
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int flag = 1;

//ISR(INT0_vect)
//{
//	if (flag==0)
//	{
//		flag = 1;
//	}
//	else
//		flag = 0;
//}



int main(void)
{
	uint8_t pc = -1;
	MCUCSR = (1<<JTD);  MCUCSR = (1<<JTD);

	DDRC = 0b00000000;	// input pc
	DDRB = 0b11111111;
	DDRA= 0b11111111;
	DDRD = 0;
	PORTC = 0b00000000;
	//GICR = 1<<INT0;
	//MCUCR = MCUCR | (1 << ISC01);  //falling edge of input interrupt
	//MCUCR = MCUCR & (~(1 << ISC00)); //ISC01 = 1, ISC00 = 0

	//sei();
	while (1)
	{
		if (PINC != pc && flag==1) {
			pc = PINC;
		}
		PORTB = pc;
		PORTA = pc;
		_delay_ms(1000);
		
	}
   
}

