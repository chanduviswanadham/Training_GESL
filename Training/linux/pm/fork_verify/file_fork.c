#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fp;
	pid_t pid;
	char *buf = "global edge"; 
	char *buf1 = "software limited"; 
	if(0 == (fp = open("just.txt", O_RDWR | 0666))) {
		printf("file is not opened\n");
		exit(0);
	}
	pid = fork();

	if ( pid > 0) {
		write(fp,"global edge ", 12);
		close(fp);
		wait(pid);

	} else if (pid == 0) {
		write(fp, "software limited\n", 17);
		close(fp);
	} else {
		printf("fork filed\n");
	}
	return 0;
}

