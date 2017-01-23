#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg) { perror(msg); exit(0); }

int main(int argc,char *argv[])
{
	/* first what are we going to send and where are we going to send it? */
	int portno =        80;
	char *message_fmt = "GET / HTTP/1.1\r\nHOST: %s\r\n\r\n";

	struct hostent *server;
	struct in_addr **addr_list;
	struct sockaddr_in serv_addr;
	char ipbuf[50];

	int sockfd;
	int bytes;
	int sent;
	int received;
	int total;

	char message[1024];
	char response[4096];

	if (argc < 2) { puts("Parameters: file name and url"); exit(0); }

	/* fill in the parameters */
//	sprintf(message,argv[1]);
//	strcpy(message, "GET /HTTP/1.1\n");
//	strcat(message, "HOST:");

//	printf("Request:\n%s\n", message);

	/* create the socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
		error("ERROR opening socket");
	
//	printf("name of the host:%s\n", argv[1]);
	/* lookup the ip address */
	if(NULL == (server = gethostbyname(argv[1])))
		error("ERROR, no such host");

	/* fill in the structure */
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
//	memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

	addr_list = (struct in_addr **)server -> h_addr_list;
	strcpy(ipbuf, inet_ntoa(*addr_list[0]));
	
//	strcat(message, "HOST:");

//	printf("from addr_list:%s", ipbuf);
	
	serv_addr.sin_addr.s_addr = inet_ntoa(ipbuf);
	
//	printf("given ip from server:%s", (char *)inet_ntoa(serv_addr.sin_addr.s_addr));

	/* connect the socket */
	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR connecting");

//	sprintf(message,message_fmt,argv[1],argv[2]);

	/* send the request */
	sprintf(message, message_fmt, ipbuf);
	
	total = strlen(message);
//	printf("sending message:%s\n", message);
//	sent = 0;
//	do {
		bytes = write(sockfd,message,total);
		if (bytes < 0)
			error("ERROR writing message to socket");
		if (bytes == 0)
//			break;
//		sent+=bytes;
//	} while (sent < total);

	/* receive the response */
	memset(response,0,sizeof(response));
//	total = sizeof(response)-1;
	received = 0;
	do {
		bytes = read(sockfd,response+received ,4096 - received);
		if (bytes < 0)
			error("ERROR reading response from socket");
		if (bytes == 0)
			break;
		received+=bytes;
		printf("Response:\n%s\n",response);
	} while (response != NULL);

//	if (received == total)
//		error("ERROR storing complete response from socket");

	/* close the socket */
	close(sockfd);

	/* process response */

	return 0;
}
