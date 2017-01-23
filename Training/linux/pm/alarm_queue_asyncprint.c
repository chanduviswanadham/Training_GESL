#include "errors.h"
#include <string.h>
#include <pthread.h>

struct node {
    char info[64];
	int seconds;
    struct node *link;
};

struct node *start = NULL;
struct node * temp = NULL;
struct node * p = NULL;

int count;

int status;
char line[128];

void ins_end (char * line, int sec)
{
    temp = (struct node*) malloc (sizeof (struct node));

    p = start;
    strcpy(temp -> info,line);
	temp -> seconds = sec;
    temp -> link = NULL;

    if (start == NULL){
        start = temp;
        count++;
    }else {
        while (p -> link != NULL){
            p = p -> link;
        }
        p -> link = temp;
        count++;
    }
}


char * del_pos (int pos)
{

    p = start;

    if (count == 0){       
        printf ("\nNo requests present \n");
    } else if (pos == 0) {

        strcpy(line, start -> info);

        p = p -> link;
        free (start);
		start = p;
        count --;
    }
	return line;
}

void threadfunc (void);


int main ()
{
//	char line[128];
	pthread_t thread;
	char message[64];
	int seconds;

	printf ("in main, pid is : %d \n", getpid());
	
	while (1) {

		printf("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL) {
			exit(0);
		}
		if (strlen (line) <= 1) 
			continue;
		if (sscanf (line, "%d  %64[^\n]", &seconds, message ) < 2) {
			fprintf (stderr, "Bad command\n");
		}

		ins_end (message, seconds);


		if (0 < pthread_create(&thread, NULL, (void *) threadfunc, NULL)) {
			perror ("thread creation failed\n");
			exit(0);
		}

	}
	
	return 0;
}

void threadfunc (void)
{
	char *line;
	char message[64];
	int seconds;

	line = del_pos(0);

	sleep(seconds);
	printf(" (%d) %s\n", seconds, message);
	pthread_detach(pthread_self());
}
