#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "board.h"
#include "print.h"
#include "brutalgame.h"

void main(int argc, char *argv[]){
    
    int**board;
    int n, m;

    open_file(argv[2], argv[4]);
    
    while(1){
        n = read_file();
        m = read_file();
        if(n == 0 || m == 0) break;

        board = (int**)malloc((n+2) * sizeof(int*));
        create_board(board, n, m);
        fill_board(board, n, m);
        if(validate_board(board, n, m) == 1){
            brutal_game(board, n, m);
            clean_board(board, n);
            free(board);
        } else {
            printf("O tabuleiro %dx%d eh invalido, retire a entrada e execute novamente.\n", n, m);
            break;
        }
    }

    close_file();
}