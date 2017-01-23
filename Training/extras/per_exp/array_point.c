#include <stdio.h>
#if 0
int main(void)
{
    char *v[ ] = {"abc", "efg", "jkl"};
	char **p;
	*p = v;
	printf("%c\n", *++p[0]);
	printf("%c\n", (*++p)[0]);
	return 0;
	
}

#endif

#if 1

int main()
{
	int a = 15;
	int *p = &a;
	int **pt = &p;
	return 0;
}
#endif
