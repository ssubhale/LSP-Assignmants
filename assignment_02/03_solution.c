#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *ptr = NULL;
    char *path = argv[1];

    if (argc < 2) {
        printf(stderr, "Usage: %s <directory path>\n", argv[0]);
        return -1;
    }

    dp = opendir(path);

    if (NULL == dp)
    {
        printf("Unable to open directory %s\n", strerror(errno));
        return -1;
    }

    while(ptr = readdir(dp))
    {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;

        printf("Inode number : %ld\n", ptr -> d_ino);
        printf("File name : %s\n", ptr -> d_name);   
    }
    
    closedir(dp);

    return 0;
}

