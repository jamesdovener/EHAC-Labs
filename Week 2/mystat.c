#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>



int main (int argc, char *argv[]){
    if ( argc != 2 ) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    const char *file_name = argv[1];
    struct stat file_stat;

    if ( stat(file_name, &file_stat) == -1 ) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    printf("File: %s\n", file_name);
    printf("Size: %ld\n", file_stat.st_size);
    printf("Blocks allocated: %ld\n", file_stat.st_blocks);
    printf("Reference count: %ld\n", file_stat.st_nlink);

    return 0;
}