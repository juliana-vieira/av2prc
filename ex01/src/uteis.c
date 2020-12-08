#include "uteis.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparTela()
{
#ifdef _WIN32
   system("cls");
#else
   system("clear");
#endif
}

void pausar()
{
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
        printf("========= AGENDA TELEFONICA ========\n");
        printf("1 - Inserir contato\n");
        printf("2 - Remover contato\n");
        printf("3 - Listar um contato\n");
        printf("4 - Listar todos os contatos\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);
    }while (opc < 1 || opc > 5);
    fflush(stdin);
    return opc;
} 