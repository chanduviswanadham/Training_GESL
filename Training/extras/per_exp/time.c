#include <stdio.h>
#include <stdlib.h>
#include <time.h>


time_t tim;

int main()
{
	printf("time from macro is:%s\n", __TIME__);
	printf("time from time function:%ld\n", (long)time(&tim));
	return 0;
}
