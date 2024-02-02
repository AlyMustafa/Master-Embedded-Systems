/*
 * Ex3.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: M E T R O
 */


/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Aly Mustafa
 */

#include "stdio.h"
void main()
{
	setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);

	int r,c;
	int i,j;
	printf("Enter Rows & Columns of Matrix :\n");
	scanf("%d %d",&r,&c);
	float x[r][c];
	float y[c][r];
	printf("Enter The elements of  Matrix :\n");
	for(i=0 ; i<r ; i++)
	{
		for(j=0 ; j<c ;j++)
		{
			printf("Enter The element a[%d][%d] :", i+1,j+1);
			scanf("%f",&x[i][j]);
		}

	}

	printf("Entered Matrix :\n");

	for(i=0 ; i<r ; i++)
	{
		for(j=0 ; j<c ;j++)
		{
			printf("%0.2f\t",x[i][j]);
		}
		printf("\n");
	}
	printf("Transpose Matrix :\n");

	for(i=0 ; i<c ; i++)
	{
		for(j=0 ; j<r ;j++)
		{
			y[i][j] =x[j][i];
		}
	}

	for(i=0 ; i<c ; i++)
	{
		for(j=0 ; j<r ;j++)
		{
			printf("%0.2f\t",y[i][j]);
		}
		printf("\n");
	}
}
