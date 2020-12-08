#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uteis.h"
#include "brinquedos.h"

int main(){
    TBrinquedo brinquedo;
    TEstoque estoque;
    char aux[20];
    int a, b, x;
    int fim = 0;
    Inicializar(&estoque);
    while(!fim){
        switch(menu()){
            case 1:
                limparTela();
                LerBrinquedo(&brinquedo);
                Inserir(&estoque, brinquedo);
                printf("\nItem inserido com sucesso!\n");
                pausar();
                break;
            case 2: 
                limparTela();
                printf("Digite o codigo e a quantidade do item a ser removido: ");
                scanf("%d %d", &a, &b);
                x = Remover(&estoque, a, b);
                if (x == 1)
                    printf("\nItem removido!\n");
                else if (x == 2)
                    printf("\nERRO: Quantidade invalida!\n");
                else if (x == 0)
                    printf("\nERRO: Item nao encontrado!\n");
                pausar();
                break;
            case 3:
                limparTela();
                printf("Digite o codigo do brinquedo que deseja atualizar: ");
                scanf("%d", &a);
                x = BrinquedoExistente(estoque, a);
                if (x > -1){
                   printf("\n=== INSIRA OS NOVOS DADOS ===\n");
                   LerBrinquedo(&brinquedo);
                   Atualizar(&estoque, a, brinquedo);
                   printf("\nItem atualizado!\n");
                }else
                    printf("\nERRO: Item nao encontrado!\n");
                pausar();
                break;
            case 4:
                limparTela();
                ListarEstoque(estoque);
                pausar();
                break;
            case 5:
                limparTela();
                printf("Digite a categoria a ser mostrada: ");
                scanf("%s", aux);
                if(ListarCategoria(estoque, aux))
                    pausar();
                else{
                    printf("\nERRO: Categoria nao encontrada!\n");
                    pausar();
                }
                break;
            case 6:
                limparTela();
                printf("Digite parte do nome ou da categoria do item a ser mostrado: ");
                scanf("%s", aux);
                if(Filtrar(estoque, aux))
                    pausar();
                else{
                    printf("\nERRO: Item nao encontrado!\n");
                    pausar();
                }
                break;
            case 7:
                limparTela();
                printf("============================\n");
                printf("  V O L T E   S E M P R E ! \n");
                printf("============================\n");
                fim = 1;
                break;
            default:
                printf("\nERRO: Opcao invalida.\n");
                pausar();
                break;

        }
    }
}

