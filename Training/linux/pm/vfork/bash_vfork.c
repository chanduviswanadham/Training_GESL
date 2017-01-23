#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//program using /bin/bash directly

#if 0

int main(int argc, char *argv[])
{
	pid_t pid;
//	pid = fork();
	pid = vfork();
	char command[100];
	
	if ( pid > 0) {
	//	wait();
		printf("child killed \n");
	} else if(pid == 0) {
		printf("******************viswanadham@user*****************\n\n\n");
		execl("/bin/bash", 0);   
	} else {
		printf("fork failed.......!");
	}
	return 0;
}

#endif

//program using own bash 

#if 1 

#define MAX 50

int main ( void )
{
	printf("**********VISWANADHAM@USER************ \n");
	
	while (1) { 
		
		char *argv[MAX];
		int i = 0;
		char *delimit = "\n ";
		pid_t pid;
		char arr[MAX]= {'\0'};   	
		
		printf("viswanadham@user$:");
		if (NULL == (fgets(arr,80,stdin))) {
			perror("fgets failed.........!");
			exit(1);
		}
		
		argv[0] = strtok (arr,delimit);
		
		for ( i= 0 ;(argv[i] != NULL); i++ ){
			argv[i+1] =  strtok (NULL,delimit);
		}
		
		pid = vfork();
		
		if (pid > 0 ) {		//parent process
			
			sleep(1);

		} else if ( pid == 0 ) {		//child process
			
			execvp(argv[0], argv);

			exit(0);
		
		} else {		//vfork validation
			
			printf("fork failed.......!");
		
		}
	}
	return 0;
}

#endif

