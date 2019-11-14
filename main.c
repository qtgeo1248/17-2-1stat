#include "stat.h"

int main() {
    struct stat info;
    if (stat("main.c", &info) < 0) {
        printf("Errno: %s\n", strerror(errno));
        return errno;
    }

    printf("File size: %lld\n", info.st_size);
    printf("perms: %o\n", info.st_mode);
    time_t time = info.st_atime;
    printf("Time Last Accessed: %s\n\n", ctime(&time));

    printf("Now doing things in Readable Form\n");
    char string[100];
    float size2;
    int size = info.st_size;
    if (size > 1024) {
        float size2 = size / 1024.0;
        sprintf(string, "%.2f Kilobytes", size2);
    } else {
        sprintf(string, "%d bytes", size);
    }
    printf("File Size: %s\n", string);

    printf("File permissionss: -");
    char perm[100];
    sprintf(perm, "%o", info.st_mode & 511);
    int i = 0;
    for (; i < 3; i++) {
        if (perm[i] == '0') {
            printf("---");
        } else if (perm[i] == '1') {
            printf("--x");
        } else if (perm[i] == '2') {
            printf("-w-");
        } else if (perm[i] == '3') {
            printf("-wx");
        } else if (perm[i] == '4') {
            printf("r--");
        } else if (perm[i] == '5') {
            printf("r-x");
        } else if (perm[i] == '6') {
            printf("rw-");
        } else {
            printf("rwx");
        }
    }
    printf("\n");
    return 0;
}
