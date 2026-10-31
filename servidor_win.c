#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define PORTA 8080

int main (){
    SOCKET sock, sock_cliente;
    WSADATA wsaData;
    int resultado; 
    
    resultado = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (resultado != 0){
        printf("há algum erro no WINSOCK");
        return 1;
    } else {
        printf("WINSOCK ligado, tudo certo");
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET){
        printf("há algum erro na criacao do socket");
        WSACleanup();
        return 1;
    }

    struct sockaddr_in endereco;
    socklen_t endereco_len = sizeof(endereco);

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(PORTA);

    if (bind(sock, (struct sockaddr *)&endereco, sizeof(endereco)) == SOCKET_ERROR) {
        printf("\nErro no bind");
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    if (listen(sock, 1) == SOCKET_ERROR) {
        printf("\nErro no listen\n");
        closesocket(sock);
        WSACleanup();
        return 1;
    }
    
    printf("Servidor aguardando conexao na porta %d...\n", PORTA);

    sock_cliente = accept(sock, (struct sockaddr *)&endereco, &endereco_len);
    if (sock_cliente == INVALID_SOCKET) {
        printf("Erro no accept\n");
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    printf("Cliente conectado!\n");

    closesocket(sock);
    closesocket(sock_cliente);
    WSACleanup();
    return 0;
}