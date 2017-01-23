#include <stdio.h>

int main()
{
	int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int (*ptr)[3][3];
	ptr = &a;
	printf("&a = %p\n", &a);
	printf("a = %p\n", a);
	printf("*a = %p\n", *a);
	printf("&a = %p\n", &a + 1);
	printf("a = %p\n", a + 1);
	printf("*a = %p\n", *a + 1);
	printf("value of a[2][2] = 0x%08x\n", *(a+1) + 1);
	printf("value of a[3][3] = %d\n", *(*(a+2) + 2));
	return 0;
}
