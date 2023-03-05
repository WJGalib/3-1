/*
* Registers.c
*
* Created: 12/2/2023 1:27:48 pm
* Author : Reyazul
*/

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define WRITE_REG_	0x01
//#define CLK_		0x02
#define RESET_		0x02
//#define OUTPUT_		0x08

uint8_t REGISTER[8] = {0}; //all registers 0


int main(void)
{
	MCUCSR = (1<<JTD);  MCUCSR = (1<<JTD);

	DDRA = 0b00000000;	// A[3:0] - SrcReg1, A[7:4] - SrcReg2
	DDRB = 0b00000000;	// B[3:0] - DstReg, B[7:4] - Write Data

	DDRC = 0b11111111;	// C[3:0] - $1, C[7:4] - $2
	DDRD = 0b11111100;	// D[0] - WriteReg, D[1] - RESET
	//PORTA = 0xff;
	//PORTB = 0xff;
	uint8_t src, dst_data, current_control = 0x02;
	src = PINA; //src1,2
	dst_data = PINB;  //dstreg, writedata

	while (1)
	{
		if((current_control != (PIND&0b00000011)) || (dst_data != PINB) || (src != PINA)){
			current_control = PIND&0b00000011;
			src = PINA; //src1,2
			
			
			if ((current_control&RESET_)) {
				for (uint8_t i=0; i<8; i++) REGISTER[i] = 0;
				//_delay_ms(20);
				continue;
			}
			PORTC = (REGISTER[(src>>4)&0b00000111]<<4) | (REGISTER[src&0b00000111]);   //src reg 1 er value ar 2 er value copied
			
			//_delay_ms(200);
			dst_data = PINB;  //dstreg, writedata
			if ((current_control&WRITE_REG_)==0x01) {
				REGISTER[dst_data&0b00000111] = (dst_data>>4);  //write data on dst reg
				//PORTD = dst_data & 0b11111100;
				_delay_ms(20);
			}
			PORTC = (REGISTER[(src>>4)&0b00000111]<<4) | (REGISTER[src&0b00000111]);
			
		}
	}
	
	
}




