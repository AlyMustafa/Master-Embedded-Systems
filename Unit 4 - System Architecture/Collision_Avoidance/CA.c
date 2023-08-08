/*
 * US.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٣
 *      Author: metro
 */
#include "CA.h"
extern void (*CA_state)();
unsigned int CA_speed;
unsigned int CA_threshold = 50;
unsigned int CA_distance;

void CA_init()
{
	printf("CA_init\n");
    CA_state = State(CA_Wating);
}

State_define(CA_Wating){
	CA_state_id = CA_Wating;
	printf("CA_Wating====>distance: %d ====>Speed: %d\t" ,CA_distance ,CA_speed);
	CA_speed=0;
	DC_motor_speed(CA_speed );

	CA_state = State(CA_Wating);
}

State_define(CA_Driving){

	CA_state_id = CA_Driving;
	CA_speed = 30;
	DC_motor_speed(CA_speed );
	printf("CA_Driving====>distance: %d ====>Speed: %d\t" ,CA_distance ,CA_speed);
	CA_state = State(CA_Driving);
}

void US_distance_get(int distance)
{
	CA_distance = distance;
	(CA_distance<=CA_threshold)?(CA_state = State(CA_Wating)):(CA_state = State(CA_Driving));
}


