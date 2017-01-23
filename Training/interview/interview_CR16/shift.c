#include <stdio.h>

#if 1
int main( void )
{
	signed int num = 31;

	num = (~num + 1);

	num = -(num >> 2);

	printf("%d", num);

	return 0;
}
#endif
