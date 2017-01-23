#include <stdio.h>
#if 0
int main()
{
	func();
	func();

	return 0;
}

static int func()
{
	printf("in func\n");
	return 0;
}
#endif

#if 1
void func();

int a = 10;
int *p = NULL;
int *q = NULL;
int main()
{
	printf("a = %d\n", a);

	func();
	printf("p = %d\n", *p);
	printf("q = %d", *q);
}

void func()
{
	static int fun = 10;
	int fun1 = 20;
	p = &fun;
	q = &fun1;
	printf("fun=%d\n", fun);
	printf("fun1=%d\n", fun1);
	return;
}
#endif
