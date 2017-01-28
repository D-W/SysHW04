#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

void stats(char *file) {
    umask(0000);
    struct stat st;
    stat(file, &st);
    long size = st.st_size;
    char *sizeDesc;
    if(size < 1000) {
        sizeDesc = "B";
    }
    else if(size < 100000){
        size /= 1000.0;
        sizeDesc = "KB";
    }
    else if(size < 1000000000) {
        size /= 100000.0;
        sizeDesc = "MB";
    }
    else {
        size /= 1000000000;
        sizeDesc = "GB";
    }
    printf("File Size: %lu %s\n", size, sizeDesc);
    printf("Mode: %o\n", st.st_mode);
    printf("Time of Last Access: %s", ctime((time_t *)&st.st_atime));
}

int main() {
    stats("file");
    return 0;
}
