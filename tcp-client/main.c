#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(){
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_fd < 0){
       printf("Error in creating socket"); 
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family =AF_INET;
    server_addr.sin_port =htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
//    bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    while(1){
    connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    char sending_mssg[50] = {0};
    printf("Enter string \n");
    fgets(sending_mssg, sizeof(sending_mssg), stdin);
    printf("sending %s", sending_mssg);
    send(socket_fd, sending_mssg, sizeof(sending_mssg), 0);
    char buffer[1024] = {0};
    read(socket_fd, buffer, sizeof(buffer));
    printf("Received %s", buffer);
    }

    close(socket_fd); 
}
