#include <stdio.h>
#include "jogador_teclado.h"
#include "partida.h"
#include "tabuleiro.h"
#include "jogador_IA.h"


void comecarPartida(Partida *p) {
    char figura;
    int count = 0;
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
        p ->j1.tipo = xis;
        p ->j2.tipo = bola;
    } else {
         p ->j1.tipo = bola;
         p ->j2.tipo = xis;
    }

    Jogador *jogadorAtual = &p->j1;


    desenhaTabuleiro(&p->tab);

    while (count < 9) {
        casaIA = 0;

        if (jogadorAtual -> modo == IA) {
            casaIA = jogadaIA(&p ->tab, jogadorAtual->tipo);
            jogou = (casaIA != 0);
        } else {
            jogou = escolhaPosicao(&p ->tab, jogadorAtual->tipo);
        }

        if (jogou == 0) {
            continue;
           } 
 
         count++;

        desenhaTabuleiro(&p ->tab);

        if (casaIA != 0) {
            printf("\nJogador IA jogou na casa %d\n", casaIA);
        }

        vencedor = temVencedor(&p -> tab);

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

        if (jogadorAtual == &p->j1) {
            jogadorAtual = &p->j2;
        } else {
           jogadorAtual = &p->j1;
        }
    }
}