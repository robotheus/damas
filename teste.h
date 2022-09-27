#include <stdio.h>
#include <stdlib.h>

typedef struct tabuleiro {
    int linhas;
    int colunas;
    char* posicoes;
    char* posicoesMod;
    int** casas;
    int** vetorCasas;
    int pecasJogador;

} Tabuleiro;

Tabuleiro* criaTabuleiro(int linhas, int colunas, char posicoes[]);

int printaTabuleiro(Tabuleiro *tabuleiro);

int printaCasas(Tabuleiro *tabuleiro);

int printaCasasJogador(Tabuleiro *tabuleiro);

int verificaTabuleiro(Tabuleiro *tabuleiro);

char* addEspaco(char* posicoes);

char* retiraEspaco(char* posicoes);

int forcaBruta(Tabuleiro *tabuleiro);