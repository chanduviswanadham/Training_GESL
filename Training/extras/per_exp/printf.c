#include <stdio.h>
#include <stdlib.h>
#if 0
int main()
{
	printf("%d");
	return 0;
}
#endif

#if 0

int main()
{
	printf("\\");
	printf("%\\");
	return 0;
}

#endif

#if 1

int main()
{
	int *a = 0x0805b000;
	printf(a);
//	print(a * a);
	return 0;
}
#endif
