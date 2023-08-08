/*
 * US.h
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٣
 *      Author: metro
 */

#ifndef US_H_
#define US_H_
#include "state.h"


enum {
	US_busy
}US_State_id;

//functions declaration
void US_init();
State_define(US_busy);
int US_get_random_value(int , int);

//pointer to function
void (*US_state)();
#endif /* US_H_ */
