#include <stdio.h>
#include "print.h"

void print_board(int **board, int n, int m){
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= m; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

