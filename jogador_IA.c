#include "jogador_IA.h"
#include <stdio.h>

int jogadaIA(Tabuleiro *t, int tipo){

    for (int i = 0; i < 3; i++){
            for (int j = 0 ; j < 3 ; j++){
                if (t -> matriz[i][j] == vazio){
                    t -> matriz[i][j] = tipo;
                    printf("\njogador IA jogou na casa %d\n", i * 3 + j + 1);
                    return 1;
                }
            }
    }
    return 0;
}
