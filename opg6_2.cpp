
#include <avr/io.h> // Standard include for AVR

#define F_CPU 16000000UL // Crystal frequency required for delay functions

#include <util/delay.h> // Delay functions


#define sbi(x, y) x |= _BV(y)                // set bit - using bitwise OR operator
#define cbi(x, y) x &= ~(_BV(y))             // clear bit - using bitwise AND operator
#define tbi(x, y) x ^= _BV(y)                // toggle bit - using bitwise XOR operator
#define is_high(x, y) (x & _BV(y) == _BV(y)) // check if the yth bit of register 'x' is high



int main()
{
	DDRB = 0xff;  // PORTB as OUTPUT
	PORTB = 0x00; // All pins of PORTB LOW
	
	TCCR1A |= (1<<COM1A1) | (1<<WGM10);
	TCCR1B |= (1<<WGM12) | (1<<CS11);         //set clock / 8 prescaler0b00001010;
	OCR1A = 0;	
	

	while(1) // Infinite loop
	{
		//PORTB = 0b00000010;
		//_delay_ms(1000);  // Delay for 500 ms
		//PORTB = 0x00;
		//_delay_ms(10);  // Delay for 500 ms
		int a = 1;
		
		while(a == 1){
			OCR1A++;
			_delay_ms(10);
			if (OCR1A==200)
			{
				a = 0;
			}
		}
		
		while(a == 0){
			OCR1A--;
			_delay_ms(10);
			if (OCR1A==0)
			{
				a = 1;
			}
		}
		
		//tbi(PORTB, PD7); // the toggling takes place here
	}

	return 0;
}