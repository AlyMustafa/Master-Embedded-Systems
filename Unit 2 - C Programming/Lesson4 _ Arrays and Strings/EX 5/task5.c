/*
 * task5.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: M E T R O
 */
#include "stdio.h"
void main()
{
	setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
	int x[30];
	int num ;
	int i;
	int a;
	printf("Enter The Number of Elements :");
	scanf("%d" , &num);
	printf("Enter your Elements of Matrix :\n");
	for( i=0 ; i<num ; i++)
	{
		scanf("%d" , &x[i]);
	}
	printf("Enter The Elements to be Searched :");
	scanf("%d" , &a);
	for( i=0 ; i<num ; i++)
	{
		if (x[i]==a)
		{
			printf("Number Found in Location = %d" , i+1);
			break;
		}
	}

	if (i==num)
	{
		printf("Number Not Found ");
	}
}
