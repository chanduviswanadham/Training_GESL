#include "headers.h"

int strrot(char *str, char *rstr)
{
	int i;
	int j;
	int k;
	int n = ( strleng( str ) - 1 );
	int len = n + 1;
	char last;
	int flag = 0;

	if( strleng( str ) == strleng( rstr ) ) { return 0; }
	else {
		while ( n != 0 ) {
			last = str[len - 1];

			for( i = len; i >= 0; i-- ) {
				str[i + 1] = str[i];
			}

			str[0] = last;
			str[len] = '\0';

			for( k = 0, j = 0; (( k < len) || ( j < (strleng( rstr ) - 1))) &&					flag == 1; k++, j++ ) {

				if( str[k] == rstr[j] )
					flag = 1;
			}
	
			if( flag == 1 ) { return 0; }
			else { n = n - 1; }
		}
	
		return -1;
	}
}

