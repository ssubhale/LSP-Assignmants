#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    int fd;
    int fileSize, iPos;
    char chChar;
    int bytesRead;

    if (argc != 2)
    {
        printf("Usage: %s <file_name>\n", argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Error : %s\n", strerror(errno));
        return -1;
    }

    fileSize = lseek(fd, 0, SEEK_END);
    if (fileSize == -1)
    {
        printf("Error determining file size : %s\n",strerror(errno));
        close(fd);
        return -1;
    }

    for (iPos = fileSize - 1; iPos >= 0; iPos--)
    {
        if (lseek(fd, iPos, SEEK_SET) == -1)
        {
            printf("lseek error: %s\n", strerror(errno));
            close(fd);
            return -1;
        }

        bytesRead = read(fd, &chChar, 1);
        if (bytesRead < 0)
        {
            printf("Read error: %s\n", strerror(errno));
            close(fd);
            return -1;
        }

        write(STDOUT_FILENO, &chChar, 1);
    }
    printf("\n");

    close(fd);
    return 0;
}
