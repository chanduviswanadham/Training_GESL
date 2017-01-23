#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

const int global = 10;
int main()
{
	int fd;
	const int global_func = 12;
	pid_t pid;
	fd = open("/dev/pagewalk", O_RDWR);

	if (fd < 0) 
		perror("unable to open the device");
	else
		printf("file Opened successfully %d\n", fd);
	
	ioctl(fd, getpid(), &global);
	printf("global value :%d", global);
	ioctl(fd, getpid(), &global_func);
	printf("global value :%d", global_func);
	
	close(fd);

	return 0;
}
