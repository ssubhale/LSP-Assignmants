#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#define MAX_SIZE 100
typedef int (*fp)(char *);


int main(void)
{
    void *handle = NULL;
    fp CountLower = NULL;
    fp CountUpper = NULL;
    fp CountDigits = NULL;
    char * err = NULL;
    char szStr[MAX_SIZE];

    printf("Enter a string : ");
    scanf("%s[^\n]", szStr);

    handle = dlopen("./libfunlib.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen() failed : %s\n", dlerror());
        return -1;
    }

    dlerror();

    CountUpper = (fp)dlsym(handle, "CountUppercase");
    CountLower = (fp)dlsym(handle, "CountLowercase");
    CountDigits = (fp)dlsym(handle, "CountDigits");

    err = dlerror();
    if (err != NULL)
    {
        printf("Error %s\n", err);
        dlclose(handle);
        return -1;
    }

    printf("Uppercase letters : %d\n", CountUpper(szStr));
    printf("Lowercase letters : %d\n", CountLower(szStr));
    printf("Count digits : %d\n", CountDigits(szStr));

    dlclose(handle);

    return 0;
}

