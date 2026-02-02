#include <stdio.h>

int Addition(int, int);
int Subtraction(int, int);


int main(void)
{
    int iNo1;
    int iNo2;

    printf("Enter two numbers : ");
    scanf("%d %d", &iNo1, &iNo2);

    printf("Addition : %d\n", Addition(iNo1, iNo2));
    printf("Subtraction : %d\n", Subtraction(iNo1, iNo2));

    return 0;
}

