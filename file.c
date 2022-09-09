#include <stdio.h>
#include "file.h"

FILE *arqEntrada;

void open_file(char argv[]){
    arqEntrada = fopen(argv, "r");

    if(arqEntrada == NULL) printf("ERRO AO ABRIR O ARQUIVO.\n");
}

int read_file(){
    int x, final;
    final = fscanf(arqEntrada, "%d", &x);
    if(final == -1) return 50;
    else return x;
}

void close_file(){
    fclose(arqEntrada);
}