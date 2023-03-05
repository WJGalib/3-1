/*
 * Data Memory.c
 *
 * Created: 13/2/2023 6:16:29 am
 * Author : Reyazul
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

//#define CLK_		0x04
#define RESET_		0x04
#define MEM_READ_	0x02
#define MEM_WRITE_	0x01

uint8_t MEMORY[1<<4] ;

void memory_reset() {
	for (int i=0; i<16; i++)
	MEMORY[i] = 0;
}


int main(void)
{
MCUCSR = (1<<JTD);  MCUCSR = (1<<JTD);

DDRA = 0b11111000;	// A[0] - Memory Write | A[1] - Memory Read  | A[2] - Reset
DDRB = 0x00;	// Address B[3:0] | Write Data B[7:4]

DDRC = 0xFF;	// C[3:0] - Data Read

memory_reset();

uint8_t current_control_input;
uint8_t current_write_data_address;
current_control_input = 0;
current_write_data_address = 0;


while (1)
{
if(	(current_control_input != (PINA & 0b00000111)) || (current_write_data_address != PINB)){
	current_control_input = PINA & 0b00000111;
	current_write_data_address = PINB;
	
	if (current_control_input & RESET_) {
		memory_reset();
		_delay_ms(50);
		continue;
		} 
		
	 if (current_control_input & MEM_WRITE_) {			

			MEMORY[current_write_data_address & 0x0F] = (current_write_data_address >> 4);
			_delay_ms(50);
			
		}
		//_delay_ms(50);
	
	if (current_control_input & MEM_READ_) {
		PORTC = MEMORY[current_write_data_address & 0x0F];
	}
	}
	
}
}


