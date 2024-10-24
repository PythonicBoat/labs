#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char buffer1[1024], buffer2[1024], result[2048];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    addr_len = sizeof(client_addr);
    recvfrom(sockfd, buffer1, sizeof(buffer1), 0, (struct sockaddr *)&client_addr, &addr_len);
    recvfrom(sockfd, buffer2, sizeof(buffer2), 0, (struct sockaddr *)&client_addr, &addr_len);

    strcpy(result, buffer1);
    strcat(result, buffer2);

    sendto(sockfd, result, strlen(result) + 1, 0, (struct sockaddr *)&client_addr, addr_len);

    close(sockfd);
    return 0;
}