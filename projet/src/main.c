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

#define VEL 96
#define DIF 20
#define TIME 500

int main(void){
	init_chassis();
	forward(VEL);

	while(1){
		
	}

	return 0;
}
