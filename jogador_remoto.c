#include "jogador_remoto.h"
#include <stdio.h>

int enviaJogada(Conexao conexao, int casa) {
    unsigned char mensagem;
    int enviados;

    if (casa < 1 || casa > 9) {
        return 0; 
    } 

    mensagem = (unsigned char) casa;

    enviados = send (conexao, (const char *)&mensagem, sizeof (mensagem), 0);

    if (enviados == sizeof(mensagem)){
        return 1;
    }

    return -1;

}



int recebeJogada(Conexao conexao, Tabuleiro *t, int tipo, int *casaRecebida){
    unsigned char mensagem;
    int recebidos;
    int casa;
    *casaRecebida = 0;
    

    recebidos = recv(conexao, (char *) &mensagem, sizeof(mensagem), 0);

    if (recebidos <= 0) {
        return -1;
    }
    casa = (int) mensagem;

    if (marcaJogada(t,casa,tipo) == 0) {
        return 0 ;
    }
    
    *casaRecebida = casa; 

    return 1; 




}
