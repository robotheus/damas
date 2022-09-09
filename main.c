#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "board.h"
#include "print.h"
#include "brutalgame.h"

void main(int argc, char *argv[]){
    
    int**board;
    int n, m;

    open_file(argv[2]);
    
    while(1){
        n = read_file();
        m = read_file();
        if(n == 0 || m == 0) break;

        if(n >= 3 && n <= 20 && m >= 3 && m <= 20 && (n*m) <= 200){
            board = (int**)malloc((n+2) * sizeof(int*));
            create_board(board, n, m);
            fill_board(board, n, m);
            brutal_game(board, n, m);
            print_board(board, n, m);
            clean_board(board, n);
            free(board);    
        }
    }

    close_file();

}