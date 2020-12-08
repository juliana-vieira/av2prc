#ifndef CONTATO_H
#define CONTATO_H

#define MAXNOME 50
#define MAXEMAIL 40
#define MAXTELEFONE 20

typedef struct {
    char nome[MAXNOME];
    char email[MAXEMAIL];
    char telefone[MAXTELEFONE];

} TContato;

typedef struct{
    TContato  v[100];
    int qtd;

} TAgenda;

void Inserir(TAgenda *a, TContato c);
void LerContato(TContato *c);
int ContatoExistente(TAgenda a, char info[]);
int Remover(TAgenda *a, char info[]);
void ListarAgenda(TAgenda a);
void ListarUmContato(TAgenda a, char info[]);
void Inicializar(TAgenda *a);

#endif
