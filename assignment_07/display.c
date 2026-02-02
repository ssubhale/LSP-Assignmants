#include <stdio.h>


void Display(char *szStr)
{
    int iCount = 0;

    if(szStr == NULL)
    {
        return;
    }

    printf("String is : %s\n", szStr);

    while(szStr[iCount] != '\0')
    {
        iCount++;
    }

    printf("Total characters : %d\n", iCount);
}
