#include <stdio.h>
#include <stdlib.h>
#include <mathops.h>

int main()
{
	int a;
	int b;
	a = 20;
	b = 10;
	
	printf("addition value is:%d\n", sum(a, b));
	printf("diffrence value is:%d\n", diff(a, b));
	printf("production value is:%d\n", prod(a, b));
	printf("division value is:%d\n", divi(a, b));
	
	return 0;
}
