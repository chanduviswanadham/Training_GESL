#include <stdio.h>
#include "global.h"
//int a = 15;
void global();

int main()
{
	printf("a value in global:%d\n", a);
	global();
	return 0;
}

