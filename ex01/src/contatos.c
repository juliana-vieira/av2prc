#include "contatos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Inserir(TAgenda *a, TContato c){
    (*a).v[(*a).qtd] = c;
    (*a).qtd++;
}

void LerContato(TContato *c){
    printf("Digite o nome: ");
    LerStr((*c).nome, MAXNOME);
    printf("Digite o e-mail: ");
    LerStr((*c).email, MAXEMAIL);
    printf("Digite o telefone: ");
    LerStr((*c).telefone, MAXTELEFONE);
    
}

int ContatoExistente(TAgenda a, char info[]){
    int existe, i;
    existe = 0;
    i = 0;
    while(!existe && i < a.qtd)
        if(strcmp(a.v[i].email, info) == 0)
            existe = 1;
        else
            i++;
    return existe ? i : -1;
}

int Remover(TAgenda *a, char info[]){
    int p;
    p = ContatoExistente(*a, info);
    if (p != -1){
        (*a).v[p] = (*a).v[(*a).qtd -1];
        (*a).qtd--;
        return 1;
    }else
        return 0;

}

void ListarAgenda(TAgenda a){
    int i;
    printf("----------------------------------\n");
    for (i=0; i<a.qtd; i++){
        printf("#%d\n", i+1);
        printf("Nome: %s\n", a.v[i].nome);
        printf("E-mail: %s\n", a.v[i].email);
        printf("Telefone: %s\n", a.v[i].telefone);
        printf("----------------------------------\n");

    }
}

void ListarUmContato(TAgenda a, char info[]){
    int i;
    for(i=0;i<a.qtd; i++){
        if(strstr(a.v[i].nome, info)!= NULL || strstr(a.v[i].email, info)!= NULL || strstr(a.v[i].telefone, info)!= NULL){
            printf("----------------------------------\n");
            printf("Nome: %s\n", a.v[i].nome);
            printf("E-mail: %s\n", a.v[i].email);
            printf("Telefone: %s\n", a.v[i].telefone);
            printf("----------------------------------\n");
        }
    }
}

void Inicializar(TAgenda *a){
    (*a).qtd = 0;
}


