#include <stdio.h>

enum { a = 10, b,c,d,e = 10,f,g};

int main()
{
	printf("%d\t%d\t%d", d,e,f);
	return 0;
}
