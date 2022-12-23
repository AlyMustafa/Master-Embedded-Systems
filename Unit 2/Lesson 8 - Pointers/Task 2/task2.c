/*
 * task2.c
 *
 *  Created on: ٢١‏/١٢‏/٢٠٢٢
 *      Author: ALY MUSTAFA ENAYA
 */

#include "stdio.h"
int main () {
	char a[26] ;
	char* ptr =a ;
	int i =0;
	printf ("The Alphabets are : \n");
	for (i ; i<26 ; i++)
	{
		*ptr = i+'A' ;
		printf ("%c \t" , *ptr);
		if (i==22) printf ("\n");
	}
	return (0);
}
