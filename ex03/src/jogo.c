#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>

void Inicializar(char jogo[3][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++)
            jogo[i][j] = ' ';
    }
}

int CoordenadaDisponivel(char jogo [3][3], int x, int y){
    if(jogo[x-1][y-1] != 'X' && jogo[x-1][y-1] != 'O')
        return 1;
    else 
        return 0;
}

void InserirJogada(char jogo[3][3], int x, int y, int j){
    if (j%2 == 0){
        if(CoordenadaDisponivel(jogo, x, y))
             jogo[x-1][y-1] = 'X';
    }else{
        if(CoordenadaDisponivel(jogo, x, y))
             jogo[x-1][y-1] = 'O';
    }
}   

int VitoriaLinhas(char jogo[3][3]) {
    int i, j, igual = 1;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            if(ValidarSimbolo(jogo[i][j]) && jogo[i][j] == jogo[i][j+1])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}

int VitoriaColunas(char jogo[3][3]){
    int i, j, igual = 1;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            if(ValidarSimbolo(jogo[j][i]) && jogo[j][i] == jogo[j+1][i])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;

}

int VitoriaDiagonal1(char jogo[3][3]){
    if(ValidarSimbolo(jogo[0][0]) && jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2])
        return 1;
    return 0;
}

int VitoriaDiagonal2(char jogo[3][3]){
    if(ValidarSimbolo(jogo[0][2]) && jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0])
        return 1;
    return 0;
}


void MostrarTabuleiro(char tabuleiro[3][3]){
    printf("\t\t       %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("\t\t      -----------\n");
    printf("\t\t       %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("\t\t      -----------\n");
    printf("\t\t       %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

void Jogar(char jogo[3][3]){
    char simbolo = 'X';
    int x, y, jogadas = 1, v = 0;
    do{
        printf("Jogador %c - Escolha as coordenadas da jogada: ", simbolo);
        scanf("%d %d", &x, &y);
        if(Validar(x, y)){
            jogadas++;
            InserirJogada(jogo, x, y, jogadas);
            MostrarTabuleiro(jogo);
        }
        if (jogadas%2 == 0)
            simbolo = 'O';
        else if (jogadas%2 != 0)
            simbolo = 'X';
        v += VitoriaLinhas(jogo);
        v += VitoriaColunas(jogo);
        v += VitoriaDiagonal1(jogo);
        v += VitoriaDiagonal2(jogo);
    }while (v == 0 && jogadas <= 9);
    if(v > 0 && jogadas%2 == 0)
        printf("Vitoria do Jogador X!\n");
    else if (v > 0 && jogadas%2 != 0)
        printf("Vitoria do Jogador O!\n");
    else
        printf("Deu velha!\n");
    
}