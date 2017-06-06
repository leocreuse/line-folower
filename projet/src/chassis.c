#include "chassis.h"

void init_chassis(void){
	init_motors();
	// M1 should be left motor
}

/*
	Velocities are coded as char
*/

void forward(uint8_t velocity){
	bool set_dir = 0;
	set_lmotor(set_dir, velocity);
	set_rmotor(~set_dir, velocity);
}

void left(uint8_t velocity, uint8_t differential){
	bool set_dir = 0;
	set_lmotor(set_dir, velocity+differential);
	set_rmotor(~set_dir, velocity-differential);
}

void right(uint8_t velocity, uint8_t differential){
        bool set_dir = 0;
        set_lmotor(set_dir, velocity-differential);
        set_rmotor(~set_dir, velocity+differential);
}

void stop(void){
	set_lmotor(0,0);
	set_rmotor(0,0);
}
