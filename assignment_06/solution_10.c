#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


int main(int argc, char * argv[])
{
    void * handle = NULL;
    void *symbol = NULL;
    char * err = NULL;

    if (argc != 3)
    {
        printf("Usage : %s <library_path> <symbol_name>\n", argv[0]);
        return -1;
    }

    handle = dlopen(argv[1], RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen() failed : %s\n", dlerror());
        return -1;
    }

    dlerror();

    symbol = dlsym(handle, argv[2]);

    err = dlerror();
    if (err != NULL)
    {
        printf("Symbol not found : %s\n", err);
        dlclose(handle);
        return -1;
    }

    printf("Symbol '%s' found at address : %p\n", argv[2], symbol);

    dlclose(handle);
    
    return 0;
}

