#include <stdio.h>
#include <string.h>

//conerting the ascii to interger

int myatoi(char *n)
{
	int res = 0;
	int i;
	int len;

	len = strlen(n); 

	for (i = 0; i < (len-1); i++) {	//logic to convert interger
		res = res * 10 + (n[i] - '0');
	}

	return res;

}	
