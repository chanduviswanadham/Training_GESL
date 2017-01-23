#include<stdio.h>

int strleng( char * );
                                  
char *sappend (char *str1, char *str2)
{
	int i;
	int j;
	int len;
	int len1;

    len = strleng(str1);                                                        
    len1 = strleng(str2);
	
	for( i = (len-1), j = 0; i < ((len + len1)-1); i++, j++) {
		str1[i] = str2[j];
	}
	
	str1[i] = '\0';

	return str1;
}
