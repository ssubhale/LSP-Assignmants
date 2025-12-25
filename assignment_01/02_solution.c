#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    int fd = 0;

    char *path = argv[1];
    int mode;

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

    fd = open(path, mode, 0777);

    if (fd < 0)
    {
        printf("Error : %s\n", strerror(errno));
        return -1;
    }
    else
    {
        printf("Successfully open file with fd %d\n", fd);
    }

    close(fd);

    return 0;
}

