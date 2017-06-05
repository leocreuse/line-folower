#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H
#include <avr/io.h>
#include <stdbool.h>
#include "bit_control.h"

void init_motors(void);

void set_lmotor(bool direction, uint8_t velocity);

void set_rmotor(bool  direction, uint8_t velocity);


#endif
