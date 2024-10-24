#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main() {
    int sockfd, fd1, length, i;
    int n1, n2, n3, res;
    struct sockaddr_in sa, ca;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = htons(8080);

    i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    if (i < 0) {
        perror("Bind failed");
        return 1;
    }
    printf("Server is live!\n");

    length = sizeof(sa);
    recvfrom(sockfd, &n1, sizeof(int), 0, (struct sockaddr *)&ca, &length);
    recvfrom(sockfd, &n2, sizeof(int), 0, (struct sockaddr *)&ca, &length);
    recvfrom(sockfd, &n3, sizeof(int), 0, (struct sockaddr *)&ca, &length);

    printf("Received three numbers are: %d\t%d\t%d\n", n1, n2, n3);
    res = n1 + n2 + n3;

    printf("Result is: %d\n", res);
    sendto(sockfd, &res, sizeof(int), 0, (struct sockaddr *)&ca, sizeof(ca));
    close(sockfd);

    return 0;
}