/*
 * US.h
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٣
 *      Author: metro
 */

#ifndef DC_motor_H_
#define DC_motor_H_
#include"state.h"


enum{
	Idle,
	Busy
}Dc_Motor_state_id;

State_define(Idle);
State_define(Busy);

void DC_motor_init();
void (*DC_state)();

#endif /* DC_motor_H_ */
