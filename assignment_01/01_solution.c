#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    int fd = 0;

    fd = open(argv[1], O_RDONLY);

    if (fd < 0)
    {
        printf("Error : %s\n", strerror(errno));
        return -1;
    }
    else
    {
        printf("Successfully open the file with fd %d\n", fd);
    }

    close(fd);

    return 0;
}

