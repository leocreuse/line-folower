#include "chassis.h"
#define DIR 0

void init_chassis(void){
	init_motors();
	// M1 should be left motor
}

/*
	Velocities are coded as char
*/

void forward(uint8_t velocity){
	set_lmotor(DIR, velocity);
	set_rmotor(~DIR, velocity);
}

void left(uint8_t velocity, uint8_t differential){
	set_lmotor( DIR, velocity-differential);
	set_rmotor(~DIR, velocity+differential);
}

void right(uint8_t velocity, uint8_t differential){
        set_lmotor( DIR, velocity+differential);
        set_rmotor(~DIR, velocity-differential);
}

void stop(void){
	set_lmotor(0,0);
	set_rmotor(0,0);
}
