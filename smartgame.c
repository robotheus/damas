#include <stdio.h>
#include <stdlib.h>
#include "smartgame.h"

void smart_game(int **board, int n, int m){
    int *count, *max;
    nodo **tree;

    count = malloc(sizeof(int));
    max = malloc(sizeof(int));
    *max = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(*(*(board + i) + j) == 1){
            *count = 0;
            /*create_tree(tree);
            insert(tree, count);
            ways(board, i, j, *count);
            //chamo a que checa  as diagonais mandando a copia do tabuleiro
            */
            }
        }
    }

    printf("maior numero de pecas comidas: %d\n", *max);
}

int ways(int **board, int i, int j, int *count){
    if(*(*(board + (i+1)) + (j+1)) == 2 && *(*(board + (i+2)) + (j+2)) == 0){
        (*count)++;
        *(*(board + (i+1)) + (j+1)) == 'y';
        ways(board, i+2, j+2, count);
    } 
    
    if(*(*(board + (i-1)) + (j-1)) == 2 && *(*(board + (i-2)) + (j-2)) == 0){
        (*count)++;
        *(*(board + (i-1)) + (j-1)) == 'y';
        ways(board, i-2, j-2, count);
    } 
    
    if(*(*(board + (i+1)) + (j-1)) == 2 && *(*(board + (i+2)) + (j-2)) == 0){
        (*count)++;
        *(*(board + (i+1)) + (j-1)) == 'y';
        ways(board, i+2, j-2, count);
    }
    
    if(*(*(board + (i-1)) + (j+1)) == 2 && *(*(board + (i-2)) + (j+2)) == 0){
        (*count)++;
        *(*(board + (i-1)) + (j+1)) == 'y';
        ways(board, i-2, j+2, count);
    }
}

void create_tree(nodo **root){
    *root = NULL;
}

void insert(nodo **root, int value){
    if(*root == NULL){
        *root = (nodo *)malloc(sizeof(nodo));
        (*root)->right = NULL;
        (*root)->left = NULL;
        (*root)->value = value;
    } else {
        if(value <= ((*root)->value)){
            insert(&(*root)->left, value);
        } else {
            insert(&(*root)->right, value);
        }
    }
}

void get_max(nodo *root, int *max){
    if(root){
        if((*root).value > *max) *max = (*root).value;
        get_max(root->left, max);
    }
}