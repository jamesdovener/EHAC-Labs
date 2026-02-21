#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void list_files(const char *dirname, int detailed) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    
    //Open the directory
    dir = opendir(dirname);
    if ( dir==NULL ) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    
    //Read directory entries
    while ( (entry = readdir(dir)) != NULL ) {
        // Ignore hidden files and directories (those stating with '.')
        if ( entry->d_name[0] == '.' ) {
            continue;
        }

        //Print file name or detailed information
        if ( !detailed ) {
            printf("%s\n", entry->d_name);
        } else {
            //Retrieve file information using stat()
            if ( stat(entry->d_name, &file_stat) == -1 ) {
                perror("stat");
                exit(EXIT_FAILURE);
            }
            printf("Name: %s, Size: %ld bytes, Owner: %d, Group: %d, Permissions: %o\n",
                entry->d_name, file_stat.st_size, file_stat.st_uid, file_stat.st_gid, file_stat.st_mode & 0777);
        }
    }

    //Close the directory
    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *dirname;
    int detailed = 0;

    //Determine directory and whether to use detailed listing
    if ( argc == 1 ) {
        //No argument given, use current directory
        dirname = ".";
    } else if ( argc == 2 && argv[1][0] == '-' && argv[1][1] == 'l' ) {
        //Use current directory with detailed listing
        dirname = ".";
        detailed = 1;
    }else if( argc == 3 && argv[1][0] == '-' && argv[1][1] == 'l' ) {
        //Use provided directory without detailed listing
        dirname = argv[1];
    } else {
        fprintf(stderr, "Usage: %s [-l] [directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //List files in the directory
    list_files(dirname, detailed);

    return 0;
}