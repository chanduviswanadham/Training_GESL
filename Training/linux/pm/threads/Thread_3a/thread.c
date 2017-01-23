#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int g_var = 10;
int *h_var;
int fd1;
int fd;

void *thread(void *i)
{
/*	int status;

	if(-1 == (status = ioctl(fd1, getpid(), fd))) {                                    perror("Error");                                                        
    } 
*/
	printf("g_var is %d and address is %p\n", g_var, &g_var);
	g_var = 20;
//	printf("l_var is %d and address is %p\n", l_var, &l_var);
	printf("h_var is %d and address is %p\n", *h_var, h_var);
	*h_var = 40;
	printf("g_var is %d and address is %p\n", g_var, &g_var);
	printf("h_var is %d and address is %p\n", *h_var, h_var);
	pthread_exit(NULL);
}
int main(void)
{
	pid_t pid;
	pthread_t tid;
	int status;

	h_var = malloc(sizeof(int));
	*h_var = 30;

/*	fd1 = open ("/dev/MyChar", O_RDWR);
	if(fd1 < 0)
		perror("Unable to open the device \n");
	else
		printf("File opened Successfully %d\n", fd1);
*/
	printf("g_var is %d and address is main %p\n", g_var, &g_var);
	printf("h_var is %d and address is main %p\n", *h_var, h_var);
	
	if((status = pthread_create(&tid,NULL,thread,NULL)) == -1)
		printf("Error ");
/*
	if(-1 == (status = ioctl(fd1, pid, fd))) {
		perror("Error");
	}
*/
	printf("g_var is %d and address is main after %p\n", g_var, &g_var);
//	printf("l_var is %d and address is %p\n", l_var, &l_var);
	printf("h_var is %d and address is main after %p\n", *h_var, h_var);

	pthread_exit(NULL);
	return 0;
} 
