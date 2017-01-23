#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int my_strspn(const char *, const char *);

int main()
{
	char *sbuf = NULL;
	char *dbuf = NULL;
	int count;

	if(NULL == (sbuf = (char *) malloc(sizeof(char) * MAX))) {
		perror("malloc failed");
		exit(1);
	}
	if(NULL == (dbuf = (char *) malloc(sizeof(char) * MAX))) {
		perror("malloc failed");
		exit(1);
	}

	printf("enter the string:\n");
	if( NULL == (fgets(sbuf, 10, stdin))) {
		perror("fgets failed");
		exit(1);
	}
//	printf("sbuf:%s\n",sbuf);

	sbuf[strlen(sbuf) - 1] = '\0';
	__fpurge(stdin);

	printf("enter the accept string:\n");
	if( NULL == (fgets(dbuf, 10, stdin))) {
		perror("fgets failed");
		exit(1);
	}
//	printf("dbuf:%s",dbuf);
	dbuf[strlen(dbuf) - 1] = '\0';
	__fpurge(stdin);
	
	count = my_strspn(sbuf, dbuf);

	printf("count : %d\n", count);

	return 0;

}

int my_strspn(const char *str, const char *accept)
{
	int count  = 0;
	int i = 0;

	if(strlen(accept) != 0) {
		for(i = 0; i < strlen(accept); i++) {
			if (str[i] != accept[i]) {
				break;
			}
			count++;
		}
	} 

	return count;
}

	
	
