#include <stdio.h>

#if 1
int main()
{
	char a[] = "abcde";
	char *p;
	p = a;
	p++;
	p++;
	p[2] = 'z';
	printf("%s", p);
	return 0;
}
#endif
