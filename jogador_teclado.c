#include <stdio.h>
#include "jogador_teclado.h"
#include "tabuleiro.h"


int escolhaPosicao(Tabuleiro *t, int tipo) {
    int casa;
    int caractere;
    int linha, coluna;

    if (tipo == xis) {
        printf("\nJogador X selecione a casa que deseja inserir (escolha de 1 a 9): ");
    } else {
        printf("\nJogador O selecione a casa que deseja inserir (escolha de 1 a 9): ");
    }

    if (scanf("%d", &casa) != 1){
        printf("Insira um número inteiro!");
        caractere = getchar();
        while (caractere != ("\n" && EOF )) {
            caractere = getchar();
        }
        
        return 0;
    }
    
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

    printf("Linha: %d & Coluna: %d\n\n", linha, coluna);

    if (t -> matriz[linha][coluna] == vazio){
        t -> matriz[linha][coluna] = tipo;
        return 1;
    } else {
        printf("Esta casa já está ocupada");
        return 0;
    }
}