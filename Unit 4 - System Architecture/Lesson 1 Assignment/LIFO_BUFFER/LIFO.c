/*
 * LIFO.c
 *
 *  Created on: ٢٩‏/٠٧‏/٢٠٢٣
 *      Author: Ali Mustafa Enaya
 */

#include "LIFO.h"
LIFO_Status lifo_add_item (LIFO_Buf_t* lifo_buf , unsigned int item )
{

	//check if lifo is valid
	if (!lifo_buf -> Base || !lifo_buf -> Head )
		return LIFO_Null ;
	//check if lifo is full
	if  (lifo_buf -> Head >= (lifo_buf -> Base + (lifo_buf -> length * sizeof(int))) )
		return LIFO_full;
	//add new item
	*(lifo_buf -> Head) = item ;
	lifo_buf -> Head++ ;
	lifo_buf -> count++;
	return LIFO_no_error ;
}


LIFO_Status lifo_get_item (LIFO_Buf_t* lifo_buf , unsigned int* item )
{
	//check if lifo is valid
	if (!lifo_buf -> Base || !lifo_buf -> Head )
		return LIFO_Null ;
	//check if lifo is empty
	if  (lifo_buf -> count == 0)
		return LIFO_empty;
	//getting an item
	lifo_buf -> Head-- ;
	*item = *(lifo_buf->Head) ;
	lifo_buf -> count--;

	return LIFO_no_error ;

}

LIFO_Status lifo_init(LIFO_Buf_t* lifo_buf , unsigned int* buf /*(my array)*/ ,unsigned int length )
{
	//check if buf is null "if dynamic allocation"
	if(buf == NULL)
		return LIFO_Null ;
	//create a buf
	lifo_buf->Base = buf ;
	lifo_buf->Head = buf ;
	lifo_buf -> count = 0 ;
	lifo_buf -> length = length ;
	return LIFO_no_error;


}
