#define set_bit(adresse,bit) ((adresse)|=(0x1<<(bit)))
#define clear_bit(adresse,bit) ((adresse)&=(~(0x1<<(bit))))
#define toggle_bit(adresse,bit) ((adresse)^=(0x1<<(bit)))
#define test_bit(adresse,bit) ((adresse)=((adresse)>>(bit))&1)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
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

bool left_is_on_track(void){
	bool test=false;
	if(PINB1 == 1)
		test =true;
	return test;
}

bool right_is_on_track(void){
        bool test=false;
	if(PINB2 == 1)
		test=true;
        return test;
}

position get_pos(void){
	position pos = OUT;
	int state = (PINB & 0b110)>>1;
	if(state == 0b01)
		pos = RIGHT;
	if(state == 0b10)
		pos = LEFT;
	if(state == 0b11)
		pos = IN;
	return pos;
}


void toggle_led(){
        toggle_bit(PORTB,PORTB5);		// Toggle led state
}


ISR(PCINT0_vect){
        toggle_led();
	uart_putstring("ok");
}


int main(void){
	PCICR  |= (1<<PCIE0);			// Activation du registre d'autorisation
	PCMSK0 |= (1<<PCINT1)|(1<<PCINT2);	// Selection des pins  PB1 et PB2 pour les interrupts
	DDRB   |= (1<<DDB5);			// Set LED port as output
	sei();
	uart_putstring("Boot ok");
	while(1){
		
	};
	return 0;
}
