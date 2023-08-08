/*
 * US.h
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٣
 *      Author: metro
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#define State_define(_state_id) void ST_##_state_id ()
#define State(_state_id) ST_##_state_id


void DC_motor_speed(int );
void US_distance_get(int);


#endif /*STATE_H_*/
