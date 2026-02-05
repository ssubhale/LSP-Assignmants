#include <stdio.h>


int Addition(int, int);


int main(void)
{
    int iNo1, iNo2;

    printf("Enter two numbers : ");
    scanf("%d %d", &iNo1, &iNo2);

    printf("Addition is %d\n", Addition(iNo1, iNo2));

    return 0;
}


int Addition(int iNo1, int iNo2)
{
    return iNo1 + iNo2;
}

