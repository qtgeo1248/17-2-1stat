#include "stat.h"

int main() {
    struct stat *info;
    if (stat("main.c", info) < 0) {
        printf("Errno: %s\n", strerror(errno));
        return errno;
    }

    printf("File size: %lld\n", info->st_size);
    return 0;
}
