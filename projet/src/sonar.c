#include "sonar.h"


void init_sonar(){
  TCCR1A = 0;
  TCCR1B = 3;
}

void distance(){
  int i = 0;
  bit_clear(PORTB,PORTB4);
  bit_set(DDRB,DDB4);
  printf("ping\n");
  _delay_us(2);
  bit_set(PORTB,PORTB4);
  _delay_us(10);
  bit_clear(PORTB,PORTB4);
  bit_clear(DDRB,DDB4);
  while(!test_bit(PINB,PINB4));
  TCNT1L=0;
  TCNT1H=0;
  while(test_bit(PINB,PINB4));
  TCCR1B=0;
  i= (TCNT1H<<8) | TCNT1L; 
  _delay_us(20);// augment if parasitic echo exists.
  TCCR1B=3;
  return i*2;

}
