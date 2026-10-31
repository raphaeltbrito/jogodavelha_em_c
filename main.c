#include <stdio.h>
#include "tabuleiro.h"
#include "jogador_teclado.h"
#include "partida.h"

int main(void) {
    Tabuleiro t;
    int modo = 0;

    do {
        printf("\nEscolha o modo de jogo:\n");
        printf(" [1] Humano contra humano\n");
        printf(" [2] Humano contra IA\n");
        printf("Opcao: ");
        scanf("%d", &modo);

        if (modo != 1 && modo != 2) {
            printf("Opcao invalida! Digite 1 ou 2.\n");
        }
    } while (modo != 1 && modo != 2);

    inicializa(&t);
    comecarPartida(&t, modo);

    return 0;
}