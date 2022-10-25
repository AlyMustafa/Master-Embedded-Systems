/*
 * task4.c
 *
 *  Created on: ٢٤‏/١٠‏/٢٠٢٢
 *      Author: metro
 */
#include <stdio.h>
struct smember
{
    int roll ;
    char name[100];
    int mark ;
};
void main() {
int i;
printf ("Enter Information of students\n");
struct smember data [10];
for (i=0 ; i<2 ; i++){
    printf ("Roll Number : ");
    setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
    scanf ("%d" , &data[i].roll);
    printf ("Enter Name : ");
    setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
    scanf ("%s" , &data[i].name);
    printf ("Enter Marks : ");
    setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
    scanf ("%d" , &data[i].mark);
    printf ("\t\t\t  \n");
}
printf ("####Displaying Information of students####\n");
for (i=0 ; i<2 ; i++){
    printf ("\nInformation for Roll Number : %d\n" , data[i].roll);
    printf ("Name : %s\n" , data[i].name);
    printf ("Marks : %d\n\n" , data[i].mark);
}
}
