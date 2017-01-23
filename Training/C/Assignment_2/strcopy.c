#include<stdio.h>

int i = 0;

void strcopy( char * sbuf, char * dbuff)
{

	for( i=0 ; sbuf[i] != '\0'; i++) {
		dbuff[i] = sbuf[i];
	}
	
	dbuff[i] = '\0';

	printf("The destination string now contains: %s\n", dbuff);
}

