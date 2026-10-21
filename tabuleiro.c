#include <stdio.h>
#include "tabuleiro.h"

void inicializa(Tabuleiro *t) {
    for (int i = 0; i < 3; i++){
        for (int j = 0 ; j < 3 ; j++){
            t -> matriz[i][j] = vazio;
        }
    }
}


void desenhaTabuleiro(Tabuleiro *t) {
    int casa = 1;
    for (int i = 0; i < 3; i++){
        for (int j = 0 ; j < 3 ; j++){
            
            if (t -> matriz[i][j] == xis) printf(" X");
            else if (t -> matriz[i][j] == bola) printf(" O");
            else printf (" %d", casa);
            
            casa++;
            
            if (j < 2) printf(" |");    
        }
    
    if (i < 2) printf("\n---+---+---\n");    
    
    }

    printf("\n");

}