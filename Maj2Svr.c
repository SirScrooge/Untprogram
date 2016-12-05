#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	int sockfd,newsockfd,portno,clilen, n,sum=0,num=0;
	char buf[256];
	struct sockaddr_in serv_addr, cli_addr;
	if (argc<2)
	{
		printf("Error: no port number provided.\n");
		exit(1);
	}
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("Error: Can't open socket.\n");
		exit(1);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(portno);
	sserv_addr.sin_addr.s_addr=INADDR_ANY;
	
	if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeor(serv_addr))<0)
	{
		printf("Error on binding.\n");
		exit(1);
	}
	while(1)
	{
		
		listen(sockfd,5);
		clilen=sizeof(cli_addr);
		newsockfd=accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
		if(newsockfd<0)
		{
			printf("Error on accept.");
			exit(1);
		}
		bzero(buf,256);
		n=read(newsockfd,buf,255);
		if(n<0)
		{
			printf("Error: Can't read from socket.");
			exit(1);
		}
		num=atoi(buf);
		sum=num+sum;
		printf("%d\n",sum);
	}
