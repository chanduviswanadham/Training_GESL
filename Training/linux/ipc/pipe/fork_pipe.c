#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#if 1
int main()
{
	int fd[2];
	pid_t pid;
	char buf[100];
	char buf1[100];
	printf("enter the buffer that you want to pipe:\n");
	if (NULL == fgets(buf, sizeof(buf), stdin)) {
		perror("fgets failed........!\n");
		exit(0);
	}
	*(buf + ((strlen(buf) - 1))) = '\0';
//	printf("%s\t%d\n", buf, strlen(buf));
//	buf[strlen(buf)] = '\0';
	
	if (pipe(fd) == -1) {
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}

	pid = fork();

	if (pid > 0) {
		close(fd[0]);  //parent is writing end so no need of read
		write(fd[1], buf, strlen(buf));
//		printf("par:%s\t%d\n", buf, strlen(buf));
		close(fd[1]);
		wait(NULL); //waiting for the children exit
	} else if (pid == 0) {
		close(fd[1]); //child is reading end so no need of write
//		printf("buf in child:%s\t%d\n", buf, strlen(buf));
		read(fd[0], buf, strlen(buf));
//		printf("child buf 1:%s\t%d\n", buf1, strlen(buf1));
		printf("%s\n", buf);
		close(fd[0]);
		exit(1); 
	} else {
		perror("fork failed\n");
	}
	return 0;
}
#endif

