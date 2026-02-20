#include <stdio.h>
#include <string.h>
#include <unistd.h>
void writeToFile(){


    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("Current working directory: %s\n", cwd);

    char input[100];
    char inputFile[100];
    char outputFile[100];

    printf("Enter input file (leave empty to write input manually):\n");
    fgets(inputFile, 100, stdin);
    if (inputFile[strlen(inputFile) - 1] == '\n') {
        inputFile[strlen(inputFile) - 1] = '\0';
    }

    printf("Enter output file:\n");
    fgets(outputFile,100, stdin);
    if (outputFile[strlen(outputFile) - 1] == '\n') {
        outputFile[strlen(outputFile) - 1] = '\0';
    }
    FILE *fptr2 = fopen(outputFile, "w");

    if ( strcmp(inputFile, "\n")==0 ) {
        printf("Enter text to be written to output file:\n");
        fgets(input, 100, stdin);
        printf("You entered input: %s!",input);
        fprintf(fptr2, "%s", input);
    }else{
        FILE *fptr1 = fopen(inputFile, "r");
        fgets(input, 100, fptr1);
        fprintf(fptr2, "%s", input);
        fclose(fptr1);
    }

    fclose(fptr2);
}

void readFile(){
    char input[100];

    printf("Enter path of file you would like to read:\n");

    fgets(input,100,stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    FILE *fptr1 = fopen(input, "r");

    char fileString[100];

    fgets(fileString, 100, fptr1);

    printf("File content:\n%s", fileString);

    fclose(fptr1);

}

int main(){
    writeToFile();
    readFile();
}

