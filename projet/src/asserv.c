#include "asserv.h"

int update_speed(unsigned int target_distance, unsigned int current_distance, float gain){
	float epsilon = gain*(-target_distance + current_distance);
	return (int)(epsilon);
}
