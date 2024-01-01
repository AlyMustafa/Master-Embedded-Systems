/*
 * task6.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: M E T R O
 */

#include "stdio.h"
void main()
{
	setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
	char string[30];
	char x;
	int counter = 0 ;
	printf("Enter The string :");
	gets(string);
	printf("Enter The Character to find frequency : ");
	scanf("%c" , &x);
	for (int i =0 ; i< strlen(string) ; i++)
	{
		if(string[i]== x)
		{
			counter++;
		}
	}
	printf("frequency of %c is %d" , x , counter);
}
