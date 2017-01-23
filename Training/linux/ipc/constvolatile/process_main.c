#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

struct data {
	int flag;
	int stored_data;
};

int main( void )
{
	int fd;
	struct data *ptr = NULL;
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

	sleep(5);
	ptr -> flag = 5;
	ptr -> stored_data = 100;

/*	printf("process 1 get input:\n");
	getchar();
*/
	sleep(2);
	ptr -> flag = 1;
/*	sleep(2);
	printf("process 2 get input:\n");
	getchar();

	ptr -> flag = 10;
*/	
/*	if (NULL == (buf = (char *) malloc(sizeof(char) * 100))) {
		perror("malloc failed........!\n");
		exit(1);
	}

	if (NULL == fgets(buf, 100, stdin)) {
		perror("fgets failed....!\n");
		exit(1);
	}
	*(buf + ((strlen(buf) - 1))) = '\0';
	printf("entered buffer:%s and length:%d", buf, strlen(buf));
	printf("entered buffer:%s and length:%d", buf, strlen(buf));
	if( -1 ==  write( fd, buf, strlen(buf)) ) {	
		perror("write failed");
		exit(1);
	}

	strcpy(ptr, buf);
*/
	if( -1 ==  close( fd ) ) {
		perror("close failed");
		exit(1);
	}

	return 0;
} 
