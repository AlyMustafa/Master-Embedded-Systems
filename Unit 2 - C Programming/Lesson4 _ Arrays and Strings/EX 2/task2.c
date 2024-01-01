/*
 * task2.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Aly mustafa
 */
#include "stdio.h"
void main()
{
	setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);

	int n;
	printf("Enter The Number Of Data :");
	scanf("%d",&n);
	float x[n];
	int i;
	float sum=0 ;

	for(i=0 ; i<n ;i++)
	{
		printf("Enter The Number %d :", i+1);
		scanf("%f",&x[i]);
	}

	for(i=0 ; i<n ;i++)
	{
		sum= sum+x[i];
	}
	printf("Average = %f" , sum/n);
}
