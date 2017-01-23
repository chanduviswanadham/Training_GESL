#include "headers.h"

int myatoi(char * n)
{
	int res = 0;
	int i;
	int len;

	len = strleng( n ); 

	for( i = 0; i < (len-1); i++) {
		res = res * 10 + (n[i] - '0');
	}

	return res;
}	
