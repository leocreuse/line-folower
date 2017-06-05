#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include "uart.c"
#include <stdio.h>

#define bit_set(adress,bit)((adress)|=(1<<bit))
#define bit_clear(adress,bit) ((adress)&=~(1<<bit))
#define bit_toggle(adress,bit) ((adress)^=(1<<bit))
#define test_bit(adress,bit) ((adress>>(bit))&1)
int conversion();
unsigned int res;
int main(void){
  printf("booting...\n ok! \n");
  bit_set(DDRD,PD6);
  bit_set(TCCR0A,COM0A1);
  bit_set(TCCR0A,WGM01);
  bit_set(TCCR0A,WGM00);
  TCCR0B=0;
  bit_set(TCCR0B,CS02);
  bit_set(DDRD,PD7);
  bit_set(PORTD,PORTD7);
  OCR0A=255;
  uint8_t val, input;
  while(1){
    scanf("%c",&input);
    printf("%c\n",input);
    switch(input){
    case '+':
      val +=10;
      break;
    case '-':
      val -=10;
      
    }
    }
     bit_toggle(PORTD,PD7);
  }
  
}
