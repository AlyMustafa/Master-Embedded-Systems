/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: M E T R O
 */

#include "stdio.h"
void main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	float a[2][2];
	float b[2][2];
	float sum[2][2];
	int r,c;


	printf ("Enter The Elements of 1st Matrix\n");

	for(r=0 ; r<2 ; r++)
	{
		for(c=0 ; c<2 ; c++)
		{
			printf ("Enter a[%d][%d]: ",r+1,c+1);
			scanf("%f",&a[r][c]);
		}
	}

	printf ("Enter The Elements of 2nd Matrix\n");

	for(r=0 ; r<2 ; r++)
	{
		for(c=0 ; c<2 ; c++)
		{
			printf ("Enter b[%d][%d]: ",r+1,c+1);
			scanf("%f",&b[r][c]);
		}
	}

	for(r=0 ; r<2 ; r++)
	{
		for(c=0 ; c<2 ; c++)
		{
			sum[r][c]=a[r][c]+b[r][c];
		}
	}
	printf ("Sum of 2 matrix\n");
	for(r=0 ; r<2 ; r++)
	{
		for(c=0 ; c<2 ; c++)
		{
			printf (" %0.2f\t",sum[r][c]);
		}
		printf("\n");
	}
}
