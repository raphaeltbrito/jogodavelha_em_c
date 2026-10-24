#include "jogador_IA.h"
#include <stdio.h>

int regra1 (Tabuleiro *t, int tipo, int alvo){
    for (int i = 0; i < 3; i++){
        if (t -> matriz[i][0] + t -> matriz[i][1] + t -> matriz[i][2] == alvo){
            for (int j = 0 ; j < 3 ; j++){
                if (t -> matriz[i][j] == vazio){
                    t -> matriz[i][j] = tipo;
                    printf("\njogador IA jogou na casa %d\n", i * 3 + j + 1);
                    return 1;
                }
            }
        }
    }

    for (int j = 0 ; j < 3 ; j++){
        if (t -> matriz[0][j] + t -> matriz[1][j] + t -> matriz [2][j] == alvo){
            for (int i = 0; i < 3; i++){
                if (t -> matriz[i][j] == vazio){
                    t -> matriz[i][j] = tipo;
                    printf("\njogador IA jogou na casa %d\n", i * 3 + j + 1);
                    return 1;
                }
            }
        }
    }

    if (t -> matriz[0][0] + t -> matriz[1][1] + t -> matriz[2][2] == alvo){
        for (int k = 0; k < 3; k++){
            if (t -> matriz[k][k] == vazio){
                t -> matriz[k][k] = tipo;
                printf("\njogador IA jogou na casa %d\n", k * 3 + k + 1);
                return 1;
            }


        }
    }

    if (t -> matriz[0][2] + t -> matriz[1][1] + t -> matriz[2][0] == alvo){
        for (int k = 0; k < 3; k++){
            if (t -> matriz[k][2 - k] == vazio){
                t -> matriz[k][2 - k] = tipo;
                printf("\njogador IA jogou na casa %d\n", 2 * k + 3);
                return 1;
            }
        }
    }

    return 0;

}

int contaLinhas (Tabuleiro *t, int alvo){
    int cont = 0;
    for (int i = 0; i < 3; i++){
        if (t -> matriz[i][0] + t -> matriz[i][1] + t -> matriz[i][2] == alvo){
            cont++;
        }
    }
    
    for (int j = 0 ; j < 3 ; j++){
        if (t -> matriz[0][j] + t -> matriz[1][j] + t -> matriz [2][j] == alvo){
            cont++;
        }
    }

    if (t -> matriz[0][0] + t -> matriz[1][1] + t -> matriz[2][2] == alvo){
            cont++;
    }

    if (t -> matriz[0][2] + t -> matriz[1][1] + t -> matriz[2][0] == alvo){
            cont++;
    }

    return cont;
}

int regra2(Tabuleiro *t, int tipo){
    for (int i = 0; i < 3; i++){
        for (int j = 0 ; j < 3 ; j++){
            if (t -> matriz[i][j] == vazio){
                t -> matriz[i][j] = tipo;
                int linhas = contaLinhas(t, tipo * 2);
                t -> matriz[i][j] = vazio;
                if (linhas >= 2){
                    t -> matriz[i][j] = tipo;
                    printf("\njogador IA jogou na casa %d\n", i * 3 + j + 1);
                    return 1;
                }
            }
        }
    }

    return 0;
    
}

int regra3(Tabuleiro *t, int tipo){
    if (t -> matriz[1][1] == vazio){
        t -> matriz[1][1] = tipo;
        printf("\njogador IA jogou na casa %d\n", 5);
        return 1;
    }

    return 0;
}

int regra4(Tabuleiro *t, int tipo, int adversario){
    if (t -> matriz[0][0] == adversario && t -> matriz[2][2] == vazio){
        t -> matriz[2][2] = tipo;
        printf("\njogador IA jogou na casa 9\n");
        return 1;
    } else if (t -> matriz[0][2] == adversario && t -> matriz[2][0] == vazio){
        t -> matriz[2][0] = tipo;
        printf("\njogador IA jogou na casa 7\n");
        return 1;
    } else if (t -> matriz[2][0] == adversario && t -> matriz[0][2] == vazio){
        t -> matriz[0][2] = tipo;
        printf("\njogador IA jogou na casa 3\n");
        return 1;
    } else if (t -> matriz[2][2] == adversario && t -> matriz[0][0] == vazio){
        t -> matriz[0][0] = tipo;
        printf("\njogador IA jogou na casa 1\n");
        return 1;
        }

    return 0;
}

int regra5(Tabuleiro *t, int tipo){
    if (t -> matriz[0][0] == vazio){
        t -> matriz[0][0] = tipo;
        printf("\njogador IA jogou na casa 1\n");
        return 1;
    } else if (t -> matriz[0][2] == vazio){
        t -> matriz[0][2] = tipo;
        printf("\njogador IA jogou na casa 3\n");
        return 1;
    } else if (t -> matriz[2][0] == vazio){
        t -> matriz[2][0] = tipo;
        printf("\njogador IA jogou na casa 7\n");
        return 1;
    } else if (t -> matriz[2][2] == vazio){
        t -> matriz[2][2] = tipo;
        printf("\njogador IA jogou na casa 9\n");
        return 1;
    }

    return 0;
}

int jogadaIA(Tabuleiro *t, int tipo){
    int adversario;
    
    if (tipo == xis){
        adversario = bola;
    } else {
        adversario = xis;
    }

    if (regra1(t, tipo, tipo * 2)){
        return 1;
    }

    if (regra1(t, tipo, adversario * 2)){
        return 1;
    }

    if (regra2(t, tipo)){
        return 1;
    }

    if (regra3(t, tipo)){
        return 1;
    }

    if (regra4(t, tipo, adversario)){
        return 1;
    }

    if (regra5(t, tipo)){
        return 1;
    }

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
