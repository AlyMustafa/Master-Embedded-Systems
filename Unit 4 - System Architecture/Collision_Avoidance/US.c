/*
 * US.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٣
 *      Author: metro
 */

#include "US.h"

unsigned int distance;
extern void (*US_state)();

void US_init (){
	//init US sensor
	printf("US_sensor_init\n");
	US_state = State(US_busy);
}

//US_busy func
State_define(US_busy){

	US_State_id = US_busy;

	distance = US_get_random_value (45,55);
	US_distance_get(distance);
	printf("US_Busy_State : distance = %d\n" ,distance );
	US_state = State(US_busy);

}

//func to get randoms numbers
int US_get_random_value(int l, int r)
{
    return (rand() % (r - l + 1) + l);
}
