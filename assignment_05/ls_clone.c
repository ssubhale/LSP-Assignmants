#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <linux/limits.h>
#include <time.h>


void PrintPermissions(int mode)
{
    char chPeram[10];

    chPeram[0] = (mode & S_IRUSR) ? 'r' : '-';
    chPeram[1] = (mode & S_IWUSR) ? 'w' : '-';
    chPeram[2] = (mode & S_IXUSR) ? 'x' : '-';

    chPeram[3] = (mode & S_IRGRP) ? 'r' : '-';
    chPeram[4] = (mode & S_IWGRP) ? 'w' : '-';
    chPeram[5] = (mode & S_IXGRP) ? 'x' : '-';

    chPeram[6] = (mode & S_IROTH) ? 'r' : '-';
    chPeram[7] = (mode & S_IWOTH) ? 'w' : '-';
    chPeram[8] = (mode & S_IXOTH) ? 'x' : '-';

    chPeram[9] = '\0';

    printf("%s", chPeram);
}


const char * GetFileType(int mode)
{
    if (S_ISREG(mode))
        return "File";

    if (S_ISDIR(mode))
        return "Directory";

    if (S_ISLNK(mode))
        return "Link";

    return "Other";
}


int main(int argc, char * argv[])
{
    DIR *dp = NULL;
    struct dirent *sObj;
    struct stat fileStat;

    char fullPath[PATH_MAX];
    char timeStr[100];

    if (argc != 2)
    {
        printf("Usage : %s <directory_path>\n", argv[0]);
        return -1;
    }

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("Error opening directory : %s\n", strerror(errno));
        return -1;
    }

    printf("Name            Type       Size     Permissions   Last Modified\n");
    printf("-------------------------------------------------------------------\n");

    while ((sObj = readdir(dp)) != NULL)
    {
        if (strcmp(sObj -> d_name, ".") == 0 || strcmp(sObj -> d_name, "..") == 0)
            continue;

        snprintf(fullPath, sizeof(fullPath), "%s/%s", argv[1], sObj -> d_name);

        if (lstat(fullPath, &fileStat) < 0)
        {
            printf("File name : %s\n", sObj -> d_name);
            printf("Error : %s\n", strerror(errno));
            continue;
        }

        strftime(timeStr, sizeof(timeStr), "%d-%m-%Y %H:%M:%S", localtime(&fileStat.st_mtime));
        
        printf("%-15s %-10s %-8ld ", sObj -> d_name, GetFileType(fileStat.st_mode), fileStat.st_size);
        
        PrintPermissions(fileStat.st_mode);

        printf("\t%s\n", timeStr);
    }

    closedir(dp);

    return 0;
}

