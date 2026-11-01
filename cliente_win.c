#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define PORTA 8080 

int main(){
    SOCKET sockfd;
    WSADATA wsaData;
    int resultado; 
    
    resultado = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (resultado != 0){
        printf("há algum erro no WINSOCK\n");
        return 1;
    } else {
        printf("WINSOCK ligado, tudo certo\n");
    }
    
    struct sockaddr_in servidor;

    servidor.sin_family = AF_INET;
    servidor.sin_port = htons(PORTA);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET){
        printf("há algum erro na criacao do socket");
        WSACleanup();
        return 1;
    }

    servidor.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&servidor, sizeof(servidor)) == SOCKET_ERROR) {
        printf("\nErro ao conectar\n");
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("\nConectado ao servidor!\n");

    int recebido = 0;
    recv(sockfd, (char *)&recebido, sizeof(recebido), 0);
    printf("Recebi: %d\n", recebido);

    int teste = 5;
    send(sockfd, (const char *) &teste, sizeof(teste), 0);

    closesocket(sockfd);
    WSACleanup();
    return 0;

}