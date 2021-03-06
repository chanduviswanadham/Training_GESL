/*
 * asyn_alarm.c
 *
 */

#include "errors.h"

int main (int argc, char *argv[])
{
	int seconds;
	char line[128];
	char message[64];
	int pid;

	while (1) {
		printf("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL) {
			exit(0);
		}
		if (strlen (line) <= 1) 
			continue;

		/*
		 * Parse input in to seconds (%d) and a message
		 * (%64[^\n]), consisting of up to 64 characters
		 * seperated from seconds by whitespaces
		 */

		if (sscanf (line, "%d  %64[^\n]", &seconds, message ) < 2) {
			fprintf (stderr, "Bad command\n");
		} else if ((pid = fork()) > 0) {
			wait(NULL);
		} else if(pid == 0){
			sleep(seconds);
			printf(" (%d) %s\n", seconds, message);
			exit(0);
		}
	}
}

