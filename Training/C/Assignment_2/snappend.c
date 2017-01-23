#include<stdio.h>

int strleng( char * );
                                  
char *snappend (char *str1, char *str2, int n)
{
	int i;
	int j;
	//int len;
	int len1;

    //len = strleng(str1);                                                        
    len1 = strleng(str2);
	
	for( i = (len1-1), j = 0; j < n ; i++, j++) {
		str2[i] = str1[j];
	}
	
	str2[i] = '\0';

	return str2;
}
