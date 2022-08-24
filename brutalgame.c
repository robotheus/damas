#include <stdio.h>
#include "brutalgame.h"

void brutal_game(int **board, int n, int m){
    int jogadas = 0;

    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < m+2; j++){
            if(board[i][j] == 1){
                printf("tem 1\n");
                if(board[i+1][j-1] == 2){
                    printf("tem 2\n");
                    if(board[i+2][j-2] == 0){
                        printf("tem 0\n");
                        jogadas++;
                    }
                } else if(board[i-1][j+1] == 2){
                    printf("tem 2\n");
                    if(board[i-2][j+2] == 0){
                        printf("tem 0\n");
                        jogadas++;
                    }
                } else if(board[i+1][j+1] == 2){
                    printf("tem 2\n");
                    if(board[i+2][j+2] == 0){
                        printf("tem 0\n");
                        jogadas++;
                    }
                }  else if(board[i-1][j-1] == 2){
                    printf("tem 2\n");
                    if(board[i-2][j-2] == 0){
                        printf("tem 0\n");
                        jogadas++;
                    }
                }
            }
        }
    }

    //printf("%d\n", jogadas);
}