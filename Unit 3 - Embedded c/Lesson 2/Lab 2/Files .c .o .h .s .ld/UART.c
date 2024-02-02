#include "UART.h"
#define UART0DR *((volatile unsigned int* const) ((unsigned int*)0x101f1000))
void uart_send_string (unsigned char* P_to_string)
{
	while(*P_to_string != '\0')
	{
		UART0DR = (unsigned int)(*P_to_string);
		P_to_string++;
	}
}

