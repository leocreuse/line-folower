#ifndef LINE_H
#define LINE_H
<<<<<<< HEAD

#include <avr/io.h>
#include <avr/interrupt>
#include <util/delay.h>
#include "bit_control.h"

static uint8_t tracking;
static uint8_t toggle;
static uint8_t old_PORTB;

void init_line();
int tracking();
=======
#include "bit_control.h"
#include <avr/io.h>
#include <stdbool.h>

>>>>>>> 5a223f74afc266a3c3c0635054715eec90ee470c


#endif
