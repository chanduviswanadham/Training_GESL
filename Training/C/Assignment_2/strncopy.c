#include<stdio.h>

void strncopy( char *sbuf, char *dbuff, int n)
{
	int i;

	for( i = 0; i < n; i++)
	{
		dbuff[i] = sbuf[i];
	}
	
	dbuff[n] = '\0';

	printf("the destination string is: %s\n", dbuff);
}
