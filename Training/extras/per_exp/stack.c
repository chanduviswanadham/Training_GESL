#include <stdio.h>

int main()
{
	int a = 1;
	int b = 2;
	char c = 3;

//	printf("%p\t%p\t%p", &c, &a, &b);

	c = fun(a,b);
	printf("%d", c);
	return 0;
}

int fun(int a, int b){
	int c = a + b;
	return c;
}
