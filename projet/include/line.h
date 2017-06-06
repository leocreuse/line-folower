#ifndef LINE_H
#define LINE_H

#include <avr/io.h>
#include <avr/interrupt>
#include <util/delay.h>
#include "bit_control.h"

static uint8_t tracking;
static uint8_t toggle;
static uint8_t old_PORTB;

void init_line();
int tracking();


#endif
