#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <linux/limits.h>


int totalFiles = 0;
int totalDirs = 0;
long long totalSize = 0;

char largestFile[PATH_MAX];
int largestSize = 0;


void AnayzeDirectory(const char *path)
{
    DIR *dp;
    struct dirent *dObj;
    struct stat fileStat;
    char fullPath[PATH_MAX];

    dp = opendir(path);
    if (dp == NULL)
    {
        printf("Error for opening file : %s\n", strerror(errno));
        return;
    }

    totalDirs++;

    while ((dObj = readdir(dp)) != NULL)
    {
        if (strcmp(dObj -> d_name, ".") == 0 || strcmp(dObj -> d_name, "..") == 0)
            continue;

        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, dObj -> d_name);

        if (lstat(fullPath, &fileStat) == -1)
        {
            printf("Error lstat : %s\n", strerror(errno));
            continue;
        }

        if (S_ISREG(fileStat.st_mode))
        {
            totalFiles++;
            totalSize += fileStat.st_size;
            strncpy(largestFile, dObj -> d_name, sizeof(largestFile) - 1);

            largestFile[sizeof(largestFile) -1] = '\0';
        }

        else if (S_ISDIR(fileStat.st_mode))
        {
            AnayzeDirectory(fullPath);
        }

        else if (S_ISLNK(fileStat.st_mode))
        {
            continue;
        }
    }

    closedir(dp);
}


int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return -1;
    }

    AnayzeDirectory(argv[1]);

    printf("\n------ File Counter + Size Report ------\n");
    printf("Files        : %d\n", totalFiles);
    printf("Directories  : %d\n", totalDirs);
    printf("Total Size   : %lld bytes\n", totalSize);

    if (largestSize > 0)
        printf("Largest File : %d (%lld bytes)\n",
               largestSize, (long long)largestSize);
    else
        printf("Largest File : None\n");

    return 0;
}

