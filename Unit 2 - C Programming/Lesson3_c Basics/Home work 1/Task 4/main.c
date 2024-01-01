/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: M E T R O
 */

#include "stdio.h"
void main ()
{
	float x ,y ,sum=0;
	printf("Enter two Numbers..\n");
	fflush(stdin); fflush(stdout);
	scanf ("%f %f",&x ,&y);
	sum =x * y ;
	printf("Product is %f",sum);
}
