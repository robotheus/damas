#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "file.h"

void create_board(int **board, int n, int m){
    //cria o vetor de ponteiros
    for(int i = 0; i < n+2; i++){
        board[i] = (int*) malloc((m+2) * sizeof(int*));
    }

    //preenche todo o vetor com zeros
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < m+2; j++){
            board[i][j] = 0;
        }
    }

    //preenche o vetor com dados lidos do arquivo
    for(int y = 1; y <= n; y++){
        if(y % 2 != 0){
            for(int x = 1; x <= m; x += 2){
                board[y][x] = read_file();
            }
        } else {
            for(int x = 2; x <= m; x += 2){
                board[y][x] = read_file();
            }
        }
    }
}

void clean_board(int **board, int n){
    for(int i = 0; i < n+2; i++){
        free(board[i]);
    }
}