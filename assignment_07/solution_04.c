#include <stdio.h>


int MyStrLen(char *);


int main(void)
{
    char szStr[100];

    printf("Enter string : ");
    scanf(" %[^\n]", szStr);

    printf("%s have %d characters\n", szStr, MyStrLen(szStr));

    return 0;
}

