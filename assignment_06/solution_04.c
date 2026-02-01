#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*fp)(int, int);

int main(void)
{
    void *handle = NULL;
    fp Add = NULL;
    fp Sub = NULL;
    fp Mul = NULL;
    fp Div = NULL;
    char *err = NULL;

    int iChoice = 0;
    int iNo1 = 0, iNo2 = 0;

    printf("Please select your choice :\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
    scanf("%d", &iChoice);

    if (iChoice == 5)
        return 0;

    if (iChoice < 1 || iChoice > 5)
    {
        printf("Invalid choice\n");
        return 0;
    }

    printf("Enter two numbers : ");
    scanf("%d %d", &iNo1, &iNo2);

    handle = dlopen("./libfunlib.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen() failed : %s\n", dlerror());
        return -1;
    }

    dlerror();

    switch (iChoice)
    {
        case 1:
            Add = (fp)dlsym(handle, "Add");
            err = dlerror();
            if (err != NULL)
            {
                printf("dlsym(Addition) failed : %s\n", err);
                break;
            }
            printf("Addition is %d\n", Add(iNo1, iNo2));
            break;

        case 2:
            Sub = (fp)dlsym(handle, "Sub");
            err = dlerror();
            if (err != NULL)
            {
                printf("dlsym(Subtraction) failed : %s\n", err);
                break;
            }
            printf("Subtraction is %d\n", Sub(iNo1, iNo2));
            break;

        case 3:
            Mul = (fp)dlsym(handle, "Mul");
            err = dlerror();
            if (err != NULL)
            {
                printf("dlsym(Multiplication) failed : %s\n", err);
                break;
            }
            printf("Multiplication is %d\n", Mul(iNo1, iNo2));
            break;

        case 4:
            Div = (fp)dlsym(handle, "Div");
            err = dlerror();
            if (err != NULL)
            {
                printf("dlsym(Division) failed : %s\n", err);
                break;
            }
            printf("Division is %d\n", Div(iNo1, iNo2));
            break;

        default:
            printf("Option not available yet\n");
            break;
    }

    dlclose(handle);
    return 0;
}
