#include "line.h"

bool follows_left(){
	return test_bit(PINB,PB1);
}

bool follows_right(){
	return test_bit(PINB,PB2);
}

dir get_dir(){
	if     (~follows_left && ~follows_right)
		return STRAIGHT;
	else if(~follows_left() &&  follows_right())
		return LEFT;
	else if( follows_left() && ~follows_right())
		return RIGHT;
	else
		return STOP;
}
