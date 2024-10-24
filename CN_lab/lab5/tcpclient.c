#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[1024], recv_buffer[1024];
    int bytes_sent, bytes_received;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); 
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    strcpy(send_buffer, "Hello, Server!");
    bytes_sent = send(sockfd, send_buffer, strlen(send_buffer), 0);
    if (bytes_sent < 0) {
        perror("Send failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(sockfd, recv_buffer, sizeof(recv_buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Receive failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    recv_buffer[bytes_received] = '\0';
    printf("Server: %s\n", recv_buffer);
    close(sockfd);
    return 0;
}