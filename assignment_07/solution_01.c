#include <stdio.h>

extern int IsPerfect(int);


int main(void)
{
    int iNo = 0;
    int iRet = 0;

    printf("Enter number : ");
    scanf("%d", &iNo);

    iRet = IsPerfect(iNo);

    if (iRet == 1)
        printf("%d is perfect number\n", iNo);
    else
        printf("%d is not perfect number\n", iNo);
    
    return 0;
}

