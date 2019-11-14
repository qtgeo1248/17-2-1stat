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
    printf("Time Last Accessed: %s\n", ctime(&time));

    printf("Now doing things in Readable Form:\n");
    char string[100];
    float size2;
    int size = info.st_size;
    sprintf(string, "%d bytes", size);
    printf("File Size: %s\n", string);

    printf("File permissions: -");
    char perm[100];
    sprintf(perm, "%o", info.st_mode % 01000);
    int i = 0;
    for (; i < 3; i++) {
        int current = perm[i] - '0';
        char out[3];
        char results[3] = "rwx";
        int j = 2;
        for(; j >= 0; j--) {
            if (current % 2 == 0) {
                out[j] = '-';
            } else {
                out[j] = results[j];
            }
            current /= 2;
        }
        printf("%s", out);
    }
    printf("\n");
    return 0;
}
