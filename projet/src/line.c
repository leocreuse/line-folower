#include "line.h"

bool follows_left(){
	return test_bit(PINB,PB1);
}

bool follows_right(){
	return test_bit(PINB,PB2);
}
