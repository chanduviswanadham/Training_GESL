#include "headers.h"

char *insertchar(char *str, char ch, int pos)
{

	int len;
	int i;

	len = strleng(str);

	for(i = len + 1; i > pos; i--) {

		str[i] = str[i - 1];

	}

	str[pos] = ch;

	return str;

}


