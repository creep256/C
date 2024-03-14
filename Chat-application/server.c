#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main ()
{
    int i=1;
    int server_fd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_addr,client_addr;
    socklen_t clilen;
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(9999);
    server_addr.sin_addr.s_addr=INADDR_ANY;

    bind(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    listen(server_fd,5);
    clilen=sizeof(client_addr);
    int client_fd=accept(server_fd,(struct sockaddr *) &client_addr,&clilen);
    char buffer[1024];
    while(1)
    {
        bzero(buffer,1024);
        read(client_fd,buffer,1024);
        printf("Client : %s",buffer);
        bzero(buffer,1024);
        fgets(buffer,1024,stdin);

        write(client_fd,buffer,strlen(buffer));
        i =strncmp("bye",buffer,3);
        if(i==0)
        break;
    }
    close(client_fd);
    close(server_fd);
    return 0;
}