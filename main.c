#include <stdio.h>
#include "tabuleiro.h"
#include "jogador_teclado.h"

int main() {
    Tabuleiro t;
    inicializa(&t);
    desenhaTabuleiro(&t);
    escolhaPosicao(&t, bola);
    desenhaTabuleiro(&t);
    return 0;
}