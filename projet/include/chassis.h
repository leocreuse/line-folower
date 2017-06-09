#ifndef CHASSIS_H
#define CHASSIS_H
#include "bit_control.h"
#include "motor_control.h"

void init_chassis(void);

void forward(uint8_t velocity,int dire);

void left(uint8_t velocity, uint8_t differential);

void right(uint8_t velocity, uint8_t differential);

void stop(void);


#endif
