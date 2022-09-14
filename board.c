#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "file.h"
#include "brutalgame.h"
#include <math.h>

void create_board(int **board, int n, int m){
    //cria um vetor de ponteiros (que é a matriz)
    for(int i = 0; i < n+2; i++){
        *(board + i) = (int*) malloc((m+2) * sizeof(int*));
    }

    //preenche todo a matriz com zero
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < m+2; j++){
            *(*(board + i) + j) = 0;
        }
    }

    //forma a borda
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < m+2; j++){
            if((i == 0 || i == (n+2)-1)){
                *(*(board + i) + j) = 3;
            } else if (j == 0 || j == (m+2)-1){
                *(*(board + i) + j) = 3;
            }
        }
    }
}

void fill_board(int **board, int n, int m){
    for(int y = 1; y <= n; y++){
        if(y % 2 != 0){
            for(int x = 1; x <= m; x += 2){
                *(*(board + y) + x) = read_file();
            }
        } else {
            for(int x = 2; x <= m; x += 2){
                *(*(board + y) + x) = read_file();
            }
        }
    }
}

void copy_board(int **copy, int **board, int n, int m){
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < m+2; j++){
            *(*(copy + i) + j) = *(*(board + i) + j);
        }
    }
}

void clean_board(int **board, int n){
    for(int i = 0; i < n+2; i++){
        free(*(board + i));
    }
}

int validate_board(int **board, int n, int m){
    double me = 0, opponent = 0, voidd = 0, total = 0;

    if(n >= 3 && n <= 20 && m >= 3 && m <= 20 && (n*m) <= 200){
        for(int y = 1; y <= n; y++){
            if(y % 2 != 0){
                for(int x = 1; x <= m; x += 2){
                    if(*(*(board + y) + x) == 2) opponent++;
                    else if(*(*(board + y) + x) == 1) me++;
                    else if (*(*(board + y) + x) == 0) voidd++;
                    else return 0;

                    total++;
                }
            } else {
                for(int x = 2; x <= m; x += 2){
                    if(*(*(board + y) + x) == 2) opponent++;
                    else if(*(*(board + y) + x) == 1) me++;
                    else if (*(*(board + y) + x) == 0) voidd++;
                    else return 0;

                    total++;
                }
            }
        }
    } else return 0;

    if(me <= ((n*m)/4.0) && opponent <= ((n*m)/4.0) && total == ceil(((n*m)/2.0))){
        return 1;
    } else return 0;
}