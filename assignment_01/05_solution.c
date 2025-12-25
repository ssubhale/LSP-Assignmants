#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 100


int main(int argc, char *argv[])
{
    int fd = 0;
    char *path = argv[1];
    int nBytes = atoi(argv[2]);
    char chBuffer[BUFFER_SIZE];
    int iRet = 0;

    if (argv[1] == NULL)
    {
        printf("File name not provided\n");
        return -1;
    }

    if (argv[2] == NULL)
    {
        printf("Number of bytes count not provided\n");
        return -1;
    }

    if (nBytes > BUFFER_SIZE)
    {
        nBytes = BUFFER_SIZE;
    }

    fd = open(path, O_RDONLY);

    if (fd < 0)
    {
        printf("Error : %s\n", strerror(errno));
        return -1;
    }

    memset(chBuffer, '\0', BUFFER_SIZE);
    

    iRet = read(fd, chBuffer, nBytes);

    printf("%d bytes gets read from the file\n", iRet);

    printf("Data from file %s\n", chBuffer);


    close(fd);

    return 0;
}

