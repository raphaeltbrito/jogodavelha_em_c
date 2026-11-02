#include <stdio.h>
#include "jogador_teclado.h"
#include "tabuleiro.h"


int escolhaPosicao(Tabuleiro *t, int tipo, int *casaJogada) {
    int casa;
    int jogou;
    *casaJogada = 0;

    if (tipo == xis) {
        printf("\nJogador X selecione a casa que deseja inserir (escolha de 1 a 9): ");
    } else {
        printf("\nJogador O selecione a casa que deseja inserir (escolha de 1 a 9): ");
    }
    
    scanf("%d", &casa);

    jogou = marcaJogada(t, casa , tipo);

    if (jogou == 1){
        *casaJogada = casa;
        return 1;
    } else {
        printf("Esta casa já está ocupada ou invalida");
        return 0;
    }
}