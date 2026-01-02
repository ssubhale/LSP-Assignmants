#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024


int main(int argc, char * argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    int bytesRead, bytesWritten;
    char chBuffer[BUFFER_SIZE];


    if (argc != 3)
    {
        fprintf(stderr, "Usage : %s <source_file_path> <destination_file_path>\n", argv[0]);
        return -1;
    }

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0)
    {
        printf("Error for fd1 : %s\n", strerror(errno));
        return -1;
    }

    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd2 < 0)
    {
        printf("Error for fd2 : %s\n", strerror(errno));
        close(fd1);
        return -1;
    }

    while ((bytesRead = read(fd1, chBuffer, bytesRead)) > 0)
    {
        bytesWritten = write(fd2, chBuffer, BUFFER_SIZE);
        if (bytesWritten < 0)
        {
            printf("Error to write in file : %s\n", strerror(errno));
            close(fd1);
            close(fd2);
            return -1;
        }
    }

    if (bytesRead < 0)
    {
        printf("Error rteading source file : %s\n", strerror(errno));
        return -1;
    }

    close(fd1);
    close(fd2);

    printf("File copied successfully\n");

    return 0;
}

