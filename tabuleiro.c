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

    printf("\033[2J\033[H");

    for (int i = 0; i < 3; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            
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

int temVencedor(Tabuleiro *t) {
    for (int i = 0; i < 3; i++) {
        if (t ->matriz[i][0] + t ->matriz[i][1] + t ->matriz[i][2] == 3) return bola;
        else if (t ->matriz[i][0] + t ->matriz[i][1] + t ->matriz[i][2] == 12) return xis; 
    }


    for (int j = 0 ; j < 3; j++) {
        if (t ->matriz[0][j] + t ->matriz[1][j] + t ->matriz[2][j] == 3) return bola;
        else if (t ->matriz[0][j] + t ->matriz[1][j] + t ->matriz[2][j] == 12) return xis;     
    }


    if (t ->matriz[0][0] + t ->matriz[1][1] + t ->matriz[2][2] == 3) return bola; 
    else if (t ->matriz[0][0] + t ->matriz[1][1] + t ->matriz[2][2] == 12) return xis;
        

    if (t ->matriz[0][2] + t ->matriz[1][1] + t ->matriz[2][0] == 3) return bola;
    else if (t ->matriz[0][2] + t ->matriz[1][1] + t ->matriz[2][0] == 12) return xis;

    return vazio;
}  
