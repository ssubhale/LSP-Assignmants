#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <linux/limits.h>


int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    struct stat sObj;
    char fullpath[PATH_MAX];

    struct fileStat {
        char path[PATH_MAX];
        int size;
    } fileObj = {"", 0};

    if (argc < 2)
    {
        printf(stderr, "Usage: %s <directory path>\n", argv[0]);
        return -1;
    }

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("Unable to open directory: %s\n", strerror(errno));
        return -1;
    }

    while ((ptr = readdir(dp)) != NULL)
    {
        if (strcmp(ptr -> d_name, ".") == 0 || strcmp(ptr -> d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", argv[1], ptr -> d_name);

        if (stat(fullpath, &sObj) == -1)
            continue;

        if (S_ISREG(sObj.st_mode) && sObj.st_size > fileObj.size)
        {
            strcpy(fileObj.path, ptr -> d_name);
            fileObj.size = sObj.st_size;
        }
    }

    closedir(dp);

    if (fileObj.size > 0)
    {
        printf("Largest file name : %s\n", fileObj.path);
        printf("Actual file size  : %d bytes\n", fileObj.size);
    }
    else
    {
        printf("No regular files found.\n");
    }

    return 0;
}
