#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sObj;

    if (argc < 2)
    {
        printf(stderr, "Usage: %s <file/directory path>\n", argv[0]);
        return -1;
    }

    if (lstat(argv[1], &sObj) == -1)
    {
        printf("lstat error: %s\n", strerror(errno));
        return -1;
    }

    printf("Inode number     : %ld\n", sObj.st_ino);
    printf("Hard link count  : %ld\n", sObj.st_nlink);
    printf("Total size       : %ld bytes\n", sObj.st_size);
    printf("Block size       : %ld bytes\n", sObj.st_blksize);

    printf("File type        : ");

    if (S_ISREG(sObj.st_mode))
    {
        printf("Regular file\n");
    }
    else if (S_ISDIR(sObj.st_mode))
    {
        printf("Directory\n");
    }
    else if (S_ISCHR(sObj.st_mode))
    {
        printf("Character device\n");
    }
    else if (S_ISBLK(sObj.st_mode))
    {
        printf("Block device\n");
    }
    else if (S_ISFIFO(sObj.st_mode))
    {
        printf("FIFO (Pipe)\n");
    }
    else if (S_ISLNK(sObj.st_mode))
    {
        printf("Symbolic link\n");
    }
    else if (S_ISSOCK(sObj.st_mode))
    {
        printf("Socket\n");
    }
    else
        printf("Unknown\n");

    return 0;
}
