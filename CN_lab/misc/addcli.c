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
int a,b,res;

struct sockaddr_in sa;

sockfd=socket(AF_INET,SOCK_DGRAM,0);

sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");//loop back ip address
sa.sin_port=htons(6028);
printf("Enter two numbers\t");
scanf("%d%d",&a,&b);

sendto(sockfd,&a,sizeof(int),0,(struct sockaddr *)&sa,sizeof(sa));
sendto(sockfd,&b,sizeof(int),0,(struct sockaddr *)&sa,sizeof(sa));


length=sizeof(sa);
recvfrom(sockfd,&res,sizeof(int),0,(struct sockaddr *)&sa, &length);
printf("Sum Result is: %d\n",res);
close(sockfd);
}
