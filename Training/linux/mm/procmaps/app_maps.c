#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>

int main( void )
{
	int fd;
	int *ptr = NULL;

	if(NULL == (ptr = (int *) malloc(sizeof(int)))) {
		perror("malloc failed");
		exit(1);
	}

	if(0 > (fd = open("/dev/proc", O_RDWR))) {
		perror("open failed");
		exit(1);
	}
	
	printf("pid from app%d\n", getpid());

	printf("file opened successfully %d \n", fd);

	ioctl(fd, getpid(), 1);
	getchar();

	close(fd);
	
	return 0;
}
