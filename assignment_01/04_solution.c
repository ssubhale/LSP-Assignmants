#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    char *path = argv[1];

    struct stat sObj;
    int iRet = 0;

    if (argv[1] == NULL)
    {
        printf("File name not provided\n");
        return -1;
    }

    iRet = stat(path, &sObj);

    if (iRet == -1)
    {
        printf("Unale to check file %s\n", strerror(errno));
        return -1;
    }

    printf("Total size : %ld\n", sObj.st_size);
    printf("Inode number : %ld\n", sObj.st_ino);
    printf("Permission : %d\n", sObj.st_mode);
    printf("Hardlink,s : %ld\n", sObj.st_nlink);
    printf("User ID : %d\n", sObj.st_uid);
    printf("Group ID : %d\n", sObj.st_gid);

    if (S_ISBLK(sObj.st_mode))
    {
        printf("Block device\n");
    }
    else if (S_ISCHR(sObj.st_mode))
    {
        printf("Character device\n");
    }
    else if (S_ISDIR(sObj.st_mode))
    {
        printf("Directory file\n");
    }
    else if (S_ISREG(sObj.st_mode))
    {
        printf("Reguler file\n");
    }
    else if (S_ISSOCK(sObj.st_mode))
    {
        printf("Sock file\n");
    }
    else if (S_ISFIFO(sObj.st_mode))
    {
        printf("Pipe file\n");
    }
    else if (S_ISLNK(sObj.st_mode))
    {
        printf("Symbolic link\n");
    }

    printf("Last access time : %ld\n", sObj.st_atime);
    

    return 0;
}

