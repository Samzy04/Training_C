//Write 2 programs, where the first program should send a file to the second program using TCP,
//and the second program must print the information received and save the it on a file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main (){
    char *ip = " 127.0.0.1";
    int port = 5566;

    int server_sock,client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;

    server_sock = socket(AF_INET,SOCK_STREAM,0);
    if (server_sock<0){
        perror("[-]Socket error");
        exit(1);
    }
    printf("[+]TCP server socket created\n");

    memset(&server_addr,'\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    n = bind(server_sock, (struct sockaddr*)&server_addr,sizeof(server_addr));
    if(n<0){
        perror("Bind error");
        exit(1);
    }
    printf("BIND to port number:%d\n",port);
    listen(server_sock,5);
    printf("Listening....\n");

    while(1){
        addr_size = sizeof(client_addr);
        client_sock = accept(server_sock,(struct  sockaddr*)&client_addr,&addr_size);
        printf("Clint Connected\n");
    }

}

