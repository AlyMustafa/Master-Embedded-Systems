/*
 * Keypad_Driver.c
 *
 * Created: 13/09/2023 07:34:07 PM
 * Author : Aly Enaya
 */ 

#include "Keypad.h"
typedef unsigned char uint8_t ;
 
uint8_t keypad_Rows[] = {R0 ,R1 ,R2 ,R3};
uint8_t keypad_Col[]  = {C0 ,C1 ,C2 ,C3};

void keypad_init(){
	//make R0->R3 input
	keypadDDR &=~( (1<<R0) | (1<<R1) | (1<<R2) | (1<<R3) );	
	//make C0->c3 Output and vcc
	keypadDDR |=  (1<<C0) | (1<<C1) | (1<<C2) | (1<<C3) ;
	keypadPORT = 0xFF; //to write on keypad_Col 1 and make raws pullup
	
}

char keypad_get_key(){
	int i,j;
	for ( i=0;i<4 ;i++)
	{
		keypadPORT |=  (1<<keypad_Col[0]) | (1<<keypad_Col[1]) | (1<<keypad_Col[2]) | (1<<keypad_Col[3]) ; //to make sure all columns is Vcc
		//_delay_ms(2000);
		keypadPORT &=~ (1 << keypad_Col[i]);// to send 0 to specific column
	
		for ( j=0 ; j<4 ;j++)
		{
			if (!(keypadPIN & (1<<keypad_Rows[j]))) //keypad_Rows[j] using for masking
			{
				while( !(keypadPIN & (1<<keypad_Rows[j])) );
				switch (i)
				{
				case (0) :
					{
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?'; /* ON/OFF button */
						break;
					}
				case(1):
					{
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
					}
				case(2):
					{
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					}
				case(3):
					{
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
					}
				}
			}
		}	
	}
	return 'A' ;			
}


