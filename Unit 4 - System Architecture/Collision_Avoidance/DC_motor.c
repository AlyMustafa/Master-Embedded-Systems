/*
 * US.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٣
 *      Author: metro
 */
#include "DC_motor.h"
unsigned int speed;
void DC_motor_init (){
	//init US sensor
	printf("DC_motor_init\n");
	DC_state = State(Idle);
}


void DC_motor_speed(int CA_speed) {
	speed = CA_speed;
	printf("CA ==> Dc_Motor : Speed = %d\t" ,speed );
	DC_state = State(Busy);
}



State_define(Idle){
	Dc_Motor_state_id = Idle;
	printf("DC_motor_Idle=====>Speed: %d\t\n" , speed);
	DC_state = State(Idle);
}


State_define(Busy){
	//define the state
	Dc_Motor_state_id = Busy;
	//set a speed =30 from DC_motor_speed(CA_speed )
	printf("DC_motor_Busy=====>Speed: %d\t\n" , speed);
	DC_state = State(Idle);

}
