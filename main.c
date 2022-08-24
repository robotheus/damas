#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "board.h"
#include "print.h"
#include "brutalgame.h"

void main(int argc, char *argv[]){
    
    int n, m, **board;

    open_file(argv[2]);
    
    while(1){
        if(n == 0 || m == 0) break;
        
        n = read_file();
        m = read_file();

        board = (int**)malloc((n+2) * sizeof(int*));
        create_board(board, n, m);
        print_board(board, n, m);
        brutal_game(board, n, m);

        clean_board(board, n);
        free(board);
    }

    close_file();

}