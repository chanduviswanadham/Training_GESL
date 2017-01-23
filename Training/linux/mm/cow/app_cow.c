#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <sys/wait.h>

unsigned long glob = 5;

int main( void )
{
	int fd;
	pid_t pid;
	int *ptr = malloc(4);
	int stack = 4;

	*ptr = 20;
	fd = open("/dev/cow", O_RDWR);
	
	printf("pid from app%d\n", getpid());

	if(fd < 0) {
		perror("unable to open the device");
	} else {
		printf("file opened successfully %d \n", fd);
	}

	
	ioctl(fd, getpid(), &glob);
	
	pid = fork();
	if(pid > 0) {
/*		if(-1 == wait(NULL)) {
			perror("wait failed");
			exit(1);
		}
*/	
		printf("in parent %p\n", &stack);
		printf("in parent %p\n", ptr);
		printf("in parent %p\n", &glob);

		ioctl(fd, getpid(), &stack);

		ioctl(fd, getpid(), ptr);

		ioctl(fd, getpid(), &glob);

/*		sleep(2);

		*ptr = 50;
		stack = 5;
		glob = 24;

		printf("in par after modify %p\n", &glob);
		printf("in par after modify %p\n", &stack);
		printf("in par after modify %p\n", ptr);

		ioctl(fd, getpid(), &stack);

		ioctl(fd, getpid(), ptr);

		ioctl(fd, getpid(), &glob);

*/		if(-1 == wait(NULL)) {
			perror("wait failed");
			exit(1);
		}

	} else if(pid == 0) {
		
//		sleep(2);
		printf("in chld %p\n", &stack);
		printf("in child %p\n", ptr);
		printf("in child %p\n", &glob);

		ioctl(fd, getpid(), &stack);

		ioctl(fd, getpid(), ptr);

		ioctl(fd, getpid(), &glob);

		sleep(2);

		*ptr = 50;
		stack = 5;
		glob = 24;

		printf("in child after modify %p\n", &stack);
		printf("in child after modify %p\n", ptr);
		printf("in child after modify %p\n", &glob);

		ioctl(fd, getpid(), &stack);

		ioctl(fd, getpid(), ptr);

		ioctl(fd, getpid(), &glob);
		exit(0);

	} else {
		perror("fork failed");
		exit(1);
	}

	close(fd);

	return 0;
}
