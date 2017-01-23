#include <stdio.h>
#include <unistd.h>
#if 0
int main()
{	
	fork();
	fork();
	fork();
	printf("hello\n");
	return 0;
}
#endif

#if 1
int main()
{	
	vfork();
	vfork();
	vfork();
	printf("hello\n");
	return 0;
}

#endif
