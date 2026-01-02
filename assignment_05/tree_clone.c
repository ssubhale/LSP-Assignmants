#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <linux/limits.h>


void PrintDepth(int iDepth)
{
    for (int iCounter = 0; iCounter < iDepth; iCounter++)
        printf("    ");
}


void PrintTree(const char *path, int iDepth)
{
    DIR * dp;
    struct dirent * dObj;
    struct stat fileStat;
    char fullPath[PATH_MAX];

    dp = opendir(path);
    if (dp == NULL)
    {
        printf("Error opening directory : %s\n", strerror(errno));
        return;
    }

    while ((dObj = readdir(dp)) != NULL)
    {
        if (strcmp(dObj -> d_name, ".") == 0 || strcmp(dObj -> d_name, "..") == 0)
            continue;

        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, dObj->d_name);
    
        if (lstat(fullPath, &fileStat) < 0)
        {
            printf("lstat failed for %s : %s\n", dObj -> d_name, strerror(errno));
            continue;
        }

        PrintDepth(iDepth);

        if (S_ISDIR(fileStat.st_mode))
        {
            printf("[D] %s\n", dObj -> d_name);
            PrintTree(fullPath, iDepth + 1);
        }

        else if (S_ISREG(fileStat.st_mode))
        {
            printf("[F] %s\n", dObj -> d_name);
        }

        else if (S_ISLNK(fileStat.st_mode))
        {
            printf("[L] %s\n", dObj -> d_name);
        }

        else
        {
            printf("[O] %s\n", dObj -> d_name);
        }

    }

    closedir(dp);

    return;
}


int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("Usage : %s <directory_path>\n", argv[0]);
        return -1;
    }

    printf("[D] %s\n", argv[1]);
    PrintTree(argv[1], 1);

    return 0;
}

