#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>                                                              
#include <sys/stat.h>                                                           
#include <sys/mman.h>                                                           
#include <semaphore.h>                                                          

#define LEN 4096

int main (void)                                                                 
{                                                                               
    char *pathname = "/sh_memory";
	int shm_desc; 
	sem_t *sem_desc;                                                              
    char *mmap_addr = NULL;                                                     
    char catch[LEN] = {'\0'};                                                   
    char buf[LEN] = {'\0'};                                                   
                                                                                
    if (-1 == (shm_desc = shm_open(pathname, O_RDONLY, 0666))) {           
        perror ("Openning of shm_object failed\n");                        
		exit(1);
    }                                                                           

    if (SEM_FAILED == (sem_desc = sem_open(pathname, O_CREAT))) {                  
        perror("Opening the semaphore failed\n");                          
		exit(1);
    }                                                                           

/*    if (-1 == sem_wait(sem_desc)) {                                            
        perror("Locking failed\n");                                        
		exit(1);
    }                                                                                                                         
*/
    
//	sleep(10);
	if (-1 == sem_post(sem_desc)) {                                            
        perror("Unlocking failed\n");                                      
		exit(1);
    }                                                                           
    
	if ((void *)-1 == (mmap_addr = mmap (NULL, LEN, PROT_READ, MAP_SHARED, shm_desc, 0))) {
        perror ("Mapping on to virtual address failed\n");                 
		exit(1);
    }                                                                           

    if (NULL == memcpy(catch, mmap_addr, LEN)) {                                
        perror("Memcopying failed to catch\n");                            
		exit(1);
    }                                                                           
                                                                                
    if (-1 == write(1, catch, LEN)) {                                           
        perror("Writing to stdin failed\n");                               
		exit(1);
    }                                            
    
	if (-1 == sem_wait(sem_desc)) {                                            
        perror("Locking failed\n");                                        
		exit(1);
    }                                                                                                                         

    
/*	if (-1 == sem_post(sem_desc)) {                                            
        perror("Unlocking failed\n");                                      
		exit(1);
    }                                                                           
*/                                                                             
    
	if (-1 == munmap (mmap_addr, LEN)) {
		perror("Unmapping of memory failed\n");
		exit(1);
	}  
	
	close (shm_desc);
	if (-1 == shm_unlink (pathname)) {
		perror("deleting the shared memory object\n");                     
		exit(1);
    }                                                                           
                                                                                
    return 0;                                                                   
	
}
