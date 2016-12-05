strunc#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
int main(int argc, char *argv[])
{
	int sockfd, sportno, cportno1,cportno2, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buf[256];
	if(argc<5)
	{
		printf("Error: To use, provide: ip address, server port#, client1 port#, client2 port#, and cpu usage limit.\n");
		exit(1);
	}
	sportno=atoi(argv[2]);
	cportno1=atoi(argv[3]);
	cportno2=atoi(argv[4]);
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("Error
}	
	
