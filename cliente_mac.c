#include <stdio.h>
#include <string.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include "partida_remota.h"

#define PORTA 8080
#define IP_SERVIDOR "192.168.15.67"

int main(void) {
    Conexao sockfd;
    struct sockaddr_in servidor;
    Partida p;

    memset(&servidor, 0, sizeof(servidor));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Erro ao criar socket.\n");
        return 1;
    }

    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(PORTA);

    if (inet_pton(
            AF_INET,
            IP_SERVIDOR,
            &servidor.sin_addr
        ) != 1) {
        printf("IP do servidor invalido.\n");
        close(sockfd);
        return 1;
    }

    if (connect(
            sockfd,
            (struct sockaddr *)&servidor,
            sizeof(servidor)
        ) < 0) {
        printf("Erro ao conectar ao servidor.\n");
        close(sockfd);
        return 1;
    }

    printf("Conectado ao servidor!\n");

    inicializa(&p.tab);

    p.j1.tipo = xis;
    p.j1.modo = REMOTO;

    p.j2.tipo = bola;
    p.j2.modo = TECLADO;

    comecarPartidaRemota(&p, sockfd);

    close(sockfd);

    return 0;
}