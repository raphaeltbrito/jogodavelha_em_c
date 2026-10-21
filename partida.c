#include <stdio.h>
#include "jogador_teclado.h"
#include "partida.h"
#include "tabuleiro.h"
void comecarPartida(Tabuleiro *t) {
    char figura;
    int count = 0;
    int tipo; 
    int vencedor = vazio;

    do {
        printf("Primeiro jogador deseja ser qual figura (X/O): ");
        scanf(" %c", &figura);
        if (figura == 'X' ){
            tipo = xis;
        } else if(figura == 'O') {
            tipo = bola;
        }else {
            printf("Figura inválida. Tente Novamente!!!\n");
        }
    } while (figura != 'X' && figura != 'O');


    desenhaTabuleiro(t);


    while (count < 9) {
        if (escolhaPosicao(t, tipo) == 1){
            count++;

            if (tipo == xis){
                tipo = bola;
            } else {
                tipo = xis;
            }

            desenhaTabuleiro(t);

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
    

