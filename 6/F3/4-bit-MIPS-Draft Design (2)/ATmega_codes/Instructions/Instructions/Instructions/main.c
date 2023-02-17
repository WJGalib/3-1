/*
 * Instructions.c
 *
 * Created: 12/2/2023 1:32:32 am
 * Author : Reyazul
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

uint16_t INSTRUCTIONS[1<<8] ={0x306f,
	0x3023,
	0x503e,
	0x6231,
	0xc234,
	0xd135,
	0x9323,
	0xd135,
	0x9323,
	0x1331,
	0xa341,
	0x21c0,
	0x0441,
	0xf334,
	0x5661,
	0x9620,
	0x5661,
	0x9630,
	0x21b0,
	0x8131,
	0x7531,
	0xf630,
	0x3661,
	0xb352,
	0xf620,
	0x3661,
	0x21c0,
0xe138};


int main(void)
{
	MCUCSR = (1<<JTD);  MCUCSR = (1<<JTD);

	DDRA = 0b00000000;	// input pc
	PORTA = 0xFF;

	// Instruction : D[0-7]C[0-7]
	DDRB = 0b11111111;	// lower 8-bits of instruction
	DDRC = 0b11111111;	// upper 8-bits of instruction

	uint8_t pc = -1;
	uint16_t instruction;
	while (1)
	{
		pc = PINA;
		instruction = INSTRUCTIONS[pc];
		PORTB = (uint8_t) instruction;
		PORTC = (uint8_t) (instruction >> 8);
		//_delay_ms(50);
		
	}
}

