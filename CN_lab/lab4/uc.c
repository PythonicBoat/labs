// UDP CLIENT
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int i, sockfd, length;
    char buf[100], buf1[100];
    struct sockaddr_in sa;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1"); // loop back ip address
    sa.sin_port = htons(6025);
    printf("Enter a message\t");
    gets(buf);
    sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&sa, sizeof(sa));
    length = sizeof(sa);
    int k = recvfrom(sockfd, buf1, 100, 0, (struct sockaddr *)&sa, &length);
    buf1[k] = '\0';
    printf("Received: %s\n", buf1);
    close(sockfd);
}
