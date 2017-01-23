#include "headers.h"

int strcasecmpr(char *str1, char * str2)
{
	int i;
	int len;
	int len1;

	
	len = strleng( str1 );
	len1 = strleng( str2 );

	if( len == len1) {
		for( i = 0; i < len; i++) {
			if((str1[i]+DIFF == str2[i]) | (str1[i]-DIFF == str2[i])) {
				continue;
			}
			if(str1[i] > str2[i]) {
				return 1;
			}
			if(str1[i] < str2[i]) {
				return -1;
			}
		}
		return 0;
	}

	if( len > len1 ) {
		return 1;
	}else {
		return -1;
	}
}
