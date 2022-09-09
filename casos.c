#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void main(){
    double n, m, a, b;
    int minhas = 0, oponente = 0, max_pecas;;
    srand(time(NULL));

    for(int i = 0; i < 1;){
        n = rand() % 20;
        m = rand() % 20;
        if(n >= 3 && n <= 20){
            if(m >= 3 && m <= 20){
                if(n*m <= 200){
                    i++;
                }
            }
        }
    }
    a = (n*m)/2.0;
    b = (n*m)/4.0;

    printf("%.0lf %.0lf\n", n, m);
    max_pecas = ceil(a);
    int pecas[max_pecas];

    //inicio:
    for(int i = 1; i <= max_pecas; i++){
        pecas[i] = rand() % 3;
    }

    for(int i = 1; i <= max_pecas; i++){
        if(pecas[i] == 1) minhas++;
        else if(pecas[i] == 2) oponente++;
    }

    if(minhas > floor(b)){
        printf("erro\n");
    } else if(oponente > floor((n*m)/4.0)){
        printf("erro\n");
    }
    
    for(int i = 1; i <= max_pecas; i++){
        printf("%d ", pecas[i]);
    }

    printf("\n");
}