#include <stdio.h>
#include <stdlib.h>
#if 0
int main()
{
	int *ptr;
	ptr = (int *)malloc(sizeof(4 * 4));
	
	printf("the size of :%d", sizeof(ptr));
	*(ptr - 1) = 20;
	printf("the size of ptr after changing size:%d", sizeof(ptr));
	return 0;
}
#endif

#if 1

int main()
{
	int *ptr = NULL;

	while(1) {
		if(NULL == (ptr = malloc(540672))) {
			perror("malloc failed");
			exit(1);
		}
		printf("%d\n", *ptr);
	}

	return 0;
}
#endif


