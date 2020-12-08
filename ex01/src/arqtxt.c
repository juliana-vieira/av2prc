#include "arqtxt.h"

#include <stdio.h>
#include <stdlib.h>

char *lerAte(FILE *arq, char sep, char strDestino[], int max)
{
    int i=0;
    int letra;
    while ((letra = fgetc(arq)) > 0 && letra!=sep && i<max-1)
    {
        strDestino[i] = letra;
        i++;
    }
    strDestino[i] = '\0';
    return strDestino;
}

int LerContatos(char nomearq[], TAgenda *a){
    FILE *arq;
    int existe;
    arq = fopen(nomearq, "rt");
    if (arq != NULL){
        existe = 1;
        (*a).qtd = 0;
        TContato c;
        while(!feof(arq)){
           lerAte(arq, ',', c.nome, MAXNOME);
           lerAte(arq, ',', c.email, MAXEMAIL);
           lerAte(arq, ',', c.telefone, MAXTELEFONE);
           Inserir(&*a, c);
        }
        fclose(arq);
    }else
        existe = 0;
    return existe;
}

void GravarContato(char nomearq[], TAgenda a){
    FILE *arq;
    int i;
    arq = fopen(nomearq, "wt");
    if (arq != NULL){
        for(i=0; i<a.qtd; i++){
            TContato c = a.v[i];
        }
        fclose(arq);
    }
}