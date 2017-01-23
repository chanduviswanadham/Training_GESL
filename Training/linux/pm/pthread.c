#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void hello(void);
pthread_t td;
int main()
{
	if (0 != (pthread_create(td,NULL,(void*)&hello,NULL))) {
		perror("thread creation failed...!\n");
		exit(1);
	}
	printf("in process\n");
//	sleep(2);
//	pthread_exit(NULL);
	return 0;
}

void hello(void)
{
	printf("in thread....!\n");
}
