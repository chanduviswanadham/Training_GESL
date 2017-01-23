#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *mythread(void *);

int flag = 1;

int main( void )
{
	pthread_t td;

	if (0 != (pthread_create(&td,NULL,&mythread,NULL))) {
		perror("thread creation failed...!\n");
		exit(1);
	}

	printf("in process\n");
	sleep(2);

	flag = 5;
	pthread_exit(NULL);

	return 0;
}

void *mythread(void * arg)
{
	long long count = 0;
	printf("in thread....!\n");
	while( flag != 5 ) {
//	printf("in loop waiting for value changing\n");
//		count++;
	}
	printf("count:%Ld\nfalg %d\n", count, flag);
}
