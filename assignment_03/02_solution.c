#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <linux/limits.h>


int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat st;
    char fullpath[PATH_MAX];
    int found = 0;

    if (argc != 3)
    {
        printf(stderr, "Usage : %s <directory_path> <file_name>\n", argv[0]);
        return -1;
    }

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("Error : %s\n", strerror(errno));
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (strcmp(entry -> d_name, argv[2]) == 0)
        {
            snprintf(fullpath, sizeof(fullpath), "%s/%s", argv[1], entry -> d_name);

            if (stat(fullpath, &st) == 0)
            {
                printf("File found!\n");
                printf("Absolute path : %s\n", fullpath);
                found = 1;
                break;
            }
        }
    }

    closedir(dp);

    if (!found)
        printf("File not found in directory.\n");

    return 0;
}
