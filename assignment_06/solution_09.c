#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


typedef int (*fp)(int, int);


int main(void)
{
    void * handle = NULL;
    char * err = NULL;
    int iCounter;
    int iNo1 = 12, iNo2 = 10;

    fp mathFuncs[4];
    char *funNames[] = {"Addition", "Subtraction", "Multiplication", "Division"};

    handle = dlopen("./libfunlib.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen() failed : %s\n", dlerror());
        return -1;
    }

    dlerror();
    for (iCounter = 0; iCounter < 4; iCounter++)
    {
        mathFuncs[iCounter] = (fp)dlsym(handle, funNames[iCounter]);
        err = dlerror();
        if (err != NULL)
        {
            printf("dlsym() failed : %s\n", err);
            dlclose(handle);
            return -1;
        }
    }

    for (iCounter = 0; iCounter < 4; iCounter++)
    {
        printf("Address of %s : %p\n", funNames[iCounter], mathFuncs[iCounter]);
        printf("Result : %d\n\n", mathFuncs[iCounter](iNo1, iNo2));
    }

    dlclose(handle);

    return 0;
}

