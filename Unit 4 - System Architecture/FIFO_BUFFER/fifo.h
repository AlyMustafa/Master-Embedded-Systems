/*
 * fifo.h
 *
 *  Created on: ٣٠‏/٠٧‏/٢٠٢٣
 *      Author: metro
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

//user configuration

//select data type
#define element_type uint8_t

//width of array
#define width 5
element_type UART_BUFFER[width];

typedef struct {
	element_type* Base ;
	element_type* Head ;
	element_type* Tail ;
	uint32_t count;
	uint32_t length;

}FIFO_Buf_t;


// LIFO Status
typedef enum {
	FIFO_no_error,
	FIFO_full,
	FIFO_not_full,
	FIFO_empty,
	FIFO_not_empty,
	FIFO_Null,
}FIFO_Status;

//APIs
FIFO_Status FIFO_enqueue_item (FIFO_Buf_t* fifo_buf ,element_type item );
FIFO_Status FIFO_dequeue_item (FIFO_Buf_t* fifo_buf , element_type* item );
FIFO_Status FIFO_init(FIFO_Buf_t* fifo_buf , element_type* buf /*(my array)*/ , uint32_t length );
FIFO_Status FIFO_Full (FIFO_Buf_t* fifo_buf);
void FIFO_Print (FIFO_Buf_t* fifo_buf);


#endif /* FIFO_H_ */
