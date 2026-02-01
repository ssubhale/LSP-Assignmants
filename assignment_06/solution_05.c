#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*fp)(int, int);


int main(void)
{
    void * handle = NULL;
    fp Add = NULL;
    fp Sub = NULL;
    char *err = NULL;
    int iNo1 = 10, iNo2 = 5;

    printf("Demonstration of dlopen() whth RTLD_LAZY flag\n");

    handle = dlopen("./libfunlib.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen() failed with RTLD_LAZY : %s\n", dlerror());
        return -1;
    }

    dlerror();

    Add = (fp)dlsym(handle, "Addition");
    err = dlerror();
    if (err != NULL)
    {
        printf("dlsym(Addition) failed : %s\n", err);
        dlclose(handle);
    }

    printf("Addition is %d\n", Add(iNo1, iNo2));

    dlclose(handle);

    printf("Demonstration of dlopen() whth RTLD_NOW flag\n");


    handle = dlopen("./libfunlib.so", RTLD_NOW);
    if (!handle)
    {
        printf("dlopen() failed RTLD_NOW : %s\n", dlerror());
        return -1;
    }

    Sub = (fp)dlsym(handle, "Subtraction");
    err = dlerror();
    if (err != NULL)
    {
        printf("dlsym(Subtraction) failed : %s\n", err);
        dlclose(handle);
    }

    printf("Subtraction is %d\n", Sub(iNo1, iNo2));

    dlclose(handle);

    return 0;
}

/*
    RTLD_LAZY finds symbols only when they are used, 
    whereas RTLD_NOW finds all symbols immediately at load time. 
    RTLD_LAZY gives immediate starting but runtime errors, while RTLD_NOW finds errors quekly.
*/

