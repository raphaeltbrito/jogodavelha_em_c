#include <stdio.h>
#include "jogador_teclado.h"
#include "tabuleiro.h"


int escolhaPosicao(Tabuleiro *t, int tipo) {
    int casa;
    int linha, coluna;

    if (tipo == xis) {
        printf("\nJogador X selecione a casa que deseja inserir (escolha de 1 a 9): ");
    } else {
        printf("\nJogador O selecione a casa que deseja inserir (escolha de 1 a 9): ");
    }
    
    scanf("%d", &casa);
    
    switch (casa){
        case 1:
        linha = 0;
        coluna = 0;
        break;

        case 2:
        linha = 0;
        coluna = 1;
        break;

        case 3:
        linha = 0;
        coluna = 2;
        break;

        case 4:
        linha = 1;
        coluna = 0;
        break;

        case 5:
        linha = 1;
        coluna = 1;
        break;

        case 6:
        linha = 1;
        coluna = 2;
        break;

        case 7:
        linha = 2;
        coluna = 0;
        break;

        case 8:
        linha = 2;
        coluna = 1;
        break;

        case 9:
        linha = 2;
        coluna = 2;
        break;

        default:
        printf("Casa inválida\n");
        return 0 ;
    }


    if (t -> matriz[linha][coluna] == vazio){
        t -> matriz[linha][coluna] = tipo;
        return 1;
    } else {
        printf("Esta casa já está ocupada");
        return 0;
    }
}