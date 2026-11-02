#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define PORTA 8080

int main (){
    SOCKET sockfd, client_fd;
    WSADATA wsaData;
    int resultado; 
    
    resultado = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (resultado != 0){
        printf("há algum erro no WINSOCK");
        return 1;
    } else {
        printf("WINSOCK ligado, tudo certo");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET){
        printf("há algum erro na criacao do socket");
        WSACleanup();
        return 1;
    }

    struct sockaddr_in endereco;
    socklen_t endereco_len = sizeof(endereco);

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(PORTA);

    if (bind(sockfd, (struct sockaddr *)&endereco, sizeof(endereco)) == SOCKET_ERROR) {
        printf("\nErro no bind");
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    if (listen(sockfd, 1) == SOCKET_ERROR) {
        printf("\nErro no listen\n");
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }
    
    printf("\nServidor aguardando conexao na porta %d...\n", PORTA);

    client_fd = accept(sockfd, (struct sockaddr *)&endereco, &endereco_len);
    if (client_fd == INVALID_SOCKET) {
        printf("Erro no accept\n");
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("Cliente conectado!\n");

    int envia = 7;
    send(client_fd, (const char *) &envia, sizeof(envia), 0);

    int teste2 = 0;

    recv(client_fd, (char *)&teste2, sizeof(teste2), 0);
    printf("Recebi: %d\n", teste2);

    closesocket(sockfd);
    closesocket(client_fd);
    WSACleanup();
    return 0;
}