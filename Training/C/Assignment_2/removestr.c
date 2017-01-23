#include "headers.h"

char *remsstr(char *str, char *sstr)
{

	int i = 0;
	int j = 0;
	int k;
	int pos = 0;


	while(str[i] != '\0') {

		if( sstr[j] == str[i] ) {

			i++;
			j++;

			if( sstr[j] == '\n') {

				pos = i + 1;

				for(k = (pos - strleng(sstr)); str[k] != '\0'; k++, pos++) {

					str[k] = str[pos-1];

				}

				str[k] = '\0';

				i = i - strleng(sstr);

				j = 0;

			}

		} else {

			i++;

			j = 0;

		}

	}

	return str;

}


