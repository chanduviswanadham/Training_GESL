#include <stdio.h>
#if 0
int main()
{
	int i = 10;
	i = (++i) + (++i) + (++i);
	printf("i value= %d\n", i);
	return 0;
}

#endif

#if 1

int main()
{
	int i = 10;
	printf("%d\t%d\t%d", ++i, i, i++);
	return 0;
}
#endif
