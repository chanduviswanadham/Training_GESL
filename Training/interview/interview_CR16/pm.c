#include <stdio.h>
#include <sys/types.h>
int main( void )
{
//	printf("parent pid:%d\n", gettid());
	printf("working for pid:%d\n", getpid());
	printf("parent parent pid:%d\n", getppid());
	getchar();
	return 0;
}
