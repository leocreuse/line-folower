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
#include "line.h"
#include "asserv.h"

#include "time.c"

#define VEL 255
#define DIF 127
#define TIME 500
#define MAX_CMD 255
#define TURN_CMD 128
long last_it=0;
long last_toggle = 0;
int cmd=0;
int turn_cmd;
int sens = 0;
dir last;
int target = 250;
int dist = 0;
int main(void){
        time_init();
	init_chassis();
	forward(VEL,sens);

	while(1){
	  if(millis() - last_it> 5){
	    last_it = millis();
	    dist = distance();
	    cmd = update_speed(target,dist,5.);
		printf("%ld,%d,%d\n",last_it,dist,target);
		if(cmd<0){
			cmd = -cmd;
			sens = 1;
		}
		else
			sens = 0;
		if(cmd >MAX_CMD){
			cmd = MAX_CMD;
		}
		forward(cmd,sens);
			if(sens ==1)
			forward(cmd,sens);
		else{
		  dir direction = get_dir();
		  if (direction == STOP){
		    direction = last;
		  }
		turn_cmd = cmd<TURN_CMD? cmd: TURN_CMD;
      		  if     (direction == LEFT)
				left(turn_cmd, turn_cmd/2);
		  else if(direction == RIGHT)
				right(turn_cmd, turn_cmd/2);
		  else if(direction == STRAIGHT)
			  forward(cmd,0);
		  last = direction;
		
	  }
	  }
	}

	return 0;
}
