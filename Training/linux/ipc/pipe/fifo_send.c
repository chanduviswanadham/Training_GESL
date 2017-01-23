#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <error.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>			  
#include <string.h>
#define MAX 256

int main()
{
	int fd;
	char *send_ptr = NULL; //"chandu viswanadham";
	char *pathname = "./myfifo"; 
	
	printf("enter your message:");
		
	if (NULL == (send_ptr = (char *) malloc(sizeof(char) * MAX))) {
		perror("malloc failed...!\n");
		exit(1);
	}
		
	if (NULL == (fgets(send_ptr, MAX, stdin))) {
		perror("fgets failled...\n");
		exit(1);
	}
	
	if (-1 == mkfifo(pathname, 0666)) {
		perror("mkfifo failed......!\n");
		exit(1);
	}

	if ( -1 == (fd = open(pathname, O_WRONLY))) {
		perror("que opening is failed");;
		exit(1);
	}

	if (-1 == (write(fd, send_ptr,strlen(send_ptr)))) {
		perror("write failed\n");
		exit(1);
	}
		
	close(fd);
		
/*	if ( -1 == unlink(pathname)) {
		perror("unlink is failed.........\n");
		exit(1);
	}
*/	free(send_ptr);
	return 0;
}
		

