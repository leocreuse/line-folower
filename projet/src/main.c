#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>

#include "bit_control.h"
#include "uart.c"
#include <stdio.h>
#include "sonar.h"
#include "chassis.h"
//#include "line.h"



#define VEL 96
#define DIF 20
#define TIME 750

int main(void){
	init_chassis();
        init_sonar();

	forward(VEL);

	while(1){
	  printf("%d\n",distance());
	forward(VEL);
	_delay_ms(TIME);
	left(VEL,DIF);
	_delay_ms(TIME);
	right(VEL,DIF);
	_delay_ms(TIME);
	}

	return 0;
}
