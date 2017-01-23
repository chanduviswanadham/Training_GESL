#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>


int main( void )
{
	int fd;
	void *ptr = NULL;
	char *pathname = "/sh_memory";
//	char *buf = NULL;

	if( -1 == (fd = shm_open( pathname, O_CREAT | O_RDWR, 0666 ) ) ) {
		perror("shm_open failed.......!\n");
		exit(1);
	}

	if( -1 == ( ftruncate( fd, 100 ) ) ) {
		perror("ftrucate failed");
		exit(1);
	}

	if( MAP_FAILED == ( ptr = mmap( NULL, 100, PROT_READ  | PROT_WRITE, MAP_SHARED, fd, 0 ) ) ) {
		perror("mmap failed..............!\n");
		exit(1);
	}
	
	if (NULL == (buf = (char *) malloc(sizeof(char) * 100))) {
		perror("malloc failed........!\n");
		exit(1);
	}

	if (NULL == fgets(buf, 100, stdin)) {
		perror("fgets failed....!\n");
		exit(1);
	}
	*(buf + ((strlen(buf) - 1))) = '\0';
	printf("entered buffer:%s and length:%d", buf, strlen(buf));
/*	printf("entered buffer:%s and length:%d", buf, strlen(buf));
	if( -1 ==  write( fd, buf, strlen(buf)) ) {	
		perror("write failed");
		exit(1);
	}
*/
	strcpy(ptr, buf);

	if( -1 ==  close( fd ) ) {
		perror("close failed");
		exit(1);
	}

	return 0;
} 
