#include <stdio.h>
#include <stdlib.h>
#include "smartgame.h"

void smart_game(int **board, int n, int m){
    int count, *max;
    nodo **tree;

    max = malloc(sizeof(int));
    *max = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(*(*(board + i) + j) == 1){
                count = 0;
                create_tree(tree);
                ways(board, i, j, count, tree);
                get_max(tree, max);
            }
        }
    }

    printf("maior numero de pecas comidas: %d\n", *max);
}

int ways(int **board, int i, int j, int count, nodo **tree){
    if(*(*(board + (i+1)) + (j+1)) == 2 && *(*(board + (i+2)) + (j+2)) == 0){
        count++;
        *(*(board + (i+1)) + (j+1)) == 'y';
        insert(tree, count);
        ways(board, i+2, j+2, count, tree);
    } else if(*(*(board + (i-1)) + (j-1)) == 2 && *(*(board + (i-2)) + (j-2)) == 0){
        count++;
        *(*(board + (i-1)) + (j-1)) == 'y';
        insert(tree, count);
        ways(board, i-2, j-2, count, tree);
    } else if(*(*(board + (i+1)) + (j-1)) == 2 && *(*(board + (i+2)) + (j-2)) == 0){
        count++;
        *(*(board + (i+1)) + (j-1)) == 'y';
        insert(tree, count);
        ways(board, i+2, j-2, count, tree);
    } else if(*(*(board + (i-1)) + (j+1)) == 2 && *(*(board + (i-2)) + (j+2)) == 0){
        count++;
        *(*(board + (i-1)) + (j+1)) == 'y';
        insert(tree, count);
        ways(board, i-2, j+2, count, tree);
    } else return 0;
}

int create_tree(nodo **root){
    *root = NULL;

    if(*root == NULL){
        *root = (nodo *)malloc(sizeof(nodo));
        (*root)->right = NULL;
        (*root)->left = NULL;
        (*root)->value = 0;
        return 0;
    }
}

int insert(nodo **root, int value){
    if(*root == NULL){
        *root = (nodo *)malloc(sizeof(nodo));
        (*root)->right = NULL;
        (*root)->left = NULL;
        (*root)->value = value;
        return 0;
    } else if(value > ((*root)->value)){
        insert(&(*root)->left, value);
        return 0;
    } else {
        insert(&(*root)->right, value);
        return 0;
    }
}

int get_max(nodo **root, int *max){
    if(*root == NULL) return 0;
    else if((*root)->value >= *max){
        *max = (*root)->value;
        printf("pegou %d\n", *max);
        get_max(&(*root)->left, max);
    }
}