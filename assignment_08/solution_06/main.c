#include <stdio.h>
#include "math.h"


int main(void)
{
    int iNo1, iNo2;

    printf("Enter two numbers : ");
    scanf("%d %d", &iNo1, &iNo2);

    printf("Addition : %d\n", Addition(iNo1, iNo2));
    printf("Subtraction : %d\n", Subtraction(iNo1, iNo2));
    printf("Multiplication : %d\n", Multiplication(iNo1, iNo2));
    printf("Division : %d\n", Division(iNo1, iNo2));

    return 0;
}

