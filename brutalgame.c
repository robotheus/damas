#include <stdio.h>
#include <stdlib.h>
#include "brutalgame.h"
#include "board.h"
#include "print.h"

void brutal_game(int **board, int n, int m){
    int *count, *max, **copy, k = 0, l = 0, o = 0, p = 0, password = 0, **point, *copy_count, pointi, pointj;
    
    count = malloc(sizeof(int));
    max = malloc(sizeof(int));
    copy_count = malloc(sizeof(int));
    copy = (int**)malloc((n+2) * sizeof(int*));
    point = (int**)malloc((n+2) * sizeof(int*));
    *max = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == 1){
                *count = 0;
                *copy_count = 0;
                create_board(copy, n, m);
                create_board(point, n, m);
                copy_board(copy, board, n, m);
                check_diagonals(copy, i, j, k, l, o, p, count, password, point, n, m, max, copy_count, pointi, pointj);
                clean_board(copy, n);
                clean_board(point, n);
            }
        }
    }
    
    printf("maior numero de jogadas: %d\n", *max);
    free(count);
    free(copy);
    free(point);
}

int check_diagonals(int **board, int i, int j, int k, int l, int m, int n, int *count, int password, int **point, int x, int y, int *max, int *copy_count, int pointi, int pointj){    
    if(password < 1){
        int ways = 0;
        if(board[i+1][j+1] == 2 && board[i+2][j+2] == 0) ways++;
        if(board[i-1][j-1] == 2 && board[i-2][j-2] == 0) ways++;
        if(board[i+1][j-1] == 2 && board[i+2][j-2] == 0) ways++;
        if(board[i-1][j+1] == 2 && board[i-2][j+2] == 0) ways++;

        if(ways > 1){
            copy_board(point, board, x, y);
            pointi = i;
            pointj = j;
            *copy_count = *count;
            password++;
        }
    }

    if(board[i+1][j+1] == 2 && board[i+2][j+2] == 0){
        eat(board, i+2, j+2, i+1, j+1, i, j, count, password, point, x, y, max, copy_count, pointi, pointj);
    } else if(board[i-1][j-1] == 2 && board[i-2][j-2] == 0){
        eat(board, i-2, j-2, i-1, j-1, i, j, count, password, point, x, y, max, copy_count, pointi, pointj);
    } else if(board[i+1][j-1] == 2 && board[i+2][j-2] == 0){
        eat(board, i+2, j-2, i+1, j-1, i, j, count, password, point, x, y, max, copy_count, pointi, pointj);
    } else if(board[i-1][j+1] == 2 && board[i-2][j+2] == 0){
        eat(board, i-2, j+2, i-1, j+1, i, j, count, password, point, x, y, max, copy_count, pointi, pointj);
    } else {   
        //printf("chegou\n");
        if(point[pointi+1][pointj+1] != 2 && point[pointi-1][pointj-1] != 2 && point[pointi+1][pointj-1] != 2 && point[pointi-1][pointj+1] != 2){
            return 0;
        } else if(board[k][l] == 'y'){
            (*count)++;
            *count = *copy_count;
            //clean_flags(point, x, y);
            point[k][l] = 'y';
            copy_board(board, point, x, y);
            check_diagonals(board, pointi, pointj, k, l, m, n, count, password, point, x, y, max, copy_count, pointi, pointj);
        } else if(k == 0) {
            return 0;
        } else {
            back_one(board, i, j, k, l, m, n, count, password, point, x, y, max, copy_count, pointi, pointj);
        }
    }
}

void clean_flags(int **point, int x, int y){
    for(int i = 0; i < x+2; i++){
        for(int j = 0; j < y+2; j++){
            if(point[i][j] == 'y') point[i][j] = 2;
        }
    }
}


void eat(int **board, int i, int j, int k, int l, int m, int n, int *count, int password, int **point, int x, int y, int *max, int *copy_count, int pointi, int pointj){
    (*count)++;
    if(*count > *max) *max = *count;
    board[i][j] = 1;
    board[k][l] = 0;
    board[m][n] = 0;
    check_diagonals(board, i, j, k, l, m, n, count, password, point, x, y, max, copy_count, pointi, pointj);
}

void back_one(int **board, int i, int j, int k, int l, int m, int n, int *count, int password, int **point, int x, int y, int *max, int *copy_count, int pointi, int pointj){
    (*count)--;
    board[i][j] = 0;
    board[k][l] = 'y';
    board[m][n] = 1;
    check_diagonals(board, m, n, k, l, i, j, count, password, point, x, y, max, copy_count, pointi, pointj);
}