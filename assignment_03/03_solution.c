#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/limits.h>

#define BUF_SIZE 100


int copy_file(const char *ptr, const char *dst)
{
    int fd_source, fd_dest;
    char chBuffer[BUF_SIZE];
    int bytes;

    fd_source = open(ptr, O_RDONLY);
    if (fd_source < 0)
        return -1;

    fd_dest = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest < 0)
    {
        close(fd_source);
        return -1;
    }

    while ((bytes = read(fd_source, chBuffer, BUF_SIZE)) > 0)
        write(fd_dest, chBuffer, bytes);

    close(fd_source);
    close(fd_dest);
    return 0;
}

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *entry;
    struct stat fileStat;
    char sourcePath[PATH_MAX];
    char destPath[PATH_MAX];
    int iCounter = 0;

    if (argc != 3)
    {
        printf(stderr, "Usage : %s <source_dir> <destination_dir>\n", argv[0]);
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

        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", argv[1], entry -> d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", argv[2], entry -> d_name);

        if (stat(sourcePath, &fileStat) == -1)
            continue;

        if (S_ISREG(fileStat.st_mode))
        {
            if (rename(sourcePath, destPath) == 0)
            {
                iCounter++;
            }
            else if (errno == EXDEV)
            {
                if (copy_file(sourcePath, destPath) == 0)
                {
                    unlink(sourcePath);
                    iCounter++;
                }
            }
        }
    }

    closedir(dp);

    printf("Total files moved: %d\n", iCounter);
    return 0;
}
