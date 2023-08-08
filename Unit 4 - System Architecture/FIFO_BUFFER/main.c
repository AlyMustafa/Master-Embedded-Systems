/*
 * main.c
 *
 *  Created on: ٣٠‏/٠٧‏/٢٠٢٣
 *      Author: metro
 */
#include "stdio.h"
#include "stdint.h"
#include "fifo.h"

void main() {
	element_type temp;
	int i;
	FIFO_Buf_t FIFO_UART ;
	if( FIFO_init (&FIFO_UART, UART_BUFFER, 5)  == FIFO_no_error)
		printf("===FIFO_init is Done===\n\n");
	else
		printf("===FIFO_init is Failed===\n");

	for (i= 0 ;i<5 ;i++ ){
		if (FIFO_enqueue_item(&FIFO_UART, i)  == FIFO_no_error)
			printf("UART_FIFO_enqueue : %d \n" , i);
		else
			printf("===FIFO_enqueue is Failed===");
	}

	FIFO_Print(&FIFO_UART);

	if (FIFO_dequeue_item(&FIFO_UART, &temp) == FIFO_no_error)
		printf("\nUART_FIFO_dequeue : %d \n" , temp);
	if (FIFO_dequeue_item(&FIFO_UART, &temp) == FIFO_no_error)
		printf("\nUART_FIFO_dequeue : %d \n" , temp);

	FIFO_Print(&FIFO_UART);

}




