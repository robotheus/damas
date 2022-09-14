#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include "file.h"
#include "board.h"
#include "print.h"
#include "brutalgame.h"
#include "times.h"
#include "smartgame.h"

void main(int argc, char *argv[]){
    struct timeval start, end;
    struct rusage start_s, end_s;
    int **board;
    int n, m; 
    float user_time = 0, system_time = 0;

    open_file(argv[2], argv[4]);
    
    while(1){
        n = read_file();
        m = read_file();
        
        if(n == 0 || m == 0) break;
        
        board = (int**)malloc((n+2) * sizeof(int*));
        create_board(board, n, m);
        fill_board(board, n, m);
        
        if(validate_board(board, n, m) == 1){
            gettimeofday(&start, NULL);
            getrusage(RUSAGE_SELF, &start_s);
            //brutal_game(board, n, m);
            smart_game(board, n, m);
            getrusage(RUSAGE_SELF, &end_s);
            gettimeofday(&end, NULL);
            
            user_time += user_time_difference(&start, &end);
            system_time += system_time_difference(&start_s, &end_s);
            //print_board(board, n, m);
            
            clean_board(board, n);
            free(board);
        } else {
            output(-1, n, m);
            break;
        }
    }

    printf("Tempo de usuario na forca bruta: %.10f sec\n", user_time);
    printf("Tempo de sistema na forca bruta: %.10f sec\n", system_time);
    
    close_file();
}