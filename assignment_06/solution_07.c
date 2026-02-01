#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*fp_update)(int);
typedef int (*fp_display)(void);
typedef void (*fp_reset)(void);


int main(void)
{
    void *handle = NULL;
    fp_update UpdateVar = NULL;
    fp_display Display = NULL;
    fp_reset ResetVar = NULL;
    char * err = NULL;

    printf("Demonstration of global varibale persistence demo\n");

    handle = dlopen("./libvarlib.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen() failed : %s\n", dlerror());
        return -1;
    }

    dlerror();

    UpdateVar = (fp_update)dlsym(handle, "UpdateVar");
    Display = (fp_display)dlsym(handle, "Display");
    ResetVar = (fp_reset)dlsym(handle, "ResetVar");

    err = dlerror();
    if (err != NULL)
    {
        printf("dlsym() failed : %s\n", err);
        return -1;
    }

    printf("Initial value : %d\n", Display());

    UpdateVar(50);
    printf("After UpdateVar(50) : %d\n", Display());

    UpdateVar(100);
    printf("After UpdateVar(100) : %d\n", Display());

    ResetVar();
    printf("After ResetVar() : %d\n", Display());

    dlclose(handle);

    return 0;
}

