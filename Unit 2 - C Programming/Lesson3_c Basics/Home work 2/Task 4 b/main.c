/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Aly Mustafa
 */
#include"stdio.h"
void main()
{
	float x;
	printf("Please Enter your Number :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&x);
	if (x<=0)
	{
		if(x==0) printf("You Entered Zero");
		else printf("%f is a Negative Number",x);
	}
	else printf("%f is a Positive Number",x);
}
