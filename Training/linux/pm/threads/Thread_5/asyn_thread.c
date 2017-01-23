#include <stdio.h>                                                               
#include "errors.h"                                                              
#include "errors.h"                                                             
                             
char line[128];                                                             
int seconds;                                                                
char message[64];     
void *alrm(void *arg)
{
	if(sscanf(line, "%d %64[^\n]", &seconds, message) < 2) {                    
        fprintf(stderr, "Bad command\n");                                       
    }	
    sleep(seconds);                                                         
    printf("(%d) %s\n", seconds, message); 
		                                                                    
}                                                                           

int main(void)                                                
{                                                                               
	pthread_t th_id;                                                      
	int status;
 	while(1) {                                                                  
        printf("Alarm > ");                                                     
    	if(fgets (line, sizeof(line), stdin) == NULL)                               
        	exit(0);                                                                
    	if(strlen(line) <= 1)                                                       
        	continue;                                                               
    	if(status == pthread_create(&th_id, NULL, &alrm, NULL)) {
			err_abort(status,"failed pthread craete()");
			pthread_exit(NULL);
		}	
	}
}

