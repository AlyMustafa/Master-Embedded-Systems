/*
 * Lab 1.c
 *
 * Created: 04/09/2023 05:12:33 م
 * Author : Metro
 */ 
#define F_CPU 8000000UL
#include "MemMap.h"
#include "Utils.h"
#include "avr/delay.h"

int main(void)
{
	int i=5;
    /* Replace with your application code */
    while (1) 
    {
		
		DDRD |= (0b111<<5); 
		for (i ; i<8 ; i++)
		{
			SetBit(PORTD,i);
			_delay_ms(300);
		}
		for (i=7 ; i>=5 ; i--)
		{
			ResetBit(PORTD,i);
			_delay_ms(300);
		}
		
		
    }
}

