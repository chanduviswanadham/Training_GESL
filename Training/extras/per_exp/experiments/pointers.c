#include<stdio.h>

#if 0
int main()
{
	int *p;
	int n = 1;
	p = &n;
	printf("the value is:%p", p);
	printf("the value is:%p", &p);
	printf("the value is:%d", *p);
	return 0;
}

#endif

#if 0
int main()
{
	int* p;
	//int n = 10;
	p = 0xbfc0fef8;
	printf("the value is:%p\n", p);
	p = NULL;
	printf("the value is:%d\n", *p);
//	printf("the value is:%p\n", &n);
	return 0;
	  
}
#endif

#if 0
int main()
{
	//char buf[64] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	int n = 12345678;
	char *buf = NULL;

	buf = (char *) & n;
	printf("%d\n", buf[0]);		//due to little endian it is printing 78
	return 0;
}
#endif

#if 0
int main()
{

	int a[7]={1, 2, 3, 4, 5, 6, 7};
	printf("%p\n", a);
	printf("%p\n", &a);
	return 0;
}
#endif 

#if 0
int main()
{
	int *p;
	int n = 10;
	p = &n;
	printf("the value is:%d\n", *p);
	++*p;
	printf("the value is:%d\n", *p);
	return 0;
}
#endif

#if 0
typedef int (*INTARRAY) [10];
typedef int INTARR [10];
INTARRAY a;
INTARR b = {1, 2, 3, 4, 5};

int main()
{
	a = &b;
	printf("%d\n",sizeof(a));
	b[5]=6;
	printf("%p", *(a + 6));
	return 0;	
}
#endif

#if 0

char *str = "global edge";
int main()
{
	printf("%08p\n", str);	//global edge will be in RODATA so it will store only once when you will give the same data twice then you will represent the same previous data only
	printf("%08p\n", "global edge");
	printf("%s\n", "global edge");
	return 0;
}
#endif

#if 0

void func(char *s)
{
	printf("%s", s);
}

int main()
{
	func("chandu viswanadham");
	return 0;

}
#endif

#if 0

char *n;
int main()
{
	char *p = "chandu";
	char s[5] = "happy";
	p = &s[0];
	*p = 'p';
	p = p + 4;
	*p = 'u';
	printf("%s\n", s);
	p = n;
//	*p = n;	//segfault because it leads to dereference the 0 address.
	return 0;
}

#endif

#if 0

int b[][2];
int a[];
int main()
{
	b[0][1] = 4;
	printf("size of a is :%d\n", sizeof(a));	//invalid operation
	printf("b[0][1]=%d", b[0][1]);
	printf("size of b is :%d\n", sizeof(b));	//when the array is not fixed sizeof will through compiler error
	return 0;
}
#endif

#if 1

char str1[2][6] = { "hello world" };
char str2[2][20] = { "global edge" };
char str3[][10] = { "hyper active" };
char str4[][20] = { "idiosyncracy", "vagbond"};

int main()
{
	printf("%s\n", *(str1 + 0));
//	printf("%s", *(6 + str1));
	return 0;
}
#endif
