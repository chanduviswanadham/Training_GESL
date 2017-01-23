#include <stdio.h>
#include <stdlib.h>
#if 0
int a = 4;
//int b;
static int c = a;
//static int d = b;
int main()
{
	int e = 4;
//	static int f = a;

	printf("c:%d\n", c);
//	printf("d:%d\n", d);
//	printf("f:%d\n", f);
	return 0;
}
#endif

int main()
{
	int a;
	int b;

	printf("a = %p\tb = %p\tc = %p", &a, &b, &a + 1);
	printf("pid:%d", getpid());
	getchar();
	return 0;
}

