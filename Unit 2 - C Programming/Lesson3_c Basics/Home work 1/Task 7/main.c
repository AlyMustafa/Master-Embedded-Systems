/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Aly Mustafa
 */
#include"stdio.h"
void main()
{
	int a;
	int b;
	int p=0;
	int n=0;
	printf ("please Enter a..");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
	printf ("please Enter b..");
	fflush(stdin); fflush(stdout);
	scanf("%d",&b);
	if(b>a)
	{
		p=b-a;
		a=a+p ;
		b=b-p;
		printf ("a = %d",a);
		printf ("\nb = %d",b);
	}
	else
	{
		n= a-b;
		a=a-n;
		b=b+n;
		printf ("a = %d",a);
		printf ("\nb = %d",b);
	}
}


