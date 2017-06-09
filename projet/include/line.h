#ifndef LINE_H
#define LINE_H

#include <avr/io.h>
#include "bit_control.h"
#include <stdbool.h>

typedef enum {LEFT, STRAIGHT, RIGHT, STOP} dir;

bool follows_left();
bool follows_right();

dir get_dir();

#endif
