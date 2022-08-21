#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "board.h"

void main(int argc, char *argv[]){
    int n, m, **board;
    
    open_file(argv[2]);
    
    while(1){
        if(n == 0 || m == 0) break;
        
        n = read_file();
        m = read_file();

        board = (int**)malloc(n * sizeof(int*));
        create_board(board, n, m);

        for(int i = n; i >= 1; i--){
            for(int j = 1; j <= m; j++){
                printf("%d ", board[j][i]);
            }
            printf("\n");
        }

        printf("\n");
    }
}