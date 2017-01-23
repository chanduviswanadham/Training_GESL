#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "errors.h"
#if 1
void verify(int);
int main()
{
	if ( signal(SIGUSR1, verify) == SIG_ERR) {
		printf("signal sending failed\n");
	}
	if ( signal(SIGUSR2, verify) == SIG_ERR) {
		printf("signal sending failed\n");
	}
	kill(getpid(),SIGUSR1);
	kill(getpid(),SIGUSR2);
	kill(getpid(),SIGUSR1);
	return 0;

}

void verify(int signo)
{
	if (signo == SIGUSR1) {
		printf("signal 1 is received\n");
	} else if (signo == SIGUSR2) {
		printf("signal 2 is received\n");
	}
}

#endif

#if 0
void verify(int);
int main()
{
	pid_t pid;
	pid = fork();
	if (pid > 0) {
		if ( signal(SIGCHLD, verify) == SIG_ERR) {
			printf("signal sending failed\n");
		}
		wait(NULL);
		getchar();
	} else if (pid == 0) {
		printf("in child process\n");
		getchar();
	} else {
		errno_abort("fork failed\n");
	}

	return 0;

}

void verify(int signo)
{
	if (signo == SIGCHLD) {
		printf("child killed\n");
	}
}
#endif

#if 0
typedef int * i;
void seg_fau(int signo, siginfo_t *sir,void *arg)
{
		printf("segfault .....core dump\n");
		printf("sending process pid:%d", sir -> si_signo);
		exit(1); //if we not put this the code will execute n noof times
					// and generates sigsegv n no of times
}

int main()
{
	struct sigaction sig;
	int a = 10;
	i *ptr = &a;
	sig.sa_sigaction = seg_fau;
	sig.sa_flags = SA_SIGINFO;
	if(sigaction(SIGSEGV, &sig, NULL)) {
		perror("signal calling failed\n");
	}
	printf("%d", **ptr);
	return 0;
}
#endif

#if 0
void verify(int);
struct sigaction sig;
int main()
{
	sig.sa_handler = &verify;
	if ( sigaction(SIGINT, &sig, NULL) == -1) {
		perror("signal sending failed\n");
		exit(1);
	}
	sleep(10);
	return 0;

}

void verify(int signo)
{
		printf("sigaction working\n");
}

#endif
