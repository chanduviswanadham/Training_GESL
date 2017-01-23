#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>
#include"errors.h"

#if 1

void *thread(void *i)
{
	pid_t pid;

	printf("Thread pid is %d\n", pid);   


	pthread_exit(NULL);
}

int main(void)
{
	pthread_t tid;
	int status;

	printf("pid is %d\n", getpid());

	if(status = pthread_create(&tid, NULL, thread, NULL)) {
			err_abort(status, "pthread_create() failed");
		}
	printf("Thread Group Leader \n");

	pthread_exit(NULL);
	return 0;
}

#endif

