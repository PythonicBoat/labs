//UDP SERVER
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
int sockfd,fd1,length,i;
char buf1[100],buf2[100], buf3[200];
struct sockaddr_in sa,ca;

sockfd=socket(AF_INET,SOCK_DGRAM,0);

sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=htons(6025);

i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
printf("test %d%d\n",sockfd,i);

length=sizeof(sa);
int k=recvfrom(sockfd,buf1,100,0,(struct sockaddr *)&ca,&length);
buf1[k]='\0';
printf("Received: %s\n",buf1);
int k2=recvfrom(sockfd,buf2,100,0,(struct sockaddr *)&ca,&length);
buf2[k2]='\0';
printf("Received: %s\n",buf2);

strcpy(buf3,strcat(buf1,buf2));
sendto(sockfd,buf3,strlen(buf3),0,(struct sockaddr *)&ca,sizeof(ca));
close(sockfd);
}
