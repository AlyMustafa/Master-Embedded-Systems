/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: Aly Mustafa
 */

#include"stdio.h"
void main ()
{
	int a;
	int sum=0;
	printf("Enter your integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
	for(int i=1; i<=a; i++)
	{
		sum=sum+i ;
	}
	printf("Sum = %d",sum);
}

