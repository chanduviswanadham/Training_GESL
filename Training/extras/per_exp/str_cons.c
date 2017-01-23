#include <stdio.h>

char *str = "chandu";
char *str1 = "chandu";

const int a = 25;
const int b = 25;

int main()
{
	
	char *str2 = "chandu";
	char *str3 = "chandu";
//	char str2[10] = {"chandu"};
//	char str3[10] = {"chandu"} ;

/*	if ( &str == &str1 ) {
		printf("equal address for string constants in global area\n");
	} else {
		printf("separate address for string constants in global area\n");
	}
*/	
	printf("address of str1:%p\tstr2:%p\tstr3:%p\tstr4:%p\t\n", str, str1, str2, str3);
	printf("a=%p\tb=%p", a, b);
	return 0;
}
