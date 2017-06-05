#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>

#include "bit_control.h"
#include "uart.c"
#include "motor_control.h"



int main(void){
	init_motors();

	set_lmotor(1,127);

	while(1){
	set_lmotor(0,127);
	_delay_ms(1000);
	set_lmotor(1,127);
	_delay_ms(1000);
	}

	return 0;
}
