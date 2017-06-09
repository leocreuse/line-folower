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
#include "asserv.h"

#include "time.c"

#define VEL 128
#define DIF 127
#define TIME 500

int main(void){
	init_chassis();
	forward(VEL);

	while(1){
		dir direction = get_dir();
		if     (direction == LEFT)
			left(VEL, DIF);
		else if(direction == RIGHT)
			right(VEL, DIF);
		else if(direction == STRAIGHT)
			forward(VEL);
		_delay_ms(10);
	}

	return 0;
}
