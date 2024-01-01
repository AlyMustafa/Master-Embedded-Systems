/*
 * Keypad.h
 *
 * Created: 13/09/2023 09:49:34 PM
 *  Author: Aly Enaya
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>

//rows & columns
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

//keypad connections
#define keypadPORT		PORTD
#define keypadPIN		PIND
#define keypadDDR		DDRD

//APIs
void keypad_init();
char keypad_get_key();

#endif /* KEYPAD_H_ */