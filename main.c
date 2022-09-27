#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include "file.h"
#include "board.h"
#include "print.h"
#include "algorithm1.h"
#include "times.h"
#include "algorithm2.h"

void main(int argc, char *argv[]){
    struct timeval startb, endb, starti, endi;
    struct rusage start_sb, end_sb, start_si, end_si;
    int **board;
    int lines, columns; 
    float user_time_b = 0, system_time_b = 0, user_time_i = 0, system_time_i = 0;

    open_file(argv[2], argv[4]);
    
    while(1){
        lines = read_file();
        columns = read_file();
        
        if(lines == 0 || columns == 0) break;
        
        board = (int**)malloc((lines+2) * sizeof(int*));
        create_board(board, lines, columns);
        fill_board(board, lines, columns);
        
        if(validate_board(board, lines, columns) == 1){            
            gettimeofday(&startb, NULL);
            getrusage(RUSAGE_SELF, &start_sb);
            algorithm1(board, lines, columns);
            getrusage(RUSAGE_SELF, &end_sb);
            gettimeofday(&endb, NULL);
            user_time_b += user_time_difference(&startb, &endb);
            system_time_b += system_time_difference(&start_sb, &end_sb);
            
            gettimeofday(&starti, NULL);
            getrusage(RUSAGE_SELF, &start_si);
            algorithm2(board, lines, columns);
            getrusage(RUSAGE_SELF, &end_si);
            gettimeofday(&endi, NULL);
            user_time_i += user_time_difference(&starti, &endi);
            system_time_i += system_time_difference(&start_si, &end_si);
            
            clean_board(board, lines);
            free(board);
        } else {
            output(-1, lines, columns);
            break;
        }
    }

    printf("Tempo de usuario no algoritmo I: %.10f sec\n", user_time_b);
    printf("Tempo de sistema no algoritmo I: %.10f sec\n\n", system_time_b);
    printf("Tempo de usuario no algoritmo II: %.10f sec\n", user_time_i);
    printf("Tempo de sistema no algoritmo II: %.10f sec\n", system_time_i);
    
    close_file();
}