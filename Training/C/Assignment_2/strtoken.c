#include "headers.h"

char *strtoken( char *sbuf, char *dlim )
{
	int i;
	int j;
	int count = 0;
	int slen = strleng(sbuf);
	int dlen = strleng(dlim);

	//to check whether the string is tokenised
	for( i = 0; sbuf[i] != '\0'; i++ ) { 
		if( sbuf[i] == '\n' ) {
			count++;
		}
	}
	
	if( count > 1 ) {
		printf("the string is already tokenised\n");
		return sbuf;
	}

	//to tokenise
	for( j = 0; j < dlen; j++ )	{
		for( i = 0; i < slen; i++ ) {
			if( sbuf[i] == dlim[j] ) {
				sbuf[i] = '\n';
			}
		}
	}

	return sbuf;
}
