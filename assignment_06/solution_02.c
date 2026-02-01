#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*fp)(int, int);


int main(void)
{
    void *handle = NULL;
    fp Add = NULL;
    fp Sub = NULL;
    char *err = NULL;
    int iNo1 = 10, iNo2 = 5;

    // 1) loading the shared library at runtime using dlopen() function
    handle = dlopen("./libfunlib.so", RTLD_LAZY);
    if (!handle)
    {
        // 2) dlerror() is used for showing the error message
        printf("dlopen() failed : %s\n", dlerror());
        return -1;
    }

    // 3) Clearing the error any existing error message
    dlerror();

    // 4) Getting Addition() function address for addition using dlsym() function
    Add = (fp)dlsym(handle, "Addition");
    err = dlerror();
    if (err != NULL)
    {
        printf("dlsym(Addition) failed : %s\n", err);
        // 5) closing the handle using the dlclose()
        dlclose(handle);
    }

    // 6) Getting Subtraction() function address for subtraction using dlsym() function
    Sub = (fp)dlsym(handle, "Subtraction");
    err = dlerror();
    if (err != NULL)
    {
        printf("dlsym(Subtraction) failed : %s\n", err);
        // 7) closing the handle using the dlclose()
        dlclose(handle);
    }

    // 8) Calling the Addition() and Subtraction() functions
    printf("Addition is %d\n", Add(iNo1, iNo2));
    printf("Subtraction is %d\n", Sub(iNo1, iNo2));

    // 9) Closing the handle after its used
    dlclose(handle);

    return 0;
}

