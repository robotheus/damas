#include <stdio.h>
#include <stdlib.h>
#include "algorithm2.h"
#include "board.h"
#include "file.h"
#include "print.h"

void algorithm2(int **board, int n, int m){
    int count, *max, **copyboard;
    nodo *tree;

    max = malloc(sizeof(int));
    copyboard = (int**)malloc((n+2) * sizeof(int*));
    *max = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(*(*(board + i) + j) == 1){
                count = 0;
                create_board(copyboard, n, m);
                copy_board(copyboard, board, n, m);
                create_tree(&tree);
                ways(copyboard, i, j, count, &tree, n, m);
                clean_board(copyboard, n);
                get_max(&tree, max);
                free_tree(&tree);
            }
        }
    }
    //output(*max, n, m);
    free(max);
    free(copyboard);
}


int ways(int **board, int i, int j, int count, nodo **tree, int n, int m){
    count++;

    if(*(*(board + (i+1)) + (j+1)) == 2 && *(*(board + (i+2)) + (j+2)) == 0){
        if(insert(tree, count, 0) == -1) return 0;
        
        int **copy = (int**)malloc((n+2) * sizeof(int*));
        create_board(copy, n, m);
        copy_board(copy, board, n, m);
        
        *(*(copy + (i+2)) + (j+2)) = 1;
        *(*(copy + (i+1)) + (j+1)) = 0;
        *(*(copy + i) + j) = 0;
        
        ways(copy, i+2, j+2, count, tree, n, m);
        
        clean_board(copy, n);
        free(copy);
        
    } 
    
    if(*(*(board + (i-1)) + (j-1)) == 2 && *(*(board + (i-2)) + (j-2)) == 0){
        if(insert(tree, count, 0) == -1) return 0;
        
        int **copy = (int**)malloc((n+2) * sizeof(int*));
        create_board(copy, n, m);
        copy_board(copy, board, n, m);
        
        *(*(copy + (i-2)) + (j-2)) = 1;
        *(*(copy + (i-1)) + (j-1)) = 0;
        *(*(copy + i) + j) = 0;
        
        ways(copy, i-2, j-2, count, tree, n, m);
        
        clean_board(copy, n);
        free(copy);
        
    } 
    
    if(*(*(board + (i+1)) + (j-1)) == 2 && *(*(board + (i+2)) + (j-2)) == 0){
        if(insert(tree, count, 0) == -1) return 0;
        
        int **copy = (int**)malloc((n+2) * sizeof(int*));
        create_board(copy, n, m);
        copy_board(copy, board, n, m);
        
        *(*(copy + (i+2)) + (j-2)) = 1;
        *(*(copy + (i+1)) + (j-1)) = 0;
        *(*(copy + i) + j) = 0;
        
        ways(copy, i+2, j-2, count, tree, n, m);
        
        clean_board(copy, n);
        free(copy);
        
    } 
    
    if(*(*(board + (i-1)) + (j+1)) == 2 && *(*(board + (i-2)) + (j+2)) == 0){
        if(insert(tree, count, 0) == -1) return 0;
        
        int **copy = (int**)malloc((n+2) * sizeof(int*));
        create_board(copy, n, m);
        copy_board(copy, board, n, m);
        
        *(*(copy + (i-2)) + (j+2)) = 1;
        *(*(copy + (i-1)) + (j+1)) = 0;
        *(*(copy + i) + j) = 0;
        
        ways(copy, i-2, j+2, count, tree, n, m);
        
        clean_board(copy, n);
        free(copy);
    }

}

int create_tree(nodo **root){
    *root = NULL;
    
    if (*root == NULL){
        *root = (nodo *)malloc(sizeof(nodo));
        (*root)->right = NULL;
        (*root)->left = NULL;
        (*root)->value = 0;
        return 0;
    }
}

int insert(nodo **root, int value, int nmbchild){
    if(*root == NULL){
        *root = (nodo *)malloc(sizeof(nodo));
        (*root)->right = NULL;
        (*root)->left = NULL;
        (*root)->value = value;
        return 0;
    } else if(value > ((*root)->value)){
        insert(&(*root)->left, value, nmbchild);
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

int free_tree(nodo **root){
    if(!(*root)) return 0;
        free_tree(&(*root)->right);
        free_tree(&(*root)->left);
        free(*root);
}