#include<stdio.h>

#if 0

int main( void )
{
	printf(1+"%d",4);
}

#endif

#if 0

int main()
{
	int num = 5;
	int add = 10;

	num = num + add;

	num += add;

	return 0;
}
#endif

#if 0
int i = 1;

#define F printf("%d\n", i++);
#define G F F F F F F F F F F 
#define H G G G G G G G G G G

int main( void )
{
	H;
	return 0;
}
#endif

#if 1
int main( void )
{
	while(1)
	;
	return 0;
}

#endif
