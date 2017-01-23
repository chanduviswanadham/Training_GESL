#include <stdio.h>
#include <stdlib.h>
//no memory leaks 
int main()
{
	int *p = NULL;
	p = (int*)malloc(10);
	*p = 10;
	free(p);
	return 0;
}
