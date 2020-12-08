#include <stdio.h>
#include <stdlib.h>

#include "conjuntos.h"
#include "uteis.h"

int main(){
    int qtdA, qtdB, fim = 0;
    float A[100], B[100];
    while (!fim){
        switch (menu()){
            case 1:
                limparTela();
                qtdA = LerConjuntoA(A);
                qtdB = LerConjuntoB(B);
                printf("Conjuntos inseridos com sucesso!\n");
                pausar();
                break;
            case 2:
                limparTela();
                MostrarConjuntos(A, B, qtdA, qtdB);
                Uniao(A, B, qtdA, qtdB);
                pausar();
                break;
            case 3:
                limparTela();
                MostrarConjuntos(A, B, qtdA, qtdB);
                Interseccao(A, B, qtdA, qtdB);
                pausar();
                break;
            case 4:
                limparTela();
                MostrarConjuntos(A, B, qtdA, qtdB);
                Diferenca(A, B, qtdA, qtdB);
                pausar();
                break;
            case 5:
                fim = 1;
                break;
            default:
                printf("Opcao invalida!\n");
                pausar();
                break;
        }
    }

}