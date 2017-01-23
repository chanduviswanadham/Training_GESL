#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int data = 15;
	pid = fork();
	
	if (pid > 0) {
		printf("parent\n");
		sleep(15);
	} else if (pid == 0) {
		printf("child\n");
		sleep(10);
		data = 20;
		sleep(20);
	} else {
		printf("fork failed.........!");
	}
	return 0;
}
