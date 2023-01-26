/*
 * task2.c
 *
 *  Created on: ٢١‏/١٢‏/٢٠٢٢
 *      Author: ALY MUSTAFA ENAYA
 */
#include "stdio.h"
int main () {

	int a[15];
	int i=0;
	int *firstptr = a;
	printf ("Input the number of elements to store in the array (max 15) : ");
	int n;
	setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
	scanf("%d" , &n);
	int* lastptr = &a[n-1];
	printf ("Input %d number of elements in the array : \n" , n);
	for (i; i<n ;i++ )
	{
		printf ("element - %d : " , (i+1) );
		scanf("%d" , &(*firstptr));
		firstptr++;
	}
i=n;
printf ("The elements of array in reverse order are : \n");

	for (i; i>0 ;i-- )
	{
		printf ("element - %d : " , i);
		printf ("%d \n" , *lastptr );
		lastptr--;
	}

	return (0);
}
