#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#if 0
int main()
{
	FILE *fp;
	if ( NULL == (fp = fopen("chandu.txt", "r"))) {
		perror("fail open failed.......!");
		exit(1);
	}
	return 0;
} 
#endif

#if 0
int main()
{
	int fp;
	if ( -1 == (fp = open("chandu.txt", O_RDONLY))) {
		perror("fail open failed............!\n");
		exit(1);
	} else {
		printf("fail opend successfully.....!\n");
	}
	return 0;
}
#endif
#if 1

int main()
{
FILE * fp;
if (NULL == (fp = fopen ("file.txt", "w+"))) {
	printf(“files is not opened....!”);
	exit(1);
}

fclose(fp);
return(0);
}

#endif
