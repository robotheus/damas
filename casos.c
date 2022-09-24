#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void main(){
    double n, m, a, b;
    int minhas = 0, oponente = 0, max_pecas;;

    for(int k = 0; k < 100; k++){
        inicio:
        srand(time(NULL));

        for(int i = 0; i < 1;){
            n = rand() % 21;
            m = rand() % 21;
            if(n >= 3 && n <= 20){
                if(m >= 3 && m <= 20){
                    if(n*m <= 200){
                        i++;
                    }
                }
            }
        }

        max_pecas = ceil((n*m)/2.0);
        int pecas[max_pecas];

        for(int i = 1; i <= max_pecas; i++){
            pecas[i] = rand() % 3;
        }

        for(int i = 1; i <= max_pecas; i++){
            if(pecas[i] == 1) minhas++;
            else if(pecas[i] == 2) oponente++;
        }

        if(minhas > floor((n*m)/4.0)){
            break;
        } else if(oponente > floor((n*m)/4.0)){
            break;
        }
        
        printf("%.0lf %.0lf\n", n, m);

        for(int i = 1; i <= max_pecas; i++){
            printf("%d ", pecas[i]);
        }

        printf("\n");
    }
}