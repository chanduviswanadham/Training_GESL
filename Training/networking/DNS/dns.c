#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
#include <sys/types.h>                                                          
#include <sys/socket.h>                                                         
//#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 150                                                                 

//#define error(message) \
		perror(#message);\
		exit(1);                                                                
void error(const char *msg) {perror(msg); exit(0); }

int main(int argc, char *argv[])
{
//	char *message = "POST /apikey=%s&command=%s HTTP/1.0\r\n\r\n";
	char request[100];
	struct hostent *server = NULL;
	struct in_addr **addr_list;
	int sockfd, i, bytes;
	char ip[100];
	struct sockaddr_in server_addr;
	char response[4096];

	int sent, received, total = 0;
	

	if(argc != 2) {
		perror("invalid request from command line....!");

		exit(1);
	}

	printf("Your request:%s\n", argv[1]);
	
	strcpy(request, "POST /apikey=");
	strcat(request, argv[1]);
	strcat(request, "&command=(null) HTTP/1.0");
	
	printf("Your request:%s\n", request);

	

	if ( 0 > (sockfd = socket(AF_INET, SOCK_STREAM, 0))) {
		error("socket opening failed");
	}

	if (NULL == (server = (struct hostent *) gethostbyname(argv[1]))) {
		error("no such host");
	}
	
	addr_list = (struct in_addr**) (server -> h_addr_list);

	strcpy(ip, inet_ntoa(*addr_list[0]) );
	
	printf("resloved ip:%s\n", ip);

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(80);
	server_addr.sin_addr.s_addr = inet_addr(ip);
	

	if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		error("ERROR connecting");
	}

	total = strlen(request);
/*	sent = 0;
	do {
		bytes = write(sockfd, argv[1] + sent, total - sent);
*/		bytes = write(sockfd, request, total);
		
/*		if(bytes < 0) {
			error(writing failed);
		}
		if (bytes == 0) {
			break;
		}
		sent = sent + bytes;
	} while (sent < total);
*/	
	printf("sended bytes:%d\n", bytes);
	memset(response, 0, sizeof(response));
	total = sizeof(response) - 1;
	received = 0;
	do {
		bytes = read(sockfd, response+received, total - received);
//		bytes = read(sockfd, response, sizeof(response));
		if(bytes < 0) {
			error("reading failed");
		}
		if (bytes == 0) {
			break;
		}
		received = received + bytes;
	} while (received < total);

	if(received == total)
			error("error storing complete response from the socket");

	close(sockfd);
	printf("response:\n%s\n", response);

	return 0;
}
