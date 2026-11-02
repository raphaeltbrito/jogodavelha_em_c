#ifndef jogador_remoto
#define jogador_remoto

#ifdef _WIN32
#include <winsock2.h>
typedef SOCKET Conexao;
#else
#include <sys/types.h>
#include <sys/socket.h>
typedef int Conexao;
#endif

#include "tabuleiro.h"

int enviaJogada(Conexao conexao, int casa);
int recebeJogada(Conexao conexao, Tabuleiro *t, int tipo, int *casaRecebida);

#endif