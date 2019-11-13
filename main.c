#include "stat.h"

int main() {
    struct stat *info;
    if (stat("main.c", info) < 0) {
        printf("Errno: \n", strerro(errno));
        return errno;
    }

    printf("File size: %d\n", info->st_size);
    return 0;
}
