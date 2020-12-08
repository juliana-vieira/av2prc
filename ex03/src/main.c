#include "validar.h"
#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>


int main(){
    char jogo[3][3], resp;
    
    printf("\t\t=========================\n");
    printf("\t\t J O G O  D A  V E L H A\n");
    printf("\t\t=========================\n");
    do{
        Inicializar(jogo);
        MostrarTabuleiro(jogo);
        Jogar(jogo);
        printf("Deseja jogar de novo? [s/n]:");
        scanf(" %c", &resp);
    }while(resp == 's');
    
    return 0;
}