#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include"errors.h"

int g_var = 10;
int *h_var;
int fd1;

void *thread(void *i)
{
	g_var = 90;
	*h_var = 80;
	int l_var1 = 30;
	int status;

	if(-1 == (status = ioctl(fd1, getpid(), 3))) {                                    perror("Error");                                                        
    }
 
	printf("Thread pid id %d\n", getpid());
	printf("Address is %p\n", &l_var1);
	getchar();

	printf("g_var is %d and address is %p\n", g_var, &g_var);
//	printf("l_var is %d and address is %p\n", l_var, &l_var);
	printf("h_var is %d and address is %p\n", *h_var, h_var);

	pthread_exit(NULL);
}
int main(void)
{
	pid_t pid;
	pthread_t tid;
	int status;

	fd1 = open ("/dev/MyChar", O_RDWR);
	if(fd1 < 0)
		perror("Unable to open the device \n");
	else
		printf("File opened Successfully %d\n", fd1);


	int l_var = 20;
	printf("Thread group leaer pid is %d\n", getpid());
	printf("address is %p\n",&l_var);
	getchar();

	h_var = malloc(sizeof(int));
	*h_var = 30;
	
	if((status = pthread_create(&tid,NULL,thread,NULL)) == -1)
		err_abort(status, "pthread_create() failed");

	if(-1 == (status = ioctl(fd1, pid, 3))) {
		perror("Error");
	}
	
	pthread_join(tid, NULL);

	printf("g_var is %d and address is %p\n", g_var, &g_var);
//	printf("l_var is %d and address is %p\n", l_var, &l_var);
	printf("h_var is %d and address is %p\n", *h_var, h_var);

	pthread_exit(NULL);
	return 0;
} 
