#include <stdio.h>
#include "jogador_teclado.h"
#include "partida.h"
#include "tabuleiro.h"
#include "jogador_IA.h"


void comecarPartida(Tabuleiro *t, int modo) {
    char figura;
    int count = 0;
    int tipo;
    int humano;
    int vencedor = vazio;
    int jogou;
    int casaIA;

    do {
        printf("Primeiro jogador deseja ser qual figura (X/O): ");
        
        if ((scanf(" %c", &figura)) !=1){
            return;
        }
            
        if (figura != 'X' && figura != 'O') {
            printf("\nFigura inválida. Tente novamente!\n");
        }

    } while (figura != 'X' && figura != 'O');

    if (figura == 'X') {
        tipo = xis;
    } else {
        tipo = bola;
    }

    humano = tipo;

    desenhaTabuleiro(t);

    while (count < 9) {
        casaIA = 0;

        if (modo == 2 && tipo != humano) {
            casaIA = jogadaIA(t, tipo);
            jogou = (casaIA != 0);
        } else {
            jogou = escolhaPosicao(t, tipo);
        }

        if (jogou == 0) {
            continue;
        }

        count++;

        desenhaTabuleiro(t);

        if (casaIA != 0) {
            printf("\nJogador IA jogou na casa %d\n", casaIA);
        }

        vencedor = temVencedor(t);

        if (vencedor == xis) {
            printf("O vencedor foi X!\n");
            return;
        }

        if (vencedor == bola) {
            printf("O vencedor foi O!\n");
            return;
        }

        if (count == 9) {
            printf("Deu empate!\n");
            return;
        }

        if (tipo == xis) {
            tipo = bola;
        } else {
            tipo = xis;
        }
    }
}