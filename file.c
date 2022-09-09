#include <stdio.h>
#include "file.h"

FILE *arqEntrada;

void open_file(char argv[]){
    arqEntrada = fopen(argv, "r");

    if(arqEntrada == NULL) printf("ERRO AO ABRIR O ARQUIVO.\n");
}

int read_file(){
    int x;
    fscanf(arqEntrada, "%d", &x);
    
    return x;
}

void close_file(){
    fclose(arqEntrada);
}