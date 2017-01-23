#include <stdio.h>
#define OFFSET 32

char my_tolower(char c)
{
	if ( c >= 'A' && c <= 'Z')
		c = c + OFFSET;
	return c;
}

