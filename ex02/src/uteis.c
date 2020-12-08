#include "uteis.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void LerStr(char str[], int max){
   fgets(str, max, stdin);
   str[strlen(str) - 1] = '\0';
}


int menu(){
    int opc;
    do{
        limparTela();    
        printf("============================\n");
        printf("      T O Y   S T O R E     \n");
        printf("============================\n");
        printf("\nBem-vindo(a)!\n");
        printf("1 - Inserir brinquedo\n");
        printf("2 - Remover brinquedo\n");
        printf("3 - Atualizar brinquedo\n");
        printf("4 - Mostrar estoque\n");
        printf("5 - Mostrar categoria\n");
        printf("6 - Mostrar um brinquedo\n");
        printf("7 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);
    }while(opc < 1 || opc > 7);
    fflush(stdin);
    return opc;
}