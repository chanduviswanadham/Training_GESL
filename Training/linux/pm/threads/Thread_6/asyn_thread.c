#include <stdio.h>                                                             
#include "errors.h"            
#include <pthread.h>
#include <time.h>

void insert_end( char * );
void delete_beginning( void );
void delete_position( int  );

struct node {
	int sec;
	int lost_sec; //due to addition of abolute time 'sec' won't contain what user inputs
	char info[64];
	struct node *link;
};

typedef struct my_struct_tag {
    pthread_mutex_t     mutex;  /* Protects access to value */
	pthread_cond_t		cond1; 	
	pthread_cond_t		cond2; //cond2 for insertion at the beginning than the current running node time 
    struct node  *      head;  /* Access protected by mutex/
								* since head is being accessed by both TGL and service thread /
								* we will make it mutually exclusive by declaring a pointer instance of struct node "head" here*/
} my_struct_t;

my_struct_t data = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER, NULL}; // mutex attribute = NULL (default attributes) 

struct node *p, *temp;
int count ;
int pos ;
int n ;


                                                  
                             
void *alrm(void *line)
{
/*
*  struct timespec {
*         long       tv_sec;
*         long       tv_nsec;
*  };
*/
	struct timespec *abstract_time = NULL;
	int status;


	while ( 1 ) {
   	
		 status = pthread_mutex_lock(&(data.mutex)); // lock the resource (queue here ) as service thread untill access
        	if (0 != status) {
            	err_abort(status ,"lock filed\n");
        }
		
		if (data.head == NULL) {                     // if no elements in queue wait for signal of addition of element
            pthread_cond_wait( &(data.cond1), &(data.mutex));
        }
	
		/* time()  returns  the  time  as  the  number of seconds since the Epoch,/
   		 *1970-01-01 00:00:00 +0000 (UTC)/
   		 *THIS IS DONE BECAUSE INPUT IS ACCEPTED ASYNCHRONOUSLY BUT SERVICING REQUEST/
   		 *WAS STILL SYNCHRONOUS , BY SUSTRACTING THE INPUT TIME FROM 'TIME' WE MAKE IT SYNCHRONOUS */


		if ( NULL == (abstract_time = (struct timespec*) malloc (sizeof ( struct timespec )))) {
            perror("malloc failed\n");
            exit(0);
        }

		abstract_time -> tv_sec = ( data.head -> sec ); // reffer to the structure struct timespec , concerned about sec
        abstract_time -> tv_nsec = 0; // not concerned about nano sec

		status = pthread_cond_timedwait( &(data.cond2), &(data.mutex), abstract_time); //if signal 'cond2 ' that there is node inserted before currently processing node 
	        
		if (status == ETIMEDOUT) {
            	printf("(%d) %s \n", data.head -> lost_sec, data.head -> info);
            	delete_beginning();
        }

		status = pthread_mutex_unlock(&(data.mutex)); //release the lock 
 
       if (0 != status) {
            err_abort(status ,"unlock filed\n");
        }

        free(abstract_time);
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

		status = pthread_mutex_lock( &data.mutex ); //TGL locks the resources( linked list queue here ) which won't be accessed by service thread
		if ( 0 != status) {
                err_abort(status ,"lock filed\n");
            }

		insert_end( line );

 		status = pthread_mutex_unlock( &data.mutex ); //After its use it unlocks the resource (linked list queue here)
 
 		if (0 != status) {
                err_abort(status ,"unlock filed\n");
            }

	}

	return 0;	
}

	 



void insert_end( char * buffer) // TGL insert at the end of queue and Service thread reads from beginning 
{

	struct node *prev = NULL;
	time_t instance;
    int seconds;
    char message[64];

	
	if (NULL == (temp = ((struct node *) malloc ( sizeof(struct node ))))) {
		perror("malloc failed\n");
	}

	 if(sscanf(buffer, "%d %64[^\n]", &seconds, message) < 2) {
          fprintf(stderr, "Bad command\n");
    }

	temp -> lost_sec = seconds; // to retain user input sec value
	temp -> sec = seconds + time( &instance );
	strcpy(temp -> info, message);
	
	temp -> link = NULL;

   if (NULL == data.head){
        data.head = temp;
		temp -> link = NULL;
		pthread_cond_signal(&(data.cond1)); // if input send signal ' cond1 'to service thread

    } else {

		p = data.head;// make pointer p point to the initial node

		while (( p != NULL) && (p -> sec ) < ( temp -> sec )) {
			
             prev = p ; // store node pointed by p ( head node ) as previous node			
			 p = p -> link;

		}

		if ( p == NULL ) {  // if first node 
                prev -> link = temp;
                temp -> link = NULL;
      
	        } else if (prev == NULL) { // add the contents before first node and send a signal 
                temp -> link = data.head;
                data.head = temp;
                pthread_cond_signal(&(data.cond2)); // if node inserted before the processing node send ' cond2 '  signal
      
		      } else {
                temp -> link = prev -> link;
                prev -> link = temp;
            }


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
