#include "brinquedos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Inserir(TEstoque *e, TBrinquedo b){
    (*e).v[(*e).qtd_estoque] = b;
    (*e).qtd_estoque++;
}

void LerBrinquedo(TBrinquedo *b){
    printf("Digite o codigo: ");
    scanf("%d", &(*b).cod);
    fflush(stdin);
    printf("Digite a categoria: ");
    LerStr((*b).categoria, MAXCATEGORIA);
    printf("Digite o nome: ");
    LerStr((*b).nome, MAXNOME);
    printf("Digite o preco: R$ ");
    scanf("%lf", &(*b).preco);
    printf("Digite a quantidade: ");
    scanf("%d", &(*b).qtd);
}

int BrinquedoExistente(TEstoque e, int info){
    int existe, i;
    existe = 0;
    i = 0;
    while(!existe && i < e.qtd_estoque)
        if(e.v[i].cod == info)
            existe = 1;
        else
            i++;

    return existe ? i : -1;
}

int Remover(TEstoque *e, int info1, int info2){
    int p, removeu = 0;
    p = BrinquedoExistente(*e, info1);
    if (p > -1){
        if((*e).v[p].qtd > 0 && info2 <= (*e).v[p].qtd){
           (*e).v[p].qtd--;
            removeu = 1;
        }else if ((*e).v[p].qtd == 0){
            (*e).v[p] = (*e).v[(*e).qtd_estoque-1];
            (*e).qtd_estoque--;
            removeu = 1;
        }else if (info2 > (*e).v[p].qtd)
            removeu = 2;
    }
     return removeu;
}

void Atualizar(TEstoque *e, int info, TBrinquedo b){
    int p;
    p = BrinquedoExistente(*e, info);
    if (p > -1)
        (*e).v[p] = b;
}

int ListarCategoria(TEstoque e, char info[]){
    int i;
    for(i=0; i<e.qtd_estoque; i++){
        if (strcmp(e.v[i].categoria, info) == 0){
            printf("Codigo: %d\n", e.v[i].cod);
            printf("Categoria: %s\n", e.v[i].categoria);
            printf("Nome: %s\n", e.v[i].nome);
            printf("Preco: R$ %.2lf\n", e.v[i].preco);
            printf("Quantidade: %d\n", e.v[i].qtd);
            printf("----------------------------------\n");
            return 1;
        }
    }
    return 0;
}

int Filtrar(TEstoque e, char info[]){
    int i;
    for(i=0; i<e.qtd_estoque; i++){
        if(strstr(e.v[i].nome, info) != NULL || strstr(e.v[i].categoria, info) != NULL){
            printf("Codigo: %d\n", e.v[i].cod);
            printf("Categoria: %s\n", e.v[i].categoria);
            printf("Nome: %s\n", e.v[i].nome);
            printf("Preco: R$ %.2lf\n", e.v[i].preco);
            printf("Quantidade: %d\n", e.v[i].qtd);
            printf("----------------------------------\n");
            return 1;
        }
    }
    return 0;
}

void ListarEstoque(TEstoque e){
    int i;
    for(i=0; i<e.qtd_estoque; i++){
        printf("Codigo: %d\n", e.v[i].cod);
        printf("Categoria: %s\n", e.v[i].categoria);
        printf("Nome: %s\n", e.v[i].nome);
        printf("Preco: R$ %.2lf\n", e.v[i].preco);
        printf("Quantidade: %d\n", e.v[i].qtd);
        printf("----------------------------------\n");
    }
}

void Inicializar(TEstoque *e){
    (*e).qtd_estoque = 0;
}


