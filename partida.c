#include <stdio.h>
#include "jogador_teclado.h"
#include "partida.h"

void comecarPartida(Tabuleiro *t, int tipo) {
    printf("Primeiro jogador deseja ser qual figura (X/O): ")
    scanf("%d", &tipo)
    if (tipo != xis && tipo != bola) {
        printf("Tipo invalido. Tente novamente!!");
        
    }
}