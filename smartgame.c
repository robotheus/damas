#include <stdio.h>
#include <stdlib.h>
#include "smartgame.h"

void smart_game(int **board, int n, int m){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(*(*(board + i) + j) == 1){
            //chamo a que checa  as diagonais mandando a copia do tabuleiro
            }
        }
    }
}

void ways(int **board, int i, int j, int x, int y){
    if(*(*(board + (i+1)) + (j+1)) == 2 && *(*(board + (i+2)) + (j+2)) == 0){
        //crio um nodo e coloco uma flag
    } 
    
    if(*(*(board + (i-1)) + (j-1)) == 2 && *(*(board + (i-2)) + (j-2)) == 0){
        //crio um nodo e coloco uma flag
    } 
    
    if(*(*(board + (i+1)) + (j-1)) == 2 && *(*(board + (i+2)) + (j-2)) == 0){
        //crio um nodo e coloco uma flag
    }
    
    if(*(*(board + (i-1)) + (j+1)) == 2 && *(*(board + (i-2)) + (j+2)) == 0){
        //crio um nodo e coloco uma flag
    }
}

tree *create_tree(int x){
    tree *board;
    board = (tree*) malloc(sizeof(tree));
    board->value = x;
    board->first = NULL;
    board->next = NULL;
    
    return board;
}

void insert(tree *board, tree *sub_board){
    sub_board->next = board->first;
    board->first = sub_board->next;
}

