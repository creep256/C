#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netdb.h>

int main(int argc, char *argv[])
{
    int i=1;
    int sock_fd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in serv_addr;
    struct hostent *server;
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(9999);
    server=gethostbyname(argv[1]);
    connect(sock_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    char buffer[1024];
    while(1)
    {
        bzero(buffer,1024);
        fgets(buffer,1024,stdin);
        write(sock_fd,buffer,strlen(buffer));
        bzero(buffer,1024);
        read(sock_fd,buffer,1024);
        printf("Server:%s",buffer);
        i =strncmp("bye",buffer,3);
        if(i==0)
        break;
    }
    close(sock_fd);
    return 0;
}