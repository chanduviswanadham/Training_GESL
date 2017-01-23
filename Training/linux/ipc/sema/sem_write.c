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
	char buf[LEN] = {'\0'};
	char catch[LEN] = {'\0'};
	int shm_desc;
	sem_t *sem_desc; 
	char *mmap_addr = NULL;

    if (-1 == (shm_desc = shm_open(pathname, O_RDWR | O_CREAT, 0666))) {   
        perror ("Openning of shm_object failed\n");
	}                             
                                                                                
    if (-1 == ftruncate(shm_desc, LEN)) {                                       
        perror("Allocating size of shared object file failed\n");          
		exit(1);
    }                                                                           
	
	if (SEM_FAILED == (sem_desc = sem_open(pathname, O_CREAT, 0666, 1u))) {
		perror("Opening the semaphore failed\n");
		exit(1);
	}
	
    if ((void *)-1 == (mmap_addr = mmap (NULL, LEN, PROT_READ | PROT_WRITE, MAP_SHARED, shm_desc, 0))) {
        perror ("Mapping on to virtual address failed\n");                 
		exit(1);
    }                                                                           

	if (-1 == sem_wait(sem_desc)) {
		perror("Locking failed\n");
		exit(1);
	}
    
    if (NULL == fgets(buf, LEN, stdin)) {                                       
        perror ("loading of input to buffer failed\n");                    
		exit(1);
    }                                                                           
                                                                                
    if (NULL == memcpy(mmap_addr, buf, LEN)) {                                   
        perror("Memcopy failed\n");                                        
		exit(1);
    } 
	
	getchar();
	
	if (-1 == sem_post(sem_desc)) {
		perror("Unlocking failed\n");
		exit(1);
	}                                                                               


/*    if (-1 == munmap (mmap_addr, LEN)) {                                         
        perror("Unmapping of memory failed\n");                            
		exit(1);
    }                                                                           
*/
 	if (-1 == sem_close(sem_desc)) {
		perror("closing\n");
		exit(1);
	}

                                                                            
    close (shm_desc);                                                           
	
	return 0;
}

