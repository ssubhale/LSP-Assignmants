#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

#define BUFFER_SIZE 100


int main(int argc, char *argv[])
{
    int fd_src, fd_dst;
    ssize_t bytesRead, bytesWritten;
    char buffer[BUFFER_SIZE];
    struct stat statBuf;

    if (argc != 3)
    {
        printf(stderr, "Usage : %s <source_file> <destination_file>\n", argv[0]);
        return -1;
    }

    fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1)
    {
        printf("Error : %s\n", strerror(errno));
        return -1;
    }

    if (stat(argv[1], &statBuf) == -1)
    {
        printf("Stat error : %s\n", strerror(errno));
        close(fd_src);
        return -1;
    }

    fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, statBuf.st_mode);
    if (fd_dst == -1)
    {
        printf("Error : %s\n", strerror(errno));
        close(fd_src);
        return -1;
    }

    while ((bytesRead = read(fd_src, buffer, BUFFER_SIZE)) > 0)
    {
        bytesWritten = write(fd_dst, buffer, bytesRead);
        if (bytesWritten != bytesRead)
        {
            printf("Write error : %s\n", strerror(errno));
            close(fd_src);
            close(fd_dst);
            return -1;
        }
    }

    if (bytesRead == -1)
    {
        printf("Read error : %s\n", strerror(errno));
    }

    chmod(argv[2], statBuf.st_mode);

    close(fd_src);
    close(fd_dst);

    printf("File copied successfully.\n");
    return 0;
}
