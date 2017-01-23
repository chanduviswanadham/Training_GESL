#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#if 1

#define MAX 100
int main()
{
	int fd[2];
	pid_t pid;
	
	if (pipe(fd) == -1) {
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}

	pid = fork();

	if (pid > 0) {
		
		if (close(fd[0])) {   			//parent is writing end so no need of read
			perror("fail closing is failed\n");
			exit(1);
		}

		dup2(fd[1], 1);

		if ( -1 == execl("/bin/ls", "ls", NULL)) {
			perror("exev is failed........!\n");
		}
		wait(NULL); //waiting for the children exit
	
	} else if (pid == 0) {
		if (close(fd[1])) {   			//child is reading end so no need of write
			perror("fail closing is failed\n");
			exit(1);
		}

		dup2(fd[0], 0);

		if ( -1 == execl("/usr/bin/wc", "wc", "-w", NULL)) {
			perror("exev is failed........!\n");
		}
		exit(0);
		
	} else {
		
		perror("fork failed\n");
	
	}

	return 0;
}
#endif

