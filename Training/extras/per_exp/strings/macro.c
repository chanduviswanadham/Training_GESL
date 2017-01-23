#include <stdio.h>

#define MACRO(a,b) (a * b)
//		(a * b) (a * b)

int main()
{
	printf("%d", MACRO(2, 4));
	return 0;
}
