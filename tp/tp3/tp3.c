#define set_bit(adresse,bit) ((adresse)|=(0x1<<(bit)))
#define clear_bit(adresse,bit) ((adresse)&=(~(0x1<<(bit))))
#define toggle_bit(adresse,bit) ((adresse)^=(0x1<<(bit)))
#define test_bit(adresse,bit) ((adresse)=((adresse)>>(bit))&1)

#define PORTUS PORTB4
#define DDBUS DDB4
#define PINBUS PINB4

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>
#include "uart.c"

typedef enum {IN, LEFT, RIGHT, OUT} position;


void uart_putstring(char* str){
        int i = 0;
        while(str[i]!='\0'){
                uart_putchar(str[i],NULL);
                i++;
        }
        uart_putchar('\n',NULL);
}

void toggle_led(){
        toggle_bit(PORTB,PORTB5);	// Toggle led state
}

//ISR(PCINT0_vect){}


int main(void){
	DDRB   = (1<<DDB5);

	uart_putstring("Boot ok");
	while(1){
		_delay_ms(500);
	};
	return 0;
}
