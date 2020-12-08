#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uteis.h"
#include "contatos.h"
#include "arqtxt.h"


int main(){
    TContato contato;
    TAgenda agenda;
    char aux[20];
    int fim = 0;
    Inicializar(&agenda);
    if(LerContatos("contatos.txt", &agenda) == 1){
        GravarContato("contatos.txt", agenda);
        printf("Arquivo encontrado e gravado!\n");
        pausar();
    }
    while (!fim){
        switch(menu()){
            case 1:
               limparTela();            
               LerContato(&contato);
               Inserir(&agenda, contato);
               printf("\nContato inserido com sucesso!\n");
               pausar();
               break;
            case 2:
               limparTela(); 
               printf("Digite o email do contato que deseja remover: ");
               scanf("%s", aux);
               if(Remover(&agenda, aux))
                  printf("\nContato removido com sucesso!\n");
               else
                  printf("\nContato nao encontrado!\n");  
               pausar();
               break;
            case 3:
                limparTela();
                printf("Digite parte do nome, email ou telefone do contato que deseja mostrar: ");
                scanf("%s", aux);
                ListarUmContato(agenda, aux);
                pausar();
                break;
            case 4:
                limparTela();
                ListarAgenda(agenda);
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
    return 0;
}