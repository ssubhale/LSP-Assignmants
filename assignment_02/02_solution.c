#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 100


int main(int argc, char *argv[])
{
    char szStr[BUFFER_SIZE];
    int fd = 0;
    int iRet = 0;

    if (argc < 3) {
        printf(stderr, "Usage: %s <file path> <string>\n", argv[0]);
        return -1;
    }

    strncpy(szStr, argv[2], BUFFER_SIZE - 1);
    szStr[BUFFER_SIZE - 1] = '\0';

    fd = open(argv[1], O_RDWR | O_APPEND);
    if (fd < 0) {
        printf("Error: %s\n", strerror(errno));
        return -1;
    }

    iRet = write(fd, szStr, strlen(szStr));
    if (iRet < 0) {
        printf("Error: %s\n", strerror(errno));
    } else {
        printf("%d bytes written to file\n", iRet);
    }

    close(fd);
    
    return 0;
}
