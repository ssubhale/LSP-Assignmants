#include <stdio.h>
#include "helper.h"

int main()
{
    int iNo1, iNo2, iAns;

    printf("Enter two numbers: ");
    scanf("%d %d", &iNo1, &iNo2);

    iAns = Add(iNo1, iNo2);

    printf("Addition = %d\n", iAns);

    return 0;
}
