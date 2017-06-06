#ifndef SONAR_H
#define SONAR_H

#include <avr/io.h>
#include <avr/interrupts.h>
#include <util/delay.h>
#include "bit_control.h"


void init_sonar();//fonction de parametrage du sonar
int distance();//renvoie la distance à l'objet d'en face (unité arbitraire)

#endif
