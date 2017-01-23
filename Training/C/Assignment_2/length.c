#include<stdio.h>

int strleng( char * str )
{
	int count = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		count++;
	}

	return count;
}

