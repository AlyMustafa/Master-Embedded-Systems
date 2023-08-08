/*
 * CA.h
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٣
 *      Author: metro
 */

#ifndef CA_H_
#define CA_H_
#include"state.h"


enum {
	CA_Wating,
	CA_Driving
}CA_state_id;

State_define(CA_Wating);
State_define(CA_Driving);
void CA_init();
void (*CA_state)();



#endif /* CA_H_ */
