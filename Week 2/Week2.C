#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void writeToFile(){
    FILE *fptr1;
    FILE *fptr2;

    char input[100];
    char inputFile[100];
    char outputFile[100];

    printf("Enter input file (leave empty to write input manually):\n");
    fgets(inputFile, 100, stdin);
    inputFile[strlen(inputFile)-1] = '\0';

    printf("Enter output file:\n");
    scanf("%s", outputFile);
    fptr2 = fopen(outputFile, "w");

    if (inputFile == "\0") {
        printf("Enter text to be written to output file:\n");
        scanf("%s", input);
        fprintf(fptr2, "%s", input);
    }else{
        fptr1 = fopen(inputFile, "r");
        fgets(input, 100, fptr1);
        fprintf(fptr2, "%s", input);
    }

    fclose(fptr1);
    fclose(fptr2);
}

void readFile(){
    FILE *fptr1;

    fptr1 = fopen("output.txt", "r");

    char fileString[100];

    fgets(fileString, 100, fptr1);

    printf("File content:\n%s", fileString);

    fclose(fptr1);

}

int main(){
    writeToFile();
    readFile();
}

