#include "conjuntos.h"
#include "uteis.h"

#include <stdio.h>
#include <stdlib.h>

int LerConjuntoA(float A[]){
    int i, qtd = 0;
    printf("Para fechar o conjunto, digite 0.\n\n");
    printf("Insira o conjunto A: ");
    for(i = 0; i < 100; i++){
        scanf("%f", &A[i]);
        qtd = i;
        if(A[i] == 0)
            break;
    }
    printf("\n");
    return qtd;
}

int LerConjuntoB(float B[]){
    int i, qtd = 0;
    printf("Insira o conjunto B: ");
    for(i = 0; i < 100; i++){
        scanf("%f", &B[i]);
        qtd = i;
        if(B[i] == 0)
            break;
    }
    return qtd;
}

void MostrarConjuntos(float A[], float B[], int qtdA, int qtdB){
    int i;
    printf("A = {");
    for(i=0; i<qtdA; i++)
        printf(" %.1f ", A[i]);
    printf("}\n");
    printf("B = {");
    for(i=0; i<qtdB; i++)
        printf(" %.1f ", B[i]);
    printf("}\n");
        
}

void Uniao(float A[], float B[], int qtdA, int qtdB){
    int i, j, k, total;
    float uniao[200];
    
    for(i = 0; i < qtdA; i++)
       uniao[i] = A[i];
    for(i = 0; i < qtdB; i++)
        uniao[i+qtdA] = B[i];
    total = qtdA+qtdB;
    qsort(uniao, total, sizeof(float), comparador);
    for(i = 0; i < total; i++){
        for(j = i+1; j < total;){
            if(uniao[j] == uniao[i]){
                for(k = j; k < total; k++)
                    uniao[k] = uniao[k+1];
                total--;
            }else
                j++;
        }
    }
    qsort(uniao, total, sizeof(float), comparador);
    printf("\n");
    printf("A U B = {");
    for(i = 0; i < total; i++)
           printf(" %.1f ", uniao[i]);
    printf("}");
    printf("\n");
}

void Interseccao(float A[], float B[], int qtdA, int qtdB){
    int i, j, k = 0, total = 0;
    float interseccao[100];
    for(i = 0; i < qtdA; i++){
        for(j = 0; j < qtdB; j++){
            if (A[i] == B[j]){
                interseccao[k] = A[i];
                k++;
                break;
            }
        }
    }
    total = k;
    for(i = 0; i < total; i++){
        for(j = i+1; j < total;){
            if(interseccao[j] == interseccao[i]){
                for(k = j; k < total; k++)
                    interseccao[k] = interseccao[k+1];
                total--;
            }else
                j++;
        }
    }
    qsort(interseccao, total, sizeof(float), comparador);
    printf("\n");
    printf("Interseccao = {");
    for(i = 0; i < k; i++)
        printf(" %.2f ", interseccao[i]);
    printf("}");
    printf("\n");
    
}

void Diferenca(float A[], float B[], int qtdA, int qtdB){
    int i, j, x, k = 0, achou = 0, total = 0;
    float diferenca[100];
    for(i = 0; i < qtdA; i++){
        x = A[i];
        achou = 0;
        for(j = 0; j < qtdB; j++){
            if (x == B[j]){
                achou = 1;
                break;
            }
        }
        if(achou == 0){
           diferenca[total] = x;
           total++;
        }
    }
    for(i = 0; i < total; i++){
        for(j = i+1; j < total;){
            if(diferenca[j] == diferenca[i]){
                for(k = j; k < total; k++)
                    diferenca[k] = diferenca[k+1];
                total--;
            }else
                j++;
        }
    }
    qsort(diferenca, total, sizeof(float), comparador);
    printf("\n");
    printf("A - B = {");
    for(i = 0; i < total; i++)
        printf(" %.1f ", diferenca[i]);
    printf("}");
    printf("\n");
}