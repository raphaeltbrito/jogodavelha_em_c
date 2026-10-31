#include <stdio.h>
#include "tabuleiro.h"
#include "jogador_teclado.h"
#include "partida.h"

int main(void) {
    Partida p;
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

    p.j1.modo = TECLADO;

    if (modo == 1) {
        p.j2.modo = TECLADO;
    } else {
        p.j2.modo = IA;
    }

    inicializa(&p.tab);
    comecarPartida(&p);

    return 0;
}