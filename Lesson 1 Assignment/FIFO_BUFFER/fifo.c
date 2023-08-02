/*
 * LIFO.c
 *
 *  Created on: ٢٩‏/٠٧‏/٢٠٢٣
 *      Author: Ali Mustafa Enaya
 */

#include "fifo.h"
FIFO_Status FIFO_enqueue_item (FIFO_Buf_t* fifo_buf ,element_type item )
{

	//check if fifo is valid
	if (!fifo_buf -> Base || !fifo_buf -> Head || !fifo_buf -> Tail)
		return FIFO_Null ;

	//check if lifo is full
	if (FIFO_Full(fifo_buf) == FIFO_full)
		return FIFO_full;

	//add new item
	*(fifo_buf->Head) = item ;
	fifo_buf->count++;

	//circular case
	if  (fifo_buf->Head == (fifo_buf->Base + (fifo_buf->length * sizeof(element_type))))
		fifo_buf->Head = fifo_buf->Base;
	else
		fifo_buf->Head++ ;


	return FIFO_no_error ;
}


FIFO_Status FIFO_dequeue_item (FIFO_Buf_t* fifo_buf , element_type* item )
{
	//check if fifo is valid
	if (!fifo_buf -> Base || !fifo_buf -> Head || !fifo_buf -> Tail)
		return FIFO_Null ;

	//check if fifo is empty
	if  (fifo_buf -> count == 0)
		return FIFO_empty;

	//getting an item
	*item = *(fifo_buf->Tail);
	fifo_buf->count--;

	//circular case
	if  (fifo_buf->Tail == (fifo_buf->Base + (fifo_buf->length * sizeof(element_type))))
		fifo_buf->Tail = fifo_buf->Base;
	else
		fifo_buf->Tail++ ;


	return FIFO_no_error ;

}

FIFO_Status FIFO_init(FIFO_Buf_t* fifo_buf , element_type* buf /*(my array)*/ , uint32_t length )
{
	//check if buf is null "if dynamic allocation"
	if(buf == NULL)
		return FIFO_Null ;
	//create a buf
	fifo_buf->Base = buf ;
	fifo_buf->Head = buf ;
	fifo_buf->Tail = buf ;
	fifo_buf -> count = 0 ;
	fifo_buf -> length = length ;
	return FIFO_no_error;


}

FIFO_Status FIFO_Full (FIFO_Buf_t* fifo_buf)
{
	if (!fifo_buf -> Base || !fifo_buf -> Head || !fifo_buf -> Tail)
		return FIFO_Null ;

	if  ( fifo_buf -> count == fifo_buf -> length )
		return FIFO_full;
}

void FIFO_Print (FIFO_Buf_t* fifo_buf)
{
	element_type* temp ;
	int i=0;

	if (fifo_buf -> count == 0)
		printf("====fifo is empty====");
	else
	{
		temp=fifo_buf->Tail;
		printf("====fifo_print====");
		for(i=0 ; i<fifo_buf->count ; i++)
		{
			printf("\n\t %X\n" , *temp);
			temp++;
		}
		printf("====================");

	}

}
