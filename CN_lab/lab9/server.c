#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080

void log_client_info(struct sockaddr_in *client_addr) {
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(client_addr->sin_addr), client_ip, INET_ADDRSTRLEN);
    int client_port = ntohs(client_addr->sin_port);
    printf("Client connected: IP = %s, Port = %d\n", client_ip, client_port);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address, client_addr;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    int num1, num2, result;
    char operator;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(SERVER_PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    log_client_info(&client_addr);

    read(new_socket, buffer, 1024);
    sscanf(buffer, "%d %d %c", &num1, &num2, &operator);

    switch (operator) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': 
            if (num2 != 0) 
                result = num1 / num2; 
            else {
                snprintf(buffer, sizeof(buffer), "Error: Division by zero");
                send(new_socket, buffer, strlen(buffer), 0);
                close(new_socket);
                close(server_fd);
                return 0;
            }
            break;
        default:
            snprintf(buffer, sizeof(buffer), "Error: Invalid operator");
            send(new_socket, buffer, strlen(buffer), 0);
            close(new_socket);
            close(server_fd);
            return 0;
    }

    snprintf(buffer, sizeof(buffer), "%d", result);
    send(new_socket, buffer, strlen(buffer), 0);

    close(new_socket);
    close(server_fd);

    return 0;
}