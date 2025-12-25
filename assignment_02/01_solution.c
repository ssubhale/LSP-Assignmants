#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    char *path = argv[1];
    char chChar[1];
    int fd = 0;
    int iCounter = 0;

    if (argc < 2) {
        printf(stderr, "Usage: %s <file path>\n", argv[0]);
        return -1;
    }

    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        printf("Error : %s\n", strerror(errno));
        return -1;
    }

    while(read(fd, chChar, 1))
    {
        printf("%s", chChar);
        iCounter++;
    }

    printf("\nTotal bytes read %d\n", iCounter);

    close(fd);

    return 0;
}

