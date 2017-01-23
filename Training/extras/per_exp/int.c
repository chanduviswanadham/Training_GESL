#include <stdio.h>

int main()
{
	int a;
	printf("enter the number:\n");
	scanf("%c", &a);
	if ( ((char)a >= 48)&& ((char)a <= 57)) {
		printf("numeric\n");
	} else if ( ((char)a >= 65)&& ((char)a <= 90)) {
		printf("char capital\n");
	} else if ( ((char)a >= 97)&& ((char)a <= 122)) {
		printf("char small\n");
	}
	return 0;
}
