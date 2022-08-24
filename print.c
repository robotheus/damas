#include <stdio.h>
#include "print.h"

void print_board(int **board, int n, int m){
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < m+2; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

