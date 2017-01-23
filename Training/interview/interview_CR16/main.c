#include <stdio.h>

int main(int argc)
{
	func(1, 2);
	return 0;
}

int func( void )
{
	printf("in func");
	return 0;
}
