#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	if(NULL == (fp = fopen("list1.txt", "w"))) {	//opeing a file in write mode will cause to destory the previous data on the file
		perror("file opening failed\n");
		exit(1);
	}
	printf("%s", fp);
	fclose(fp);
}
