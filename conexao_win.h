#ifndef CONEXAO_WIN_H
#define CONEXAO_WIN_H

#include "jogador_remoto.h"

Conexao abrirServidor(void);
Conexao conectarCliente(const char *ip);

#endif