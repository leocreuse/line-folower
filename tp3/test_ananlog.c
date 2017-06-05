#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include "uart.c"
#include <stdio.h>

#define bit_set(adress,bit)((adress)|=(1<<bit))
#define bit_clear(adress,bit) ((adress)&=~(1<<bit))
#define toggle_bit(adress,bit) ((adress)^=(1<<bit))
#define test_bit(adress,bit) ((adress>>(bit))&1)
int conversion();
int res;
int main(void){
  printf("booting...\n ok! \n");
  bit_set(PRR,PRADC);
  ADMUX=0b110;
  bit_set(ADCSRA,ADEN);
  while(1){
    res= conversion();
    printf("adc: %d\n",res);
    _delay_ms(333);
  }
  
}

int conversion(){
  bit_set(ADCSRA,ADSC);
  while(test_bit(ADCSRA,ADSC));
  return ((ADCH<<8)|ADCL);
}
