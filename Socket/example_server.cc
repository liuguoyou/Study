#include <stdio.h>
#include <sys/socket.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#define MAXLINE 4096
const int BUFFER_MAX_SIZE = 4096;

char buff[BUFFER_MAX_SIZE];
int listenfd, connfd;
struct sockaddr_in servaddr;
int n;
int main()
{
	listenfd = socket(AF_INET,//int domain,协议域,常见有AF_INET(IPv4), AF_INET6(IPv6),AF_LOCAL/AF_UNIX(Unix socket), AF_ROUTE等
			SOCK_STREAM,//int type, socket类型，常见有SOCK_STREAM, SOCK_DGGRAM, SOCK_RAW,SOCK_PACKET, SOCK_SEQPACKET
			0);//int protocol, 协议，常用有，IPPROTO_TCP, IPPROTO_UDP,IPPROTO_SCTP,IPPROTO_TIPC等
	if(listenfd == -1){
		printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(6666);
	//hton<s,l>(); 主机字节序转化为网络字节序
	//ntoh<s,l>(); 网络字节序转化为主机字节序
	
	//绑定特定地址给socket
	if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
		printf("bind socket error: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	if(listen(listenfd, 10) == -1){
		printf("listen socket errot: %s(errno: %d)\n", strerror(errno), errno);
		exit(0);
	}

	printf("=======waiting for client's request==========\n");
	while(1){
		if((connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
			printf("accept socket error: %s(errno: %d)\n", strerror(errno), errno);
			continue;
		}
		n = recv(connfd, buff, MAXLINE, 0);
		buff[n] = 0;
		printf("recv msg from client:%s \n", buff);
		close(connfd);
	}
	
	close(listenfd);
	return 0;
}
