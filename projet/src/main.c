#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>

#include "bit_control.h"
#include "uart.c"
#include "chassis.h"

#define VEL 96
#define DIF 20
#define TIME 333

int main(void){
	init_chassis();

	forward(VEL);

	while(1){
	forward(VEL);
	_delay_ms(TIME);
	left(VEL,DIF);
	_delay_ms(TIME);
	right(VEL,DIF);
	_delay_ms(TIME);
	}

	return 0;
}
