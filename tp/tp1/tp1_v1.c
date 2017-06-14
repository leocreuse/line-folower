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

int main(void){
	// Init
	uart_putstring("Boot ok...");
	DDRB = (1<<DDB5);
	// Main Loop
	while(1){
		PORTB &= 0;
		position current_pos = get_pos();
		if     (current_pos == LEFT)
			uart_putstring("LEFT");
		else if(current_pos == RIGHT)
			uart_putstring("RIGHT");
		else if(current_pos == IN){
			uart_putstring("IN");
			PORTB = (1<<PORTB5);
		}
		else
			uart_putstring("OUT");
		_delay_ms(250);
	}
	return 0;
}
