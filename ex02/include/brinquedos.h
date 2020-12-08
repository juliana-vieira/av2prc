#ifndef BRINQUEDOS_H
#define BRINQUEDOS_H

#define MAXNOME 30
#define MAXCATEGORIA 20

typedef struct{
    int cod, qtd;
    double preco;
    char nome[MAXNOME], categoria[MAXCATEGORIA];

} TBrinquedo;

typedef struct{
    TBrinquedo v[100];
    int qtd_estoque;
} TEstoque;

void Inserir(TEstoque *e, TBrinquedo b);
void LerBrinquedo(TBrinquedo *b);
int BrinquedoExistente(TEstoque e, int info);
int Remover(TEstoque *e, int info1, int info2);
void Atualizar(TEstoque *e, int info, TBrinquedo b);
int ListarCategoria(TEstoque e, char info[]);
int Filtrar(TEstoque e, char info[]);
void ListarEstoque(TEstoque e);
void Inicializar(TEstoque *e);

#endif 
