#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*fp)(int, int);


int main(void)
{
    void *handle = NULL;
    fp Add = NULL;
    char *err = NULL;

    int iNo1 = 10, iNo2 = 5;

    printf("Dynamic Library Search Path Demo\n");

    handle = dlopen("libfunlib.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen failed : %s\n", dlerror());
        return -1;
    }

    dlerror();

    Add = (fp)dlsym(handle, "Addition");
    err = dlerror();
    if (err != NULL)
    {
        printf("dlsym failed : %s\n", err);
        dlclose(handle);
        return -1;
    }

    printf("Addition = %d\n", Add(iNo1, iNo2));

    dlclose(handle);
    return 0;
}


/*

Case 01 : Run WITHOUT LD_LIBRARY_PATH
    >> gcc solution_06.c -o myexe.exe
    >> ./myexe.exe

    OP :
        Dynamic Library Search Path Demo
        dlopen failed : libfunlib.so: cannot open shared object file: No such file or directory


Case 02 : Run WITH LD_LIBRARY_PATH
    >> export LD_LIBRARY_PATH=.
    >> ./myexe.exe

    OP : 
        Dynamic Library Search Path Demo
        Addition = 15

*/

