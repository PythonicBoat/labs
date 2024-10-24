#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int sockfd,fd1[5],length,i,j;
char buf[100],buf1[100];
struct sockaddr_in sa,ca[5];

sockfd=socket(AF_INET,SOCK_STREAM,0);

sa.sin_family=AF_INET;
sa.sin_addr.s_addr=inet_addr("127.0.0.1");
sa.sin_port=htons(6034);

i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
printf("test %d%d\n",sockfd,i);

listen(sockfd,5);

length=sizeof(sa);

for(j=0;j<5;j++)
{
fd1[j]=accept(sockfd,(struct sockaddr *)&ca[j],&length);
}
for(j=0;j<5;j++)
{
int k=recv(fd1[j],buf,100,0);
buf[k]='\0';
printf("%s\n",buf);

printf("Enter a message\t");
gets(buf1);
send(fd1[j],buf1,strlen(buf1),0);
}

close(sockfd);
for(j=0;j<5;j++){
close(fd1[j]);
}
}