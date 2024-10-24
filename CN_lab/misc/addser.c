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
int n1,n2,res;
struct sockaddr_in sa,ca;

sockfd=socket(AF_INET,SOCK_DGRAM,0);

sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=htons(6028);

i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
printf("test %d%d\n",sockfd,i);

length=sizeof(sa);
recvfrom(sockfd,&n1,sizeof(int),0,(struct sockaddr *)&ca,&length);
recvfrom(sockfd,&n2,sizeof(int),0,(struct sockaddr *)&ca,&length);

printf("Received two no. are: %d\t%d\n:",n1,n2);
res=n1+n2;

printf("Result is: %d\n",res);
sendto(sockfd,&res,sizeof(int),0,(struct sockaddr *)&ca,sizeof(ca));
close(sockfd);
}
