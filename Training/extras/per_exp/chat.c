#include <stdio.h>
#include <stdlib.h>
int main()
{
	char buf[100];
	while (1) {
		printf("chat application:\n");

		fgets(buf, 100, stdin);

		printf("from chat:%s\n", buf);
	}
	return 0;
}

		
