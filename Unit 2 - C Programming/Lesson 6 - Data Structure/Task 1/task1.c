/*
 * task1.c
 *
 *  Created on: ٢٤‏/١٠‏/٢٠٢٢
 *      Author:Ali Mustafa
 */

#include <stdio.h>
struct Sstudent {
    char name[50];
    int roll;
    float mark;
} member ;

int main() {
printf ("Enter Information of students\n\n ");
printf ("Enter Name : ");

setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
gets(member.name);
printf ("Enter roll Number : ");

setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
scanf("%d" , &member.roll);
printf ("Enter Marks : ");

setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
scanf("%f" , &member.mark);
printf ("Displaying Information of students\n");
printf ("\nName : ");
puts (member.name);
printf ("Roll : %d\n" , member.roll);
printf ("Marks : %0.1f" , member.mark);
    return 0;
}
