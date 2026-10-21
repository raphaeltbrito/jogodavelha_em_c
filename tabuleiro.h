#ifndef tabuleiro_h
#define tabuleiro_h

#define xis 4
#define bola 1
#define vazio 0

typedef struct {
    int matriz[3][3];
} Tabuleiro;

void inicializa (Tabuleiro *t);

void desenhaTabuleiro (Tabuleiro *t);

int temVencedor(Tabuleiro *t);

#endif