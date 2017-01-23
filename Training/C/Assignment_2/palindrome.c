#include "headers.h"

int palindrome( char *sbuf )
{
	int i;
	int j;
	int len;
	
	len = strleng( sbuf );

	for(j = (len-2), i = 0; i <= j ; i++, j--) {
		if( sbuf[i] == sbuf[j]) {
			continue;
		}else {
			break;
		}
	}

	if( i > j ) {
		printf("It is a palindrome\n");
	}else {
		printf("Not a palindrome\n");
	}

	return 0;
}
