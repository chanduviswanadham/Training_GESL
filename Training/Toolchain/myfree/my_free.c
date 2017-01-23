#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p = NULL;
	int i = 0;
	p = (int *)malloc(5 * sizeof(int));
	
	for(i = 0; i < 5; i++){
		scanf("%d", (p+i));
	}
	printf("before the free:\n");	
	for(i = 0; i < 5; i++){
		printf("%d\n", p[i]);
	}
	free(p);
	printf("After the free:%p\n", p);	
	for(i = 0; i < 5; i++){
		printf("%d\n",p[i]);
	}
	p = NULL;
	printf("After dangling the free:%p\n", p);	
	return 0;
}

