#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>


#define BUFFER_SIZE 1024


int main(int argc, char * argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    int iCounter = 2;
    int bytesRead, bytesWritten;
    char chBuffer[BUFFER_SIZE];


    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <output_file> <input_file1> <input_file2> ...\n", argv[0]);
        return -1;
    }

    fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd1 < 0)
    {
        printf("Error for output file : %s\n", strerror(errno));
        return -1;
    }

    for (iCounter; iCounter < argc; iCounter++)
    {
        fd2 = open(argv[iCounter], O_RDONLY);
        if (fd2 < 0)
        {
            printf("Error : %s\n", strerror(errno));
            printf("For file : %s\n", argv[iCounter]);
            close(fd1);
            return -1;
        }

        while ((bytesRead = read(fd2, chBuffer,BUFFER_SIZE)) > 0)
        {
            bytesWritten = write(fd1, chBuffer, bytesRead);
            if (bytesWritten < 0)
            {
                printf("Error to write in file : %s\n", strerror(errno));
                close(fd2);
                close(fd1);
                return -1;
            }
        }

        if (bytesRead < 0)
        {
            printf("Error : %s\n", strerror(errno));
            printf("For file : %s\n", argv[iCounter]);
            close(fd2);
            close(fd1);
        }

        close(fd2);
    }

    close(fd1);

    printf("File copied successfully\n");

    return 0;
}

