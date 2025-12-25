#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char * argv[])
{
    int iRet = 0;

    char *path = argv[1];
    int mode = 0;

    if (argv[1] == NULL)
    {
        printf("File name not provided\n");
        return -1;
    }

    if (argv[2] == NULL)
    {
        printf("File opening mode not provided\n");
        return -1;
    }

    if (strcmp(argv[2], "R") == 0)
    {
        mode = O_RDONLY;
    }
    else if (strcmp(argv[2], "W") == 0)
    {
        mode = O_WRONLY;
    }
    else if (strcmp(argv[2], "RW") == 0)
    {
        mode = O_RDWR;
    }
    else if (strcmp(argv[2], "A") == 0)
    {
        mode = O_APPEND | O_CREAT;
    }
    else
    {
        printf("Please enter correct file mode\n");
        return -1;
    }

    iRet = access(path, mode);

    if (iRet == -1)
    {
        printf("Not accessible\n");
    }
    else
    {
        printf("Accessible\n");
    }

    return 0;
}

