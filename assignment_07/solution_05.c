#include <stdio.h>
#include "mystring.h"
#include "mymath.h"


int main(void)
{
    int iChoice1 = 0;
    int iChoice2 = 0;

    char szStr1[100], szStr2[100];
    int iNumber;
    double dNo;
    int iNo1, iNo2;

    do
    {
        printf("\n==== MAIN MENU ====\n");
        printf("1. String Functions\n");
        printf("2. Math Functions\n");
        printf("0. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &iChoice1);

        // ---------------- STRING MENU ----------------
        if (iChoice1 == 1)
        {
            printf("\n---- STRING MENU ----\n");
            printf("1. Mystrlen\n");
            printf("2. Mystrcpy\n");
            printf("3. Mystrncpy\n");
            printf("4. Mystrcat\n");
            printf("5. Mystrcmp\n");
            printf("6. Mystrncmp\n");
            printf("7. Mystrrev\n");
            printf("8. Mystrstr\n");
            printf("Enter choice : ");
            scanf("%d", &iChoice2);

            switch (iChoice2)
            {
                case 1:
                    printf("Enter string : ");
                    scanf("%s", szStr1);
                    printf("Length = %d\n", Mystrlen(szStr1));
                    break;

                case 2:
                    printf("Enter source string : ");
                    scanf("%s", szStr2);
                    Mystrcpy(szStr1, szStr2);
                    printf("Copied string = %s\n", szStr1);
                    break;

                case 3:
                    printf("Enter source string : ");
                    scanf("%s", szStr2);
                    printf("Enter number : ");
                    scanf("%d", &iNumber);
                    Mystrncpy(szStr1, szStr2, iNumber);
                    szStr1[iNumber] = '\0';
                    printf("Result = %s\n", szStr1);
                    break;

                case 4:
                    printf("Enter first string : ");
                    scanf("%s", szStr1);
                    printf("Enter second string : ");
                    scanf("%s", szStr2);
                    Mystrcat(szStr1, szStr2);
                    printf("Concatenated = %s\n", szStr1);
                    break;

                case 5:
                    printf("Enter first string : ");
                    scanf("%s", szStr1);
                    printf("Enter second string : ");
                    scanf("%s", szStr2);
                    printf("Compare = %d\n", Mystrcmp(szStr1, szStr2));
                    break;

                case 6:
                    printf("Enter first string : ");
                    scanf("%s", szStr1);
                    printf("Enter second string : ");
                    scanf("%s", szStr2);
                    printf("Enter n : ");
                    scanf("%d", &iNumber);
                    printf("Compare = %d\n", Mystrncmp(szStr1, szStr2, iNumber));
                    break;

                case 7:
                    printf("Enter string : ");
                    scanf("%s", szStr1);
                    Mystrrev(szStr1);
                    printf("Reversed = %s\n", szStr1);
                    break;

                case 8:
                    printf("Enter main string : ");
                    scanf("%s", szStr1);
                    printf("Enter substring : ");
                    scanf("%s", szStr2);
                    if (Mystrstr(szStr1, szStr2) != NULL)
                        printf("Substring found\n");
                    else
                        printf("Substring NOT found\n");
                    break;

                default:
                    printf("Invalid choice\n");
            }
        }

        // ---------------- MATH MENU ----------------
        else if (iChoice1 == 2)
        {
            printf("\n---- MATH MENU ----\n");
            printf("1. Myabs\n");
            printf("2. Mymax\n");
            printf("3. Mymin\n");
            printf("4. Myfactorial\n");
            printf("5. Mygcd\n");
            printf("6. Mylcm\n");
            printf("7. Mypow\n");
            printf("8. Mysqrt\n");
            printf("Enter choice : ");
            scanf("%d", &iChoice2);

            switch (iChoice2)
            {
                case 1:
                    printf("Enter number : ");
                    scanf("%d", &iNo1);
                    printf("Abs = %d\n", Myabs(iNo1));
                    break;

                case 2:
                    printf("Enter two numbers : ");
                    scanf("%d%d", &iNo1, &iNo2);
                    printf("Max = %d\n", Mymax(iNo1, iNo2));
                    break;

                case 3:
                    printf("Enter two numbers : ");
                    scanf("%d%d", &iNo1, &iNo2);
                    printf("Min = %d\n", Mymin(iNo1, iNo2));
                    break;

                case 4:
                    printf("Enter number : ");
                    scanf("%d", &iNo1);
                    printf("Factorial = %ld\n", Myfactorial(iNo1));
                    break;

                case 5:
                    printf("Enter two numbers : ");
                    scanf("%d%d", &iNo1, &iNo2);
                    printf("GCD = %d\n", Mygcd(iNo1, iNo2));
                    break;

                case 6:
                    printf("Enter two numbers : ");
                    scanf("%d%d", &iNo1, &iNo2);
                    printf("LCM = %d\n", Mylcm(iNo1, iNo2));
                    break;

                case 7:
                    printf("Enter base and exponent : ");
                    scanf("%lf%d", &dNo, &iNo1);
                    printf("Power = %.2lf\n", Mypow(dNo, iNo1));
                    break;

                case 8:
                    printf("Enter number : ");
                    scanf("%lf", &dNo);
                    printf("Sqrt = %.4lf\n", Mysqrt(dNo));
                    break;

                default:
                    printf("Invalid choice\n");
            }
        }

    } while (iChoice1 != 0);

    return 0;
}

