#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>


#include"errors.h"
#if 1
	int fd;
void *thread(void *i)
{
	int status;
	pid_t pid;

	pid = syscall(SYS_gettid);
	printf("Thread pid is %d\n", pid);   

	if(-1 == (status = ioctl(fd, pid, 0))) {
		errno_abort("ioctl failed");
	}

	read (0, &status, 4);
	pthread_exit(NULL);
}
int main(void)
{
	pthread_t tid;
	int status;

	printf("pid is %d\n", getpid());

	fd = open ("/dev/myChar", O_RDWR);
	if(fd < 0) {
		errno_abort("open failed");
	}
	else
		printf("File opened Successfully %d\n", fd);


	    if(status = pthread_create(&tid, NULL, thread, NULL)) {
			err_abort(status, "pthread_create() failed");
		}
	if(-1 == (status = ioctl(fd, getpid(), 0))) {
		errno_abort("ioctl failed");
	}
	printf("Thread Group Leader \n");

	pthread_exit(NULL);
	return 0;
}
#endif
