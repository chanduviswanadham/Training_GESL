#include <stdio.h>

int rec(int, int);

int main()
{
	int m, n;
	printf("enter the values:");
	scanf("%d,%d", &m,&n);
	printf("the value is:%d",rec(m, n));
	return 0;
}

int rec(int m, int n)
{
	if ((m < 0) || (n < 0))	return 0;
	if (m == 0) return (n +1);
	if ((m > 0) && n == 0) return (rec(m -1, 1));
	if ((m > 0) && (n > 0)) return (rec(m -1,rec(m, n -1)));
}
