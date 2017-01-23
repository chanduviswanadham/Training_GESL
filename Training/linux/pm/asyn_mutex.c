#include "errors.h"
#include <pthread.h>
#include <time.h>

void del();
void ins(char *);
void *th_func(void *);

typedef struct list {
	int sec;
	int sec_print;
	char msg[120];
	struct list *next;
}stru_name;

stru_name *head = NULL;

typedef struct my_struct_tag {
	pthread_mutex_t resource;
	pthread_cond_t cond1;
	pthread_cond_t cond2;
	struct list *head;
}my_struct_t;

my_struct_t data = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER,NULL};

int main( void )
{
	char line[120];
	pthread_t tid;
	int status;
	status = (pthread_create(&tid, NULL, &th_func, NULL));
	if(0 != status) {
		err_abort(status, "thread create failed\n");
		exit(1);
	}
	while(1) {
		printf("Alarm > ");
		if(fgets(line, sizeof(line), stdin) == NULL) {
			perror("fgets failed");
			exit(0);
		}
		
		if(strlen(line) <= 1) {
			continue;
		} else {
			status = pthread_mutex_lock(&(data.resource));
			if (0 != status) {
				err_abort(status ,"lock filed\n");
			}
			ins(line);
			status = pthread_mutex_unlock(&(data.resource));
			if (0 != status) {
				err_abort(status ,"unlock filed\n");
			}
		}
	
	}

}

void ins(char *str)
{
	stru_name *temp;
	stru_name *p = NULL;
//	time_t ti;
	stru_name *prev = NULL;
	
	if(NULL == (temp = (stru_name *) malloc (sizeof(stru_name)))) {
		perror("malloc failed\n");
		exit(1);
	}

	if(sscanf(str, "%d %64[^\n]", &(temp -> sec), temp -> msg) < 2) {
		fprintf(stderr, "Bad command \n");
	} else { 
		temp -> sec_print = temp -> sec;
		temp -> sec = (temp -> sec) + time(NULL);
		if(head == NULL) {
			head = temp;
			temp -> next = NULL;
			pthread_cond_signal(&(data.cond1));
		} else {
			p = head;
			while ((p != NULL) && (p -> sec) < (temp -> sec)) {
				prev = p;
				p = p -> next;
			}
			if (p == NULL) {
				prev -> next = temp;
				temp -> next = NULL;
			} else if (prev == NULL) {
				temp -> next = head;
				head = temp;
				pthread_cond_signal(&(data.cond2));
			} else {
				temp -> next = p;
				prev -> next = temp;
			}
		}
	}
}
void del()
{
	stru_name *p = head;

	head = head -> next;
	free(p);
}

void *th_func(void *line)
{
	int status;
	struct timespec *abs = NULL;
	
	while(1) {
		status = pthread_mutex_lock(&(data.resource));
		if (0 != status) {
			err_abort(status ,"lock filed\n");
		}
		if(head == NULL) {
//			sleep(1);
//			continue;
			pthread_cond_wait( &(data.cond1), &(data.resource));
//			continue;
		}
		
//		sleep((head -> sec) - time(&ti));
		if (NULL == (abs = (struct timespec*) malloc (sizeof(struct timespec*)))) {
			perror("malloc failed\n");
			exit(0);
		}
		
		abs -> tv_sec = (head -> sec);
		abs -> tv_nsec = 0;
		status = pthread_cond_timedwait( &(data.cond2), &(data.resource), abs);
		if (status == ETIMEDOUT) {
			printf("(%d) %s \n", head -> sec_print, head -> msg);
			del();
		} 
//			continue;
		status = pthread_mutex_unlock(&(data.resource));
			if (0 != status) {
				err_abort(status ,"unlock filed\n");
			}
		free(abs);
	}
	return NULL;
}
