#include  <avrio.h>
#include <avr/interrupts.h>

TCCR2A = 0;
TCCR2B = 3;
TIMSK2 = 1;
long time= 0;
sei();

ISR(TIMER2_OVF){
time++;
}
