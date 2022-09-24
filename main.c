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
    struct timeval startb, endb, starti, endi;
    struct rusage start_sb, end_sb, start_si, end_si;
    int **board;
    int n, m; 
    float user_time_b = 0, system_time_b = 0, user_time_i = 0, system_time_i = 0;

    open_file(argv[2], argv[4]);
    
    while(1){
        n = read_file();
        m = read_file();
        
        if(n == 0 || m == 0) break;
        
        board = (int**)malloc((n+2) * sizeof(int*));
        create_board(board, n, m);
        fill_board(board, n, m);
        
        if(validate_board(board, n, m) == 1){
            gettimeofday(&startb, NULL);
            getrusage(RUSAGE_SELF, &start_sb);
            brutal_game(board, n, m);
            getrusage(RUSAGE_SELF, &end_sb);
            gettimeofday(&endb, NULL);
            user_time_b += user_time_difference(&startb, &endb);
            system_time_b += system_time_difference(&start_sb, &end_sb);
            
            gettimeofday(&starti, NULL);
            getrusage(RUSAGE_SELF, &start_si);
            smart_game(board, n, m);
            getrusage(RUSAGE_SELF, &end_si);
            gettimeofday(&endi, NULL);
            user_time_i += user_time_difference(&starti, &endi);
            system_time_i += system_time_difference(&start_si, &end_si);

            clean_board(board, n);
            free(board);
        } else {
            output(-1, n, m);
            break;
        }
    }

    printf("Tempo de usuario na FB: %.10f sec\n", user_time_b);
    printf("Tempo de sistema na FB: %.10f sec\n\n", system_time_b);
    printf("Tempo de usuario na SI: %.10f sec\n", user_time_i);
    printf("Tempo de sistema na SI: %.10f sec\n", system_time_i);
    
    close_file();
}