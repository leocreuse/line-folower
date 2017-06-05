#include "motor_control.h"

void init_motors(void){
        set_bit(TCCR0A, COM0A1);                // Set Timer for  Clearing OC01A on compare match
        set_bit(TCCR0A, WGM00);                 // Set PWM mode to Fast PWM
        set_bit(TCCR0A, WGM01);
        set_bit(TCCR0B, CS02);                  // Set clock prescaler

        set_bit(DDRD,PD5);                      // Set the pin D5 as output PWM2
	set_bit(DDRD,PD6);                      // Set the pin D6 as output PWM1

	set_bit(DDRD,PD4);			// Set the pin D4 as output Dir2
	set_bit(DDRD,PD7);			// Set the pin D7 as output Dir1

	OCR0A = 0;
	OCR0B = 0;

	set_bit(PORTD,PD4);
	set_bit(PORTD,PD7);
}

void set_lmotor(bool direction, uint8_t velocity){	// For now M1 is left motor
	if(direction)
		set_bit(PORTD,PD7);
	else
		clear_bit(PORTD,PD7);

	OCR0A = velocity;
}

void set_rmotor(bool  direction, uint8_t velocity){
	if(direction)
		set_bit(PORTD,PD4);
	else
		clear_bit(PORTD,PD4);

	OCR0B = velocity;
}
