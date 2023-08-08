/*
 * LIFO.h
 *
 *  Created on: ٢٩‏/٠٧‏/٢٠٢٣
 *      Author: metro
 */
#include "stdio.h"
#ifndef LIFO_H_
#define LIFO_H_

typedef struct {
	unsigned char* Base ;
	unsigned char* Head ;
	unsigned int count;
	unsigned int length;

}LIFO_Buf_t;


// LIFO Status
typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_not_full,
	LIFO_empty,
	LIFO_not_empty,
	LIFO_Null,
}LIFO_Status;

//APIs
LIFO_Status lifo_add_item (LIFO_Buf_t* lifo_buf , unsigned int item );
LIFO_Status lifo_get_item (LIFO_Buf_t* lifo_buf , unsigned int* item );
LIFO_Status lifo_init(LIFO_Buf_t* lifo_buf , unsigned int* buf /*(my array)*/ , unsigned int length );

#endif /* LIFO_H_ */
