#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void myprintf(int, int);
int main()
{
	int m;
	printf("enter the decimal value:");
	scanf("%d", &m);
	myprintf(1, m);
	myprintf(2, m);
	return 0;
}

void myprintf(int form, int n)
{
	int i = 0;

	char *buf = NULL;
	buf = (char *)malloc(sizeof (char) * 3);
	if(form == 1){
		while(n){
			buf[i] = (char)n % 16;
			buf[i] += '0'; 
			n = n / 16;
			i++;
		}
		buf[i] = '\0';
//		buf = strrev(buf);
		write(1, buf, sizeof(buf));
	}
	if(form ==2){
		while(n){
			buf[i] = (char)n % 10;
			buf[i] += '0'; 
			n = n / 10;
		}
//		buf = strrev(buf);
		write(1, buf, sizeof(buf));
	}	
}
