/*
 * task8.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: M E T R O
 */
#include <stdio.h>
#include <string.h>
void main()
{
	setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
	char x [30];
	char reverse [30]= {"ali"};
	int b;
	printf("Enter The string: ");
	gets(x);
	for ( b = 0 ; b < strlen(x) ; b++)
	{
		reverse[b] = x[strlen(x) - 1-b];
	}
	reverse[strlen(x)]='\0' ;
	printf ("Reverse String : %s" ,reverse);
}
