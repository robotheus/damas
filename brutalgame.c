#include <stdio.h>
#include <stdlib.h>
#include "brutalgame.h"
#include "board.h"
#include "print.h"

void brutal_game(int **board, int n, int m){
    int *contador, max = 0, **copy, k = 0, l = 0, o = 0, p = 0;
    
    contador = malloc(sizeof(int));
    copy = (int**)malloc((n+2) * sizeof(int*));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == 1){
                *contador = 0;
                copy_board(copy, board, n, m);
                check_diagonals(copy, i, j, k, l, o, p, contador);
                clean_board(copy, n);
            }

            if(*contador > max){
                max = *contador;
            }
        }
    }
    
    printf("maior numero de jogadas: %d\n", max);
    free(contador);
    free(copy);
}

int check_diagonals(int **board, int i, int j, int k, int l, int m, int n, int *contador){    
    if(board[i+1][j+1] == 2 && board[i+2][j+2] == 0){
        eat(board, i+2, j+2, i+1, j+1, i, j, contador);
    } else if(board[i-1][j-1] == 2 && board[i-2][j-2] == 0){
        eat(board, i-2, j-2, i-1, j-1, i, j, contador);
    } else if(board[i+1][j-1] == 2 && board[i+2][j-2] == 0){
        eat(board, i+2, j-2, i+1, j-1, i, j, contador);
    } else if(board[i-1][j+1] == 2 && board[i-2][j+2] == 0){
        eat(board, i-2, j+2, i-1, j+1, i, j, contador);
    } else {
        if(board[k][l] == 'y') {
            (*contador)++;
            return 0;
        } else if(k == 0){
            return 0;
        } else {
            back_one(board, i, j, k, l, m, n, contador);
        }
    }
}

void eat(int **board, int i, int j, int k, int l, int m, int n, int *contador){
    (*contador)++;
    board[i][j] = 1;
    board[k][l] = 0;
    board[m][n] = 0;
    check_diagonals(board, i, j, k, l, m, n, contador);
}

void back_one(int **board, int i, int j, int k, int l, int m, int n, int *contador){
    (*contador)--;
    board[i][j] = 0;
    board[k][l] = 'y';
    board[m][n] = 1;
    check_diagonals(board, m, n, k, l, i, j, contador);
}

