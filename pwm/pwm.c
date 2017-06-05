#define set_bit(adresse,bit) ((adresse)|=(0x1<<(bit)))
#define clear_bit(adresse,bit) ((adresse)&=(~(0x1<<(bit))))
#define toggle_bit(adresse,bit) ((adresse)^=(0x1<<(bit)))
#define test_bit(adresse,bit) ((adresse)=((adresse)>>(bit))&1)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>
#include "uart.c"

int main(void){
	set_bit(DDRD,PD6);			// Set the pin D6 as output
	set_bit(TCCR0A, COM0A1);		// Set Timer for  Clearing OC01A on compare match
	set_bit(TCCR0A, WGM00);			// Set PWM mode to Fast PWM
	set_bit(TCCR0A, WGM01);
	set_bit(TCRR0B, CS02);			// Set clock prescaler

	OCR0A = 127;

	return 0;
}
