#include<stdio.h>

char * chr_add_instr (char *buf, char c)
{
	char *temp;
	int i;

	for( i = 0; buf[i] != '\0'; i++) {
		if( buf[i] == c) {
			temp = &buf[i];
			return temp;
		}
	}

	return 0;
}
