#include "headers.h"

char *reverse( char *sbuf )
{
	int i;
	int j;
	int len;
	char *temp = (char *) malloc ( sizeof(char) * MAX );
	
	len = strleng( sbuf );

	for(j = (len-2), i = 0; j >= 0 ; i++, j--) {
		 temp[i] = sbuf[j];
	}

	return temp;
}
