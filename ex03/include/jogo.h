#ifndef JOGO_H
#define JOGO_H

void Inicializar(char jogo[3][3]);
int CoordenadaDisponivel(char jogo [3][3], int x, int y);
void InserirJogada(char jogo[3][3], int x, int y, int j);
int VitoriaLinhas(char jogo[3][3]);
int VitoriaColunas(char jogo[3][3]);
int VitoriaDiagonal1(char jogo[3][3]);
int VitoriaDiagonal2(char jogo[3][3]);
void MostrarTabuleiro(char tabuleiro[3][3]);
void Jogar(char jogo[3][3]);

#endif