/*
 * alarm.c
 * 
 * Simple synchronous alarm program. This is used as a
 * reference for progressive examples of synchronous 
 * alarm programs.
 */

#include "errors.h"
#include <signal.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
	int seconds;
	char line[128];
	char message[64];
	int pid;
	int status;
	while (1) {
/*		do {
			status = waitpid(-1, NULL, WNOHANG);
			if ( -1 == status) {
				break;
			}
		}while (0 != status);
*/		
		printf("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL) {
			printf("\n");
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
		} else {
			pid = fork();
			if (pid > 0) {
				signal(SIGCHLD,SIG_IGN);
				continue;
			
			} else if (pid == 0) {
				sleep(seconds);
				printf(" (%d) %s\n", seconds, message);
				exit(0);
			}
		}
	}
}
