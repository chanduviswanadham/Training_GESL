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
	char rec_ptr[MAX] = {'\0'}; //"chandu viswanadham";
	char *pathname = "./myfifo"; 
	
	if ( -1 == (fd = open(pathname, O_RDONLY))) {
		perror("que opening is failed");;
		exit(1);
	}
		
/*	if (NULL == (rec_ptr = (char *) malloc(sizeof(char) * MAX))) {
		perror("malloc failed...!\n");
		exit(1);
	}
		
*/	if (-1 == (read(fd, &rec_ptr,sizeof(rec_ptr)))) {
		perror("write failed\n");
		exit(1);
	}
	printf("received message:%s\n", rec_ptr);
		
	close(fd);
	if (-1 == unlink(pathname)) {
		perror("unlink failed...........!");
		exit(1);
	}

//	free(rec_ptr);
	return 0;
}
		

