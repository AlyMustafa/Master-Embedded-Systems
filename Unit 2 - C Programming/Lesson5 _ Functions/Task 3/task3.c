#include <stdio.h>

void reverse();

void main()
{
    printf("Enter a sentence: ");
    reverse();
}

void reverse()
{
    char c;
    setvbuf(stdout,NULL,_IONBF,0); setvbuf(stderr,NULL,_IONBF,0);
    scanf("%c", &c);
    if (c != '\n') {
        reverse();
        printf("%c", c);
    }
}
