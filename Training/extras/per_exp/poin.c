#include <stdio.h>
#include <stdlib.h>
#if 0
int main()
{
	char ptr[10] = {"chandu"};
	char *p;
	
	p = (char *)malloc(10);
	p = ptr;
	
	free(p);
	return 0;
}

#endif

#if 0

int main()
{
	int p = 10;
	int j;
//	printf("%d\t%d\t%d", p++, ++p, p);
	j = p++ + ++p;
	printf("%d", j);
	return 0;

}

#endif

#if 0

int main()
{
//	char *ptr = (char *)malloc(10);
	char *ptr = 5;
	ptr = "chandu";
	printf("%s\n", ptr);
	return 0;
}
#endif

#if 1
int main()
{
	int x = 1;

	printf("%d",*(char *)&x);
	return 0;
}

#endif
