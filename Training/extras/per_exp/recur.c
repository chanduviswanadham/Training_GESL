#include <stdio.h>

int recursion(int);

int main()
{
	recursion(10);
	return 0;
}

int recursion(int n)
{
	if (n == 0) {
		return 0;
	} else {
		printf("%d", n);
		recursion(n - 1);
	}
	return 0;
}
