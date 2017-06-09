#include <avr/io.h> 
#include <avr/interrupt.h>

volatile long time = 0;

void time_init(){
TCCR2A = 0;
TCCR2B = 3;
TIMSK2 = 1;
sei();
}

ISR(TIMER2_OVF_vect){
time++;
}

long millis(){
	return time;
}
