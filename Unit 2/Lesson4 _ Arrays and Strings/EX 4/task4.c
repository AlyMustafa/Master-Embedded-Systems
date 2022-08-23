/*
 * task4.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: M E T R O
 */
#include "stdio.h"
void main()
{
	setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
	int arr[20];
	int num;
	int add;
	int loc;
	printf ("Enter no of Elements :");
	scanf("%d" , &num);
	for(int i=0 ; i<num ;i++)
	{
		scanf ("%d", &arr[i]);
	}
	for(int i=0 ; i<num ;i++)
	{
		printf ("%d\t", arr[i]);
	}

	printf("\nEnter the Number to be Inserted :");
	scanf ("%d",&add);
	printf("\nEnter the Location :");
	scanf ("%d",&loc);
	num++;

	for(int i=num; i>=loc ;i--)
		{
			arr[i]=arr[i-1];
		}
	arr[loc-1]= add;

	for(int i=0 ; i<num ;i++)
	{
		printf ("%d\t", arr[i]);
	}
}
