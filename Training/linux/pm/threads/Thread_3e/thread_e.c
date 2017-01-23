#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define MAX 20

int fd;
int fd1;
int flag = 0;

void *thread(void *i)
{
	int status;
	pid_t pid;
	char str1[MAX] = "Software limited \n";

	pid = getpid();

	do {
	} while (flag == 0);

	if(write(fd, str1, sizeof(str1)) == -1) {
		perror("thread:write failed");
	}
	if(-1 == (status = ioctl(fd1, pid, fd))) {
		perror("Error");
	}
	close(fd);		

	pthread_exit(NULL);
}
int main(void)
{
	pid_t pid;
	pthread_t tid;
	int status;

	char str[MAX] = "Global Edge ";

	if((fd = open("just.txt", O_RDWR)) == -1) {
		perror("open failed");
		exit(EXIT_FAILURE);
	}

	fd1 = open ("/dev/myChar", O_RDWR);
	if(fd1 < 0)
		perror("Unable to open the device \n");
	else
		printf("File opened Successfully %d\n", fd1);


	if(status = pthread_create(&tid, NULL, thread, NULL) == -1)
		perror("error");

	if(write(fd, str, sizeof(str)) == -1) {
		perror("write failed");
		exit(EXIT_FAILURE);
	}
	if(-1 == (status = ioctl(fd1, pid, fd))) {
		perror("Error");
	}
	pthread_join(&tid, NULL);

	close(fd); 
	flag = 1;
	
	pthread_exit(NULL);
	return 0;
}

