#include <stdio.h>
#include <stdlib.h>
#include "brutalgame.h"
#include "board.h"

void eat(int **board, int i, int j, int k, int l, int m, int n, int *contador){
    board[i][j] = 'x'; //coloco 1
    board[k][l] = 'y'; //coloco 2
    board[m][n] = 'z'; //coloco 0
    check_diagonals(board, i, j, contador);
}

void reverse_eat(int **board, int i, int j, int k, int l, int m, int n){
    board[i][j] = 0; //coloco x
    board[k][l] = 2; //coloco y
    board[m][n] = 0; //coloco z
    reset_board(board, i, j);
}

void check_diagonals(int **board, int i, int j, int *contador){
    if(board[i+1][j+1] == 2 && (board[i+2][j+2] == 0 || board[i+2][j+2] == 'z')){
        (*contador)++;
        eat(board, i+2, j+2, i+1, j+1, i, j, contador);
    } else if(board[i-1][j-1] == 2 && (board[i-2][j-2] == 0 || board[i-2][j-2] == 'z')){
        (*contador)++;
        eat(board, i-2, j-2, i-1, j-1, i, j, contador);
    } else if(board[i+1][j-1] == 2 && (board[i+2][j-2] == 0 || board[i+2][j-2] == 'z')){
        (*contador)++;
        eat(board, i+2, j-2, i+1, j-1, i, j, contador);
    } else if(board[i-1][j+1] == 2 && (board[i-2][j+2] == 0 || board[i-2][j+2] == 'z')){
        (*contador)++;
        eat(board, i-2, j+2, i-1, j+1, i, j, contador);
    } else {
        reset_board(board, i, j);
    }
}

void brutal_game(int **board, int n, int m){
    int *contador, max = 0;
    contador = malloc(sizeof(int));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == 1){
                *contador = 0;
                check_diagonals(board, i, j, contador);
            }

            if(*contador > max){
                max = *contador;
            }
        }
    }

    printf("maior numero de jogadas: %d\n", max);
    free(contador);
}