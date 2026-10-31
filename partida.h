#ifndef partida_h
#define partida_h
#include "tabuleiro.h"
#include "jogador.h"
typedef struct {
    Tabuleiro tab;
    Jogador j1;
    Jogador j2;
} Partida;

void comecarPartida(Partida *p);

#endif