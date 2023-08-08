/*
 * US.c
 *
 *  Created on: ٠٧‏/٠٨‏/٢٠٢٣
 *      Author: metro
 */
#include "CA.h"
#include "US.h"
#include "DC_motor.h"

void setup ();

void main(){
	int i;
	setup ();
	for (i=0 ; i<10 ; i++){

		US_state();
		CA_state();
		DC_state();
	}

}
void setup (){
	US_init ();
	CA_init();
	DC_motor_init ();
}

