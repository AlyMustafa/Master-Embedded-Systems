/*
 * task1.c
 *
 *  Created on: ٢١‏/١٢‏/٢٠٢٢
 *      Author: metro
 */

#include "stdio.h"
int main () {

	int m= 29;
	int* ab = &m ;
	printf ("Address of m : %p" , &m);
	printf ("\nValue of m : %d" , m);

	printf ("\nNow ab is assigned with the address of m.");


	printf ("\nAddress of pointer ab : %p" , ab);
	printf ("\nContent of pointer ab : %d" , *ab);

	m = 34;

	printf ("\nThe value of m assigned to 34 now.");

	printf ("\nAddress of pointer ab : %p" , ab);
	printf ("\nContent of pointer ab : %d" , *ab);

	*ab = 7;

	printf ("\nAddress of m : %p" , &m);
	printf ("\nValue of m : %d" , m);

return (0);
}
