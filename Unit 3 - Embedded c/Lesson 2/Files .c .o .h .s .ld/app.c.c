#include "UART.h"

unsigned char string_buffer[100] = "Aly-Mustafa-Enaya" ;

void main(void){
	uart_send_string (string_buffer);
	
}