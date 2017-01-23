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
	struct list **head;
}my_struct_t;

my_struct_t data = {PTHREAD_MUTEX_INITIALIZER, &head};

int main( void )
{
	int flag = 0;
	char line[120];
	pthread_t tid;
	int status;
	
	if(0 != (pthread_create(&tid, NULL, &th_func, NULL))) {
		perror("thread create failed");
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
	time_t ti;
	
	if(NULL == (temp = (stru_name *) malloc (sizeof(stru_name)))) {
		perror("malloc failed\n");
		exit(1);
	}

	if(sscanf(str, "%d %64[^\n]", &(temp -> sec), temp -> msg) < 2) {
		fprintf(stderr, "Bad command \n");
	} else { 
		temp -> sec_print = temp -> sec;
		temp -> sec = (temp -> sec) + time(&ti);
		if(head == NULL) {
			head = temp;
			temp -> next = NULL;
		} else {
			p = head;
			while ((p -> next != NULL) && (p -> next -> sec_print) < (temp -> sec_print)) {
				p = p -> next;
			}
			if (p -> next == NULL) {
				temp -> next = NULL;
			} else {
				temp -> next = p -> next;
			}
			p -> next = temp;
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
	time_t ti;
	int status;
	
	while(1) {
		if(head == NULL) {
			sleep(1);
			continue;
		}
		
		sleep((head -> sec) - time(&ti));
//		pthread_cond_timewait()
		printf("(%d) %s \n", head -> sec_print, head -> msg);
		status = pthread_mutex_lock(&(data.resource));
		if (0 != status) {
			err_abort(status ,"lock filed\n");
		}
		del();
		status = pthread_mutex_unlock(&(data.resource));
		if (0 != status) {
			err_abort(status ,"unlock filed\n");
		}
	}
	return NULL;
}
