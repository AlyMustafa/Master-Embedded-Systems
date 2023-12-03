/*
 * Lab 2.c
 *
 * Created: 04/09/2023 05:45:16 م
 * Author : Metro
 */ 

#define F_CPU 8000000UL
#include "MemMap.h"
#include "Utils.h"

int main(void)
{
	int flag=0;
	ResetBit(DDRD,0);
	SetBit(DDRD,7);
	ResetBit(PORTD,0);

	ResetBit(PORTD,0);
    /* Replace with your application code */
    while (1) 
    {
		if(ReadBit(PIND,0) == 1 ){
			if (flag == 0)
			{
				ToggleBit(PORTD,7);
				flag++;
			}
			
		}
		else
		flag=0;
    }
}