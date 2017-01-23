#include "headers.h"

void compress( char *str )
{
	int len;
	int i;
	int n;

	len = strleng(str);

	for( i = len; i >= 0; i-- ) {
		if(str[i] == str[i - 1] ) {
			for( n = i; n <= len; n++ ) {
				str[n] = str[n + 1];
			}
		}
	}

	printf("the string is now: %s", str);
} 
