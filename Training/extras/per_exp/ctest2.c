#include <stdio.h>
#if 0
int main()
{
	int a= 5, b = 6;
	printf("%d\n", a = b);
	printf("%d\n", a == b);
	printf("%d\t%d\n", a, b);
	return 0;
}

#endif

#if 0
int func();
int main()
{
	int x = 10;
	x = func();
	printf("%d", x);
	return 0;
}

int func()
{
	printf("function\n");
}
#endif

#if 0

union test {
	int x;
	char arr[4];
	int y;
};

int main()
{
	union test t;
	t.x = 0;
	t.arr[0] = 'c';
	t.arr[1] = 'G';
	printf("%s", t.arr);
	return 0;
}
#endif

#if 1

struct test {
	int i : 1;
	int j : 2;
	int k : 3;
	int l : 4;
}s;

int main()
{
	s.i = 1;
	s.j = 3;
	s.k = 7;
	s.l = 10;
	printf("s.i = %d\t%d\t%d\t%d\t%d\n",s.i,s.j,s.k,s.l,sizeof(s));
	return 0;
}
#endif
