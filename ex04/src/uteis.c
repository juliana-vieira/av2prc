#include "uteis.h"

#include <stdio.h>
#include <stdlib.h>

void limparTela(){
#ifdef _WIN32
   system("cls");
#else
   system("clear");
#endif
}

void pausar(){
#ifdef _WIN32
    system("pause");
#else
    //system("read -n1 -r -p \"Press any key to continue...\" key");
    printf("Press any key to continue...\n");
    getchar();
#endif    
}

int comparador(const void *a, const void *b) {
   return ( *(float*)a - *(float*)b );
}

int menu(){
    int opc;
    do{
        limparTela();
        printf("1 - Inserir conjuntos\n");
        printf("2 - Mostrar uniao\n");
        printf("3 - Mostrar interseccao\n");
        printf("4 - Mostrar diferenca\n");
        printf("5 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opc);
    }while (opc < 0 && opc > 5);
    return opc;
}