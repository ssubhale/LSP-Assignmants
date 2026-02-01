#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


typedef int (*fp)(int, int);


int main(void)
{
    void *handle = NULL;
    fp Add = NULL;
    fp Sub = NULL;
    int iNo1 = 10, iNo2 = 5;
    
    handle = dlopen("./libfunlib.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen() failed\n");
        return -1;
    }

    Add = (fp)dlsym(handle, "Addition");
    Sub = (fp)dlsym(handle, "Subtraction");
    
    printf("Addition is %d\n", Add(iNo1, iNo2));
    printf("Subtraction is %d\n", Sub(iNo1, iNo2));

    dlclose(handle);

    return 0;
}

