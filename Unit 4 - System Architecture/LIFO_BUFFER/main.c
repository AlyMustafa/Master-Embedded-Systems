/*
 * main.c
 *
 *  Created on: ٢٩‏/٠٧‏/٢٠٢٣
 *      Author: metro
 */
#include "LIFO.h"
#include "stdio.h"
unsigned int Uart_buf[5];

void main() {
	int i,temp=0 ;
	LIFO_Buf_t UART_BUFFER ;
	lifo_init (&UART_BUFFER , Uart_buf,5);

	for (i= 0 ;i<5 ;i++ ){
		if (lifo_add_item (&UART_BUFFER, i) == LIFO_no_error)
			printf("UART_LIFO_add : %d \n" , i);
	}

	for (i= 0 ;i<5 ;i++ ){
		if (lifo_get_item(&UART_BUFFER, &temp) == LIFO_no_error)
			printf("\nUART_LIFO_get : %d \n" , temp);
	}

}

