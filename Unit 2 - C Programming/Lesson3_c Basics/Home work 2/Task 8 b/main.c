/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: M E T R O
 */
#include "stdio.h"
void main ()
{
	float a , b ;
	char c ;
	printf("Enter Operator either + or - or * or / : ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&c);
	printf ("Enter Two Numbers : \n");
	fflush(stdin); fflush(stdout);
	scanf("%f  %f",&a,&b);
	float sum = a+b ;
	float sub = a-b ;
	float mul = a*b ;
	float div = a/b ;
	switch (c)
	{
	case '+' :
	{
		printf ("%f + %f = %f",a,b,sum);
	}
	break;
	case '*' :
	{
		printf ("%f * %f = %f",a,b,mul);
	}
	break;
	case '-' :
	{
		printf ("%f - %f = %f",a,b,sub);
	}
	break;
	case '/' :
	{
		printf ("%f / %f = %f",a,b,div);
	}
	break;
	}
}
