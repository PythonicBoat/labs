#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int sockfd, clientfd[5], length, b, i;
    char buf[100];
    struct sockaddr_in sa, ta1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = 60018;

    b = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    printf("test %d%d\n", sockfd, b);

    listen(sockfd, 5);

    length = sizeof(sa);

    struct timeval timeout;

    fd_set allfd, readfd;
    FD_ZERO(&allfd);
    FD_SET(sockfd, &allfd);
    int maxfd = sockfd + 1;
    i = 0;
    while (1)
    {
        readfd = allfd; // to copy all the fds to readfd

        timeout.tv_sec = 30;  // second value
        timeout.tv_usec = 50; // micro-second value

        int k = select(maxfd, &readfd, NULL, NULL, &timeout);
        // printf("Select value=%d\n",k);
        if (FD_ISSET(sockfd, &readfd))
        {
            clientfd[i] = accept(sockfd, (struct sockaddr *)&ta1, &length);
            FD_SET(clientfd[i], &allfd);
            if (clientfd[i] >= maxfd)
                maxfd = clientfd[i] + 1;
            i++;
        }
        for (int j = 0; j < i; j++)
        {
            if (FD_ISSET(clientfd[j], &readfd))
            {
                int m = recv(clientfd[j], buf, 100, 0);
                if (m == 0)
                {
                    close(clientfd[j]);
                    FD_CLR(clientfd[j], &allfd);
                }
                else
                {
                    buf[m] = '\0';
                    printf("%s\n", buf);
                    send(clientfd[j], buf, strlen(buf), 0);
                }
            }
        }
    }
    close(sockfd);
}
