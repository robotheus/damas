#include <stdio.h>
#include "file.h"

FILE *fileInput, *fileOutput;

void open_file(char argv1[], char argv2[]){
    fileInput = fopen(argv1, "r");
    fileOutput = fopen(argv2, "w");

    if(fileInput == NULL) printf("ERRO AO ABRIR O ARQUIVO.\n");
}

int read_file(){
    int x, final;
    final = fscanf(fileInput, "%d", &x);
    if(final == -1) return 50;
    else return x;
}

void close_file(){
    fclose(fileInput);
    fclose(fileOutput);
}

void output(int output, int n, int m){
    if(output == -1) fprintf(fileOutput, "O tabuleiro %dx%d eh invalido, retire a entrada e execute novamente.\n", n, m);
    else {
        int write = output;
        fprintf(fileOutput, "%d\n", write);
    }
}