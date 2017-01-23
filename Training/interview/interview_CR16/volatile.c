#include <stdio.h>
#if 0
int main()
{
	volatile int i = 20;

	int j = 20;

	printf("%d\t%d\t%d\n", i++, ++i, --i);
	printf("%d\t%d\t%d\n", j++, ++j, --j);

	return 0;
}
#endif

#if 1

int main()
{
	volatile int a = 5;
	int b;
	while (1) {
		b = a;
		printf("%d\n", b);
	}
	return 0;
}

#endif
