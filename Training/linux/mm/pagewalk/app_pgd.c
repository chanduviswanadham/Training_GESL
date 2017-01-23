#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int global = 10;
int main()
{
	int fd;
	pid_t pid;
	fd = open("/dev/pagewalk", O_RDWR);

	if (fd < 0) 
		perror("unable to open the device");
	else
		printf("file Opened successfully %d\n", fd);
	
	printf("global variable value before page walk:%d\n", global);
	ioctl(fd, getpid(), &global);
	printf("global variable value after page walk:%d\n", global);
	
	close(fd);

	return 0;
}
