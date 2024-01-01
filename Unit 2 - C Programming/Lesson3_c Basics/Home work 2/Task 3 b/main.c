/*
 * main.c
 *
 *  Created on: ??ş/??ş/????
 *      Author:Aly Mustafa
 */
#include"stdio.h"
void main()
{
	float a,b,c ;
	printf("please Enter three Numbers:\n");
	fflush(stdin);   fflush(stdout);
	scanf("%f %f %f" , &a,&b,&c);
	if(a>b)
	{
		if(a>c) printf("Largest Num is %f", a);
		else printf("Largest Num is %f", c);
	}
	else if (b>a)
	{
		if(b>c) printf("Largest Num is %f" , b);
		else  printf("Largest Num is %f" , c);
	}
}

