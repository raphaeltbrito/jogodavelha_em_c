#include <stdio.h>

#include "partida_remota.h"
#include "jogador_teclado.h"
#include "jogador_IA.h"
#include "tabuleiro.h"

void comecarPartidaRemota(Partida *p,Conexao conexao) {
    int count = 0;
    int vencedor = vazio;
    int jogou;
    int casaJogada;
    int resultadoEnvio;
    Jogador *jogadorAtual = &p->j1;

    desenhaTabuleiro(&p->tab);

    while (count < 9) {
        casaJogada = 0;

        if (jogadorAtual->modo == REMOTO) {
            jogou = recebeJogada(conexao, &p->tab, jogadorAtual->tipo, &casaJogada);

            if (jogou == -1) {
                printf("\nO jogador remoto desconectou.\n");
                return;
            }

            if (jogou == 0) {
                printf("\nJogada remota invalida.\n");
                return;
            }
        } else {
            if (jogadorAtual->modo == IA) {
                casaJogada = jogadaIA(
                    &p->tab,
                    jogadorAtual->tipo
                );

                jogou = (casaJogada != 0);
            } else {
                jogou = escolhaPosicao(
                    &p->tab,
                    jogadorAtual->tipo,
                    &casaJogada
                );
            }

            if (jogou == 1) {
                resultadoEnvio = enviaJogada(
                    conexao,
                    casaJogada
                );

                if (resultadoEnvio != 1) {
                    printf("\nNao foi possivel enviar a jogada.\n");
                    return;
                }
            }
        }

        if (jogou == 0) {
            continue;
        }

        count++;

        desenhaTabuleiro(&p->tab);

        if (jogadorAtual->tipo == xis) {
            printf("\nJogador X colocou na casa %d.\n", casaJogada);
        } else {
            printf("\nJogador O colocou na casa %d.\n", casaJogada);
        }

        vencedor = temVencedor(&p->tab);

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