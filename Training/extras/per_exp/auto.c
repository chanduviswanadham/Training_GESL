#include <stdio.h>

int fun()
{
	printf("fake");
	return 0;
}

int main()
{
	auto int fun();
	fun();
	int fun() {
		printf("fun");
		return 0;
	}
	fun();
	return 0;
}
