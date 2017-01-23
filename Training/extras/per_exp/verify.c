#include <stdio.h>

int main()
{
	extern a;
	extern b;
	extern *heap;
	printf("global value after exec in child:%d\t%p\n", a, &a);            
	printf("stack value after exec in child:%d\t%p\n", b, &b);             
	printf("heap value after exec in child:%d\t%p\n", *heap, &heap);
	return 0;
}
