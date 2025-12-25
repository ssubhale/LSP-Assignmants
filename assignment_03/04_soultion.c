#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/limits.h>


int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat st;
    char fullpath[PATH_MAX];
    int deleteCount = 0;

    if (argc != 2)
    {
        printf(stderr, "Usage : %s <directory_path>\n", argv[0]);
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
        if (strcmp(entry -> d_name, ".") == 0 ||
            strcmp(entry -> d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", argv[1], entry -> d_name);

        if (stat(fullpath, &st) == -1)
            continue;

        if (S_ISREG(st.st_mode) && st.st_size == 0)
        {
            if (unlink(fullpath) == 0)
            {
                printf("Deleted : %s\n", entry -> d_name);
                deleteCount++;
            }
        }
    }

    closedir(dp);

    printf("Total empty regular files deleted: %d\n", deleteCount);
    return 0;
}
