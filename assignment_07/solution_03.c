#include <stdio.h>


void Display(char *szStr);


int main(void)
{
    char str[100];

    printf("Enter string : ");
    scanf(" %[^\n]", str);

    Display(str);

    return 0;
}

