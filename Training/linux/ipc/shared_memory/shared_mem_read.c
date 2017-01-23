#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>


int main( void )
{
	int fd;
	char buf[ 100 ] = {'\0'};
	char *pathname = "/sh_memory";
	char *ptr = NULL;

	if( -1 == (fd = shm_open( pathname, O_RDWR, 0666 ) ) ) {
		printf("shm_open failed\n");
		exit(1);
	}

/*	if( -1 == read( fd, buf , 100 ) ) {	
		perror("read failed");
		exit(1);
	}
*/
	if ( MAP_FAILED == (ptr = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0))) {
		perror("mmap failed..........!\n");
		exit(1);
	}

	printf("the received output is : %s\n", ptr);

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
