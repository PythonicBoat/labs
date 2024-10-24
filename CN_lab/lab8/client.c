//TCP CLIENT
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
int i,sockfd,length;
char buf[100],buf1[100];
struct sockaddr_in sa;

sockfd=socket(AF_INET,SOCK_STREAM,0);

sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");//loop back ip address
sa.sin_port=htons(6034);

i = connect(sockfd,(struct sockaddr*)&sa,sizeof(sa));
printf("Enter a message\t");
scanf("%s",buf);
send(sockfd,buf,strlen(buf),0);
length=sizeof(sa);
int k=recv(sockfd,buf1,100,0);
buf1[k]='\0';
printf("Received: %s\n",buf1);
close(sockfd);
}