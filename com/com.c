#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "uart.c"

#define  max(a,b) (((a)>(b))?(a):(b))

#define set_bit(adresse,bit) ((adresse)|(0x1<<(bit)))
#define clear_bit(adresse,bit) ((adresse)&(~(0x1<<(bit))))
#define toggle_bit(adresse,bit) ((adresse)^(0x1<<(bit)))
#define test_bit(adresse,bit) (((adresse)>>(bit))&1)

void uart_putstring(char* str){
	int i = 0;
	while(str[i]!='\0'){
		uart_putchar(str[i],NULL);
		i++;
	}
	uart_putchar('\n',NULL);
}

int main(void){
	while(1){
		char current_char=0;
		uart_putstring("Boot ok");
		while(current_char != 'A'){
			uart_putstring("Waiting for handshake");
			current_char = (char)uart_getchar(NULL);
			_delay_ms(500);
		};
		uart_putchar('B', NULL);
		uart_putchar('\n',NULL);
		uart_putstring("Handshake successful ... \n Press 's' to start");
		while(uart_getchar(NULL)!='s'){};
		_delay_ms(1000);
	}
	return 0;
}
