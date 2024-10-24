#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char recv_buffer[1024], send_buffer[1024];
    int bytes_received, bytes_sent;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_fd < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(client_fd, recv_buffer, sizeof(recv_buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Receive failed");
        close(client_fd);
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    recv_buffer[bytes_received] = '\0';
    printf("Client: %s\n", recv_buffer);

    strcpy(send_buffer, "Hello, Client!");
    bytes_sent = send(client_fd, send_buffer, strlen(send_buffer), 0);
    if (bytes_sent < 0) {
        perror("Send failed");
        close(client_fd);
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    close(client_fd);
    close(server_fd);
    return 0;
}