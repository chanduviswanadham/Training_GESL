#include <stdio.h>
#if 0
void fun(void);
int main(void)
{
	printf("hello\n");
	fun();
	return 0;
}
void fun(void)
{
	
	printf("hello\n");
}
#endif
//In C language we cannot defined the function with in one function because
//it is not blocked structure language in blocked structed language it is possible
#if 1
int main()
{
	int num1 = 10;
	int num2 = 20;
	int sum(int, int);
	sum(num1, num2);
	return 0;
}

int sum(int num1, int num2) {
	int sum = num1 + num2;
	printf("sum is:%d", sum);
	return 0;
}
#endif
