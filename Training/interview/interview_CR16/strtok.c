#include <stdio.h>
#include <string.h>

char *mystrtok(char *, char *);

int main( void )
{
	char *string = malloc(sizeof(char)*128);
	char *del = "?";
	char *buf = NULL;

	fgets(string, 128, stdin);
	*(string + strlen(string) - 1) = '\0';

	printf("String(main) = %s\n", string);

	buf = mystrtok(string, del);

	while(buf != NULL) {
		printf("%s\n", buf);
		buf = mystrtok(NULL, del);
	}

	return 0;
}

char *mystrtok(char *str, char *delim)
{
	static int pos;
	int k = pos, i = 0;
	static char *temp;

	if(str != NULL)
		temp = str;

	printf("temp = %s\n", temp);
	while( (temp[pos] != '\0') ) {
		i = 0;
		while( delim[i] != '\0' ) {
			if( temp[pos] != delim[i] )
				i++;
			else if( temp[k] == delim[i] ) {
				k++;
				break;
			} else {
				temp[pos] = '\0';
				pos++;
				return &temp[k];
			}
		}
		pos++;
	}

	temp[pos] = '\0';

	if(temp[k] == '\0') {
		return NULL;
	} else {
		return &temp[k];
	}
}
