#include <stdio.h> 
#include <stdlib.h>

#if 0
#define int float
void main()
{
	double a = 100.1234567891011;
	printf("%.10lf\n",a);
}
#endif

#if 0
#define MAX 100
#define MAX 200
#define MAX 300

int main()
{
	printf("%d", MAX);
	return 0;
}
#endif

#if 0
int main()
{
	char s[100]; /*	char str[sizeof(int)];*/ char str[sizeof(s)]; printf("%d\t%d", sizeof(s), sizeof(str));
	return 0;
}
#endif

#if 0
#define MAX 10

int main()
{
//	int a,b;
	printf("value 1:%d\n", MAX++);
	printf("valle 2:%d\n", MAX--);
	return 0;
}

#endif

#if 0

#define MAX(a) #a

int main()
{
	printf("%s", MAX(chandu viswanadham));
	return 0;
}

#endif

#if 0
#define MAX #chandu viswanadham	//if macro passing memeber is there then only it replaces the tokenizer as well as stringizer

int main()
{
	printf("%s", MAX);
	return 0;
}
#endif

#if 0
#define MAX 10
#define MAX 10

int main()
{	
	printf("%d", MAX);
	return 0;
}
#endif
