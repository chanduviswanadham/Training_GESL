#include <stdio.h>
#if 0
int main()
{
	int x = 0, y = 1, z = 0;
//	x = x && y || z;
//	printf("%d\n", x);
	printf("%d\n", x || !y && z);
	x = y = 1;
	z = x ++ - 1;
	printf("%d\n", x);
	printf("%d\n", z);
	z += -x ++ + ++y;
	printf("%d\n", x);
	printf("%d\n", z);
	z = x / ++x;
	printf("%d\n", z);
	return 0;
}
#endif
#if 0


int main ()
{
    char a  =  3;
	short  b =  4;
	printf ("%d\n", sizeof ((1==1) ? a : b));
	return 0;
}

#endif

#if 1

int main()
{	
	int a = 3;
	int b = 4;
	a = a++ + ++b;
	printf("a value is :%d", a);
	return 0;
}

#endif
