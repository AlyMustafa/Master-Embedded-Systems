/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Aly Mustafa
 */
#include"stdio.h"
void main()
{
	float a ,b ,temp=0;
	printf("Enter value of a  ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b  ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&b);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping, value of a = %f\n",a);
	printf("After swapping, value of b = %f\n",b);
}

