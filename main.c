#include <stdio.h>
#include "tabuleiro.h"
#include "jogador_teclado.h"
#include "partida.h"
int main() {
    Tabuleiro t;
    inicializa(&t);
    comecarPartida(&t);
    return 0;
}