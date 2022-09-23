#include <stdio.h>
#include <stdlib.h>
#include "smartgame.h"
#include "board.h"
#include "file.h"

void smart_game(int **board, int n, int m){
    int count, *max;
    nodo *tree;

    max = malloc(sizeof(int));
    *max = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(*(*(board + i) + j) == 1){
                count = 0;
                create_tree(&tree);
                ways(board, i, j, count, &tree, n, m);
                get_max(&tree, max);
            }
        }
    }

    //output(*max, n, m);
    printf("%d eh a maior sequencia de jogadas da inteligente.\n", *max);
    free(max);
    free(tree);
}


int ways(int **board, int i, int j, int count, nodo **tree, int n, int m){
    count++;

    if(*(*(board + (i+1)) + (j+1)) == 2 && *(*(board + (i+2)) + (j+2)) == 0){
        insert(tree, count);
        
        int **copy = (int**)malloc((n+2) * sizeof(int*));
        create_board(copy, n, m);
        copy_board(copy, board, n, m);
        
        *(*(copy + (i+2)) + (j+2)) = 1;
        *(*(copy + (i+1)) + (j+1)) = 0;
        *(*(copy + i) + j) = 0;
        printf("%d\n", count);
        ways(copy, i+2, j+2, count, tree, n, m);
        clean_board(copy, n);
        free(copy);
        
    } 
    
    if(*(*(board + (i-1)) + (j-1)) == 2 && *(*(board + (i-2)) + (j-2)) == 0){
        insert(tree, count);
        
        int **copy = (int**)malloc((n+2) * sizeof(int*));
        create_board(copy, n, m);
        copy_board(copy, board, n, m);
        
        *(*(copy + (i-2)) + (j-2)) = 1;
        *(*(copy + (i-1)) + (j-1)) = 0;
        *(*(copy + i) + j) = 0;
        printf("%d\n", count);
        ways(copy, i-2, j-2, count, tree, n, m);
        clean_board(copy, n);
        free(copy);
        
    } 
    
    if(*(*(board + (i+1)) + (j-1)) == 2 && *(*(board + (i+2)) + (j-2)) == 0){
        insert(tree, count);
        
        int **copy = (int**)malloc((n+2) * sizeof(int*));
        create_board(copy, n, m);
        copy_board(copy, board, n, m);
        
        *(*(copy + (i+2)) + (j-2)) = 1;
        *(*(copy + (i+1)) + (j-1)) = 0;
        *(*(copy + i) + j) = 0;
        printf("%d\n", count);
        ways(copy, i+2, j-2, count, tree, n, m);
        clean_board(copy, n);
        free(copy);
        
    } 
    
    if(*(*(board + (i-1)) + (j+1)) == 2 && *(*(board + (i-2)) + (j+2)) == 0){
        insert(tree, count);
        
        int **copy = (int**)malloc((n+2) * sizeof(int*));
        create_board(copy, n, m);
        copy_board(copy, board, n, m);
        
        *(*(copy + (i-2)) + (j+2)) = 1;
        *(*(copy + (i-1)) + (j+1)) = 0;
        *(*(copy + i) + j) = 0;
        printf("%d\n", count);
        ways(copy, i-2, j+2, count, tree, n, m);
        clean_board(copy, n);
        free(copy);
    }

    return 0;
}

int create_tree(nodo **root){
    *root = NULL;
    
    if (*root = NULL){
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
    else {
        if((*root)->value >= *max) *max = (*root)->value;
        get_max(&(*root)->left, max);
    }
}