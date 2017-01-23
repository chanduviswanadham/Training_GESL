#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	pid_t pid;
	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0) 
		perror("unable to open the device");
	else
		printf("file Opened successfully %d\n", fd);
	
	ioctl(fd,getpid(),100);
	
	close(fd);

	return 0;
}
