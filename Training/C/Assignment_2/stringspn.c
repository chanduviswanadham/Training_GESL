#include "headers.h"

size_t stringspn( char *buf1, char *buf2)
{
	int i;
	int j;
	int count = 0;

	for( i = 0, j = 0; i < (strleng((char *)buf1) - 1) && (j < (strleng((char*)buf2) - 1));  ) {
		if( buf1[i] == buf2[j] ) {
			i++;
			j = 0;
			count++;
		}else {
			j++;
		}
	
	}

	return count;
} 
