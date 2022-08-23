/*
 * task 6 b.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Aly mustafa
 */

#include"stdio.h"
void main ()
{
	int a;
	int factorial = 1;
	printf("Enter an Integer : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
	if (a<=0)
	{
		if (a==0) printf ("Factorial = 1");
		else printf("Error!! Factorial of Negative Numbers doesn't exist");
	}
	else
	{
		for(int i=1 ; i<=a ;i++)
		{
			factorial*= i ;
		}
		printf("Factorial = %d" , factorial);
	}
}
