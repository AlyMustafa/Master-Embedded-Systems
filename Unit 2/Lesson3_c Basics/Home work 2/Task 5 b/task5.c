/*
 * task5.c
 *
 *  Created on: ??�/??�/????
 *      Author:Aly Mustafa
 */
#include"stdio.h"
void main ()
{
	char x ;
	printf("Enter a Character :");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);
	if ( (x>='a' && x<='z') || (x>='A' && x<='Z') )
			{
		printf("%c is an alphapet", x);
			}
	else printf ("%c is not an alphapet",x);
}
