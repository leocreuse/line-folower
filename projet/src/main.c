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

//#include "time.c"

#define VEL 128
#define DIF 127
#define TIME 500

long last_it=0;
int cmd=0.;
int direction = 0;
int main(void){
	//time_init();
	init_chassis();
	forward(VEL,direction);

	while(1){

		cmd = update_speed(150,distance(),3.);
		printf("cmd: %d; distance : %d\n",cmd,distance());
		if(cmd<0){
			cmd = -cmd;
			direction = 1;
		}
		else
			direction = 0;
		if(cmd >255){
			cmd = 255;
		}
		_delay_ms(10);
		forward(cmd,direction);

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
