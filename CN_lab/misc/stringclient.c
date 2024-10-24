//UDP CLIENT
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
char buf1[100],buf2[100],buf3[200];
struct sockaddr_in sa;

sockfd=socket(AF_INET,SOCK_DGRAM,0);

sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");//loop back ip address
sa.sin_port=htons(6025);
printf("Enter 1st string\t");
gets(buf1);
sendto(sockfd,buf1,strlen(buf1),0,(struct sockaddr *)&sa,sizeof(sa));
printf("Enter 2nd string\t");
gets(buf2);
sendto(sockfd,buf2,strlen(buf2),0,(struct sockaddr *)&sa,sizeof(sa));

length=sizeof(sa);
int k=recvfrom(sockfd,buf3,100,0,(struct sockaddr *)&sa,&length);
buf3[k]='\0';
printf("Received: %s\n",buf3);
close(sockfd);
}
