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

	pid = fork();
	if (pid > 0){
		wait();
		printf("in parent\n");
		ioctl(fd,getpid(),100);
	} else if(pid == 0) {
		printf("in child\n");
		ioctl(fd,getpid(),100);
	} else {
		printf("fork failed......!");
	}
	//printf("in application pid is:%d\n", getpid());
	close(fd);

	return 0;
}
