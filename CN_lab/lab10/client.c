// Client side program
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int i, sockfd;
    char buf[100];
    struct sockaddr_in sa;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1"); // loop back ip address
    sa.sin_port = 60018;

    i = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    // strcpy(buf,"From Client1");

    while (1)
    {
        printf("Enter message\t");
        gets(buf);
        send(sockfd, buf, strlen(buf), 0);
        int k = recv(sockfd, buf, 100, 0);
        buf[k] = '\0';
        printf("Received same from Server: %s\n", buf);
    }
    close(sockfd);
}
