#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct stat fileInfo;

    if (argc != 2)
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &fileInfo) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);

    printf("File Type:            ");

    if (S_ISREG(fileInfo.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(fileInfo.st_mode))
        printf("Directory\n");
    else if (S_ISCHR(fileInfo.st_mode))
        printf("Character Device\n");
    else if (S_ISBLK(fileInfo.st_mode))
        printf("Block Device\n");
    else if (S_ISFIFO(fileInfo.st_mode))
        printf("FIFO (Pipe)\n");
    else if (S_ISLNK(fileInfo.st_mode))
        printf("Symbolic Link\n");
    else if (S_ISSOCK(fileInfo.st_mode))
        printf("Socket\n");
    else
        printf("Unknown\n");

    printf("Permissions:          %04o\n", fileInfo.st_mode & 0777);
    printf("File Size:            %ld bytes\n", fileInfo.st_size);
    printf("Hard Links Count:     %ld\n", fileInfo.st_nlink);
    printf("Owner (UID):          %d\n", fileInfo.st_uid);
    printf("Group (GID):          %d\n", fileInfo.st_gid);

    printf("Last Access Time:     %s", ctime(&fileInfo.st_atime));
    printf("Last Modification:    %s", ctime(&fileInfo.st_mtime));
    printf("Status Change Time:   %s", ctime(&fileInfo.st_ctime));

    return 0;
}

