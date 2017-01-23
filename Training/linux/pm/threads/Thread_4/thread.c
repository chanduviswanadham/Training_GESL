#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int g_var = 10;

void *thread(void *i)
{
	int l_var = 70;
	int *h_var = malloc(sizeof(int));

	g_var = 80;
	*h_var  = 90;

	printf("g_var is %d and address is %p\n", g_var, &g_var);
	printf("l_var is %d and address is %p\n", l_var, &l_var);
	printf("h_var is %d and address is %p\n", *h_var, h_var);

	pthread_exit(NULL);
}
int main(void)
{
	pid_t pid;
	pthread_t tid;
	int status;

	int l_var = 20;
	int *h_var = malloc(sizeof(int));

	*h_var = 30;
	
	if((status = pthread_create(&tid,NULL,thread,NULL)) == -1)
		printf("Error ");

	printf("g_var is %d and address is %p\n", g_var, &g_var);
	printf("l_var is %d and address is %p\n", l_var, &l_var);
	printf("h_var is %d and address is %p\n", *h_var, h_var);

	pthread_exit(NULL);
	return 0;
} 
