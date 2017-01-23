#include <stdio.h>                                                               
#include "errors.h"                                                              
#if 0
void *thread(void *arg)
{
    int seconds;
	int status;                                                                
    char line[128];                                                             
    char message[64];     
	pid_t pid;

 	while(1) {                                                                  
                                                     
        printf("Alarm > ");                                                     
    	if(fgets (line, sizeof(line), stdin) == NULL)                               
        	exit(0);                                                                
    	if(strlen(line) <= 1)                                                       
        	continue;                                                               
    
    	if(sscanf(line, "%d %64[^\n]", &seconds, message) < 2) {                    
        	fprintf(stderr, "Bad command\n");                                       
    	}	
	                                                                          
		if((pid = fork()) > 0) {
/*			if((status = wait(&status)) == -1) {
				printf("Error\n");
				exit(0);
			} 		*/
		if((status = waitpid(pid, &status, WNOHANG)) == -1) {
			printf("error\n");
			exit(0);
		}
		
		} else if(pid == 0) {                                                                   
        	sleep(seconds);                                                         
        	printf("(%d) %s\n", seconds, message);
			exit(0);                                  
        } else {
			printf("fork() error\n"); 
		}                                                                     
    }

}                                                                           
int main(void)                                                
{                                                                               
	pthread_t tid;                                                      
                                                                                
    if(pthread_create(&tid, NULL, &thread, NULL)) {
		printf("pthread_create() failed\n");
		exit(0);
	} 
	pthread_exit(NULL);
}
#endif

#if 1
int main(void)                                                    
{                                                                               
    int seconds;                                                                
                                                                     
    char line[128];                                                             
    char message[64];                                                           
    pid_t pid;                                                                  
                                                                                
    while(1) {                                                                  
         
		do {
			pid = waitpid (-1, NULL, WNOHANG);
			if (pid == -1)	
				break;
		} while (pid != 0);

        printf("Alarm > ");                                                     
        if(fgets (line, sizeof(line), stdin) == NULL)                               
            exit(0);                                                                
        if(strlen(line) <= 1)                                          
            continue;                                                               
                                                                                
        if(sscanf(line, "%d %64[^\n]", &seconds, message) < 2) {                    
            fprintf(stderr, "Bad command\n");                                       
        }  
                                                                                
        if((pid = fork()) > 0) {                                                
                                                                               
         } else if(pid == 0) {                                                                   
            sleep(seconds);                                                         
            printf("(%d) %s\n", seconds, message);                              
            exit(0);                                                            
        } else {                                                                
            printf("fork() error\n");                                           
        }                                                                       
    }

} 
#endif
