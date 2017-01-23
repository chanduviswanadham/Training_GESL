#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <error.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 256

int main()
{
	mqd_t mq_d;
	pid_t pid;
	char *send_ptr = NULL; //"chandu viswanadham";
	char *rec_ptr = NULL;
	struct mq_attr *attr = NULL;

	if ( -1 == (mq_d = mq_open("/myqueue", O_RDWR | O_CREAT, 0666, NULL))) {
		perror("que opening is failed");;
		exit(1);
	}

	if (NULL == (attr = (struct mq_attr*) malloc (sizeof(struct mq_attr)))) {	
		perror("malloc failed..........!");
		exit(1);
	}

	if ( -1 == mq_getattr(mq_d, attr)) {
		perror("getting attr is failed..........\n");
		exit(1);
	}
	
	pid = fork();

	if (pid > 0) {
		
		printf("enter your message(parent):");
		
		if (NULL == (send_ptr = (char *) malloc(sizeof(char) * MAX))) {
			perror("malloc failed...!\n");
			exit(1);
		}
		
		if (NULL == (fgets(send_ptr, MAX, stdin))) {
			perror("fgets failled...\n");
			exit(1);
		}

		if (-1 == (mq_send(mq_d, send_ptr, attr -> mq_msgsize, 0))) {
			perror("mq_send failed\n");
			exit(1);
		}
		
		mq_close(mq_d);
		wait(&pid);
	
	} else if (pid == 0) {
		
//		sleep(2);
		
		if (NULL == (rec_ptr = (char *) malloc(sizeof(char)))) {
			perror("malloc failed.....\n");
			exit(1);
		}

		if (-1 == (mq_receive(mq_d, rec_ptr, (attr -> mq_msgsize) + 1, 0))) {
			perror("mq_receive failed\n");
			exit(1);
		}
		printf("received message in child:\t%s", rec_ptr);
		mq_close(mq_d);
		exit(0);

	} else {
		printf("fork failed.............!\n");
	
	}
	if ( -1 == mq_unlink("/myqueue")) {
		perror("unlink is failed.........\n");
		exit(1);
	}
	free(rec_ptr);
	free(attr);
	return 0;
}
		

