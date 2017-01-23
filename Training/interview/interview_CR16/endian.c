#include <stdio.h>

int main()
{
	int a = 1;

	printf("%d", *(char *)&a);

	return 0;
}
