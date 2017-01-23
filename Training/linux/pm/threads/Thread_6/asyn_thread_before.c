#include <stdio.h>                                                             
#include "errors.h"            
#include <pthread.h>
#include <time.h>

void insert_end( char * );
void delete_beginning( void );
void delete_position( int pos );

struct node {
	int sec;
	int lost_sec; //due to addition of abolute time 'sec' won't contain what user inputs
	char info[64];
	struct node *link;
};

typedef struct my_struct_tag {
    pthread_mutex_t     mutex;  /* Protects access to value */
	pthread_cond_t		cond1;  //cond1 for insertion at the beginning than the current running node time 
	pthread_cond_t		cond2;	
    struct node  *      head;  /* Access protected by mutex/
								* since head is being accessed by both TGL and service thread /
								* we will make it mutually exclusive by declaring a pointer instance of struct node "head" here*/
} my_struct_t;

my_struct_t data = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER, NULL};

struct node *p, *temp;
int count ;
int pos ;
int n ;


                                                  
                             
void *alrm(void *line)
{
	time_t instance; 


	while ( 1 ) {
   	
		while (data.head == NULL) {
			sleep(1);
		}
	
		/* time()  returns  the  time  as  the  number of seconds since the Epoch,/
   		 *1970-01-01 00:00:00 +0000 (UTC/
   		 *THIS IS DONE BECAUSE INPUT IS ACCEPTED ASYNCHRONOUSLY BUT SERVICING REQUEST/
   		 *WAS STILL SYNCHRONOUS , BY SUSTRACTING THE INPUT TIME FROM 'TIME' WE MAKE IT SYNCHRONOUS */

		while (data.head != 	NULL) {
		 	sleep(  (data.head -> sec) - time(NULL)); 
//			sleep( head -> sec );  					
    		printf("(%d) %s\n",  data.head -> sec, data.head -> info); 
		
			pthread_mutex_lock(&data.mutex); //Service thread locks resources ( linked list queue here ) which won't be accessed by TGL
			delete_beginning();
			pthread_mutex_unlock(&data.mutex); //Service thread frees resources ( linked list queue here ) which can be now accessed by TGL
		}

	}
	pthread_exit(NULL);
		                                                                    
}                                                                           

int main( void )                                                
{                                                                    
	
	pthread_t th_id;                                                      
	char line[128];		
	int status;

	//only one service thread is to be spawn so it is out of while loop
	 if( 0 != pthread_create(&th_id, NULL, &alrm, NULL)) {
                err_abort(status,"failed pthread craete");
                pthread_exit(NULL);
    	}
 
	while (1) { // input is accepted any time user requests and is added into the buffer                                                           
        printf("Alarm > ");                                                     

    	if(fgets (line, sizeof(line), stdin) == NULL)                               
        	exit(0);                                                                

    	if(strlen (line) <= 1)                                                       
        	continue;                                                               
/*
		 if( 0 != pthread_create(&th_id, NULL, &alrm, line)) {
    	        err_abort(status,"failed pthread craete");
        	    pthread_exit(NULL);
	 	}

*/
		pthread_mutex_lock(&data.mutex); //TGL locks the resources( linked list queue here ) which won't be accessed by service thread
		insert_end( line );
 		pthread_mutex_unlock(&data.mutex); //After its use it unlocks the resource (linked list queue here)
	}

	return 0;	
}

	 



void insert_end( char * buffer) // TGL insert at the end of queue and Service thread reads from beginning 
{

//	char line[128];	
	time_t instance;
    int seconds;
    char message[64];
	int num;

	temp = ((struct node *) malloc ( sizeof(struct node )));

	 if(sscanf(buffer, "%d %64[^\n]", &seconds, message) < 2) {
          fprintf(stderr, "Bad command\n");
    }

	num = seconds;
	temp -> sec = seconds + time( NULL );
	strcpy(temp -> info, message);
	
	temp -> link = NULL;

   if (NULL == data.head){
        data.head = temp;

    } else {

		p = data.head;// make pointer p point to thei initial node before traversing

		while ( p->link != NULL ){
			p = p->link;
		}

//		temp -> link = p -> link;
	
		p -> link = temp;

	//	temp = NULL;

	//	free(temp);	
	}

	count++;//no of nodes

    return;
}

void delete_beginning( void ) // service thread reads first and then delete the node
{
	struct node *p = data.head;

	data.head = data.head -> link;

	count --;

	free( p );
}
