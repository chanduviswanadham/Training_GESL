#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

struct data {
	int flag;
	int stored_data;
};

int main( void )
{
	int fd;
	char buf[ 100 ] = {'\0'};
	char *pathname = "/sh_memory";
	struct data *ptr = NULL;

	if( -1 == (fd = shm_open( pathname, O_RDWR, 0666 ) ) ) {
		printf("shm_open failed\n");
		exit(1);
	}

/*	if( -1 == read( fd, buf , 100 ) ) {	
		perror("read failed");
		exit(1);
	}
*/
	if ( MAP_FAILED == (ptr = (struct data*) mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0))) {
		perror("mmap failed..........!\n");
		exit(1);
	}

		
	while ( ptr -> flag == 1) {
			
			printf("sub process 2 \t stored data is :%d", ptr -> stored_data);
	}

	if( -1 == munmap( NULL, 100 ) ) {
		perror("munmap failed");
		exit(1);
	}

	if( -1 == close( fd ) ) {
		perror("close failed");
		exit(1);
	}

	if( -1 == shm_unlink( pathname ) ) {
		printf("shm_unlink failedi\n");
		exit(1);
	}

	return 0;
} 
