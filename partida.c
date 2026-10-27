#include <stdio.h>
#include "jogador_teclado.h"
#include "partida.h"
#include "tabuleiro.h"
#include "jogador_IA.h"


void comecarPartida(Tabuleiro *t) {
    char figura;
    int count = 0;
    int tipo; 
    int vencedor = vazio;
    int humano;

    do {
        printf("Primeiro jogador deseja ser qual figura (X/O): ");
        scanf(" %c", &figura);
        if (figura == 'X' ){
            tipo = xis;
            humano = xis;
        } else if(figura == 'O') {
            tipo = bola;
            humano = bola;
        } else {
            printf("Figura inválida. Tente Novamente!!!\n");
        }
    } while (figura != 'X' && figura != 'O');


    desenhaTabuleiro(t);

    int jogou;
    int casaIA;

    while (count < 9) {
        casaIA = 0;

        if (tipo != humano){
            casaIA = jogadaIA(t, tipo);
            jogou = (casaIA != 0);
    } else {
        jogou = escolhaPosicao(t, tipo);
    }

        if (jogou == 1){
            count++;

            if (tipo == xis){
                tipo = bola;
            } else {
                tipo = xis;
            }

            desenhaTabuleiro(t);
            
            if (casaIA != 0){
                printf("O jogador IA jogou na casa %d\n", casaIA);
            }

            vencedor = temVencedor(t);
            if (vencedor == xis) {
                printf("O vencedor foi X\n");
                break;
            } else if (vencedor == bola) {
                printf("O vencedor foi O\n");
                break;
            } else if (vencedor != bola && vencedor != xis && count == 9){
                printf("Deu empate!!!\n");
            }
        }
    }
}
    

