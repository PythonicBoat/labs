#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer1[1024], buffer2[1024], result[2048];
    socklen_t addr_len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    printf("Enter the first string: ");
    scanf("%s", buffer1);
    printf("Enter the second string: ");
    scanf("%s", buffer2);

    sendto(sockfd, buffer1, strlen(buffer1) + 1, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    sendto(sockfd, buffer2, strlen(buffer2) + 1, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    addr_len = sizeof(server_addr);
    recvfrom(sockfd, result, sizeof(result), 0, (struct sockaddr *)&server_addr, &addr_len);
    printf("Concatenated string: %s\n", result);

    close(sockfd);
    return 0;
}