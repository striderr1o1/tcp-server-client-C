#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(){
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);

    if(serverfd < 0){
        printf("Error in socket handling");
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family =AF_INET;
    server_addr.sin_port =htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(serverfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(serverfd, 2);
    while(1){
    socklen_t clientaddrlen = sizeof(server_addr);
//incoming client creates new socket    
    int new_sock = accept(serverfd, (struct sockaddr*)&server_addr, (socklen_t*)&clientaddrlen);
    printf("Client IP: %s\n", inet_ntoa(server_addr.sin_addr)); 
    char user_req_buffer[2048] = {0};
    read(new_sock, user_req_buffer, 2048);
    printf("client sends: %s", user_req_buffer);
    const char* response = "Welcome to xyz's server";
    send(new_sock, response,strlen(response),0);
    close(new_sock); 
   }

}
