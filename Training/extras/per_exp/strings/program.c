#include <stdio.h>

#if 0

int main()
{
	char *ptr = "chandu";
	char *happy = "chandu";

	char str[] = "chandu";
	char str1[] = "chandu";


	printf("%p\t%p\n", ptr, happy);
	printf("%p\t%p\n", str, str1);


	if(ptr == happy) {
		printf("same");
	}
	return 0;
}

#endif

#if 0
#include <string.h>
int main()
{
	char str[11] = "globaledge";
	char str1[11];

	printf("%s\n", strcpy(str1, str));

	printf("%s\n", str1);

	printf("%d\n", sizeof(str1));

	return 0;

}
#endif

#if 0
int main()
{	
	printf("hello world");
	return 0;
}
#endif

#if 0
#include <stdlib.h>
#include <string.h>

char * my_strtok(char *ptr, const char *del);
int main()
{
	char str[] = "global edge is an embedded company";
	char *del = "! ?";
	char *buf = NULL;

	printf("%s\n", (char *)my_strtok(str, del));

	buf = (char *)malloc(10);

	while(NULL != (buf = (char *)my_strtok(NULL, del))) {
		printf("%s\n", buf);
	}

	printf("%s", str);

	return 0;
}

char * my_strtok(char *ptr, const char *del)
{
	static char buf[1024];
	char *ret = NULL;
	static int pos;
	static len = 0;
	int flag = 0;
	int j = 0;

	if(ptr != NULL) {
		strcpy(buf, ptr);
		printf("%s", buf);
		len = strlen(ptr);
		pos = 0;
		ret = buf;
	}

	while(buf[pos] != '\0' && flag == 0) {

		for(j = 0; del[j] != '\0'; j++) {
			if(del[j] == buf[pos]) {
				buf[pos] = '\0';
				flag = 1;
				break;
			}
		}
		pos++;
	}

	printf("%s", buf);
	ret = buf + pos;
	if(pos >= len) {
		ret = NULL;
	}
	return ret;
}





#endif

#if 0
int main()
{
	//	printf();		//error : too few arguments
	//	printf("%d\n",printf(NULL)); //NULL or 0 will fail the printf

	printf(1);		//segmentation fault 
	return 0;
}
#endif

#if 0

int main()
{
	char a[4] = {1,2,3,4};
	int b;
	int i;

	printf("%p\t%p\t%p\t\n", &a, &b, &i);
	printf("%p\t%p\t%p\t%p\n", &a[0], &a[1], &a[2], &a[3]);
	printf("%p\t%p\t%p\t%p\n", &a[0], &a[1], &a[2], &a[3]);

	//	for(i = 8; i < 12; i++) {
	printf("%x\n", *(int *)((char *)&b + 8));
	//	}
	return 0;
}
#endif

#if 0

int main()
{
	int a = 1234;

	char b[4];

	printf("%p\t%p\n", &a, &b);

	printf("%d", *(char *)&a);

	printf("%p\n", (char *)&b[0] - 4);

	return 0;
}
#endif

#if 0

#define SIZE sizeof(arr)/sizeof(arr[0])

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int i;
	unsigned int n = 5;
	//	for(i = -1; i <= n ; i++) {
	for(i = -1; i <= SIZE ; i--) {
		printf("GLOBAL EDGE");
	}

	return 0;
}

#endif

#if 0

int main()
#endif

#if 0

int main()
{
	double n = 5.6;

	printf("%d", sizeof(!n));
	printf("%d", sizeof(main);
			return 0;
			}
#endif

#if 0

#define SIZEOF(type) ((char *)(&type + 1) - (char *)&type)

			double fun();

			int main()
			{
			int a;
			printf("void :%d\n", SIZEOF(void));
			printf("void * :%d\n", SIZEOF(void *));
			printf("NULL:%d\n", SIZEOF(NULL));
			printf("main:%d\n", SIZEOF(main));
			//	printf("fun:%d\n", (char *)(&fun + 1) - (char *)&fun);
			//	printf("a:%d\n", (char *)(&a + 1) - (char *)&a);
			printf("main():%d\n", SIZEOF(main()));
			//	printf("fun():%d\n", sizeof(fun()));

			return 0;
			}

#endif

#if 0

int main()
{
	int a[5] = {1, 2, '\0', '\0', '\0'};
	int i;

	for(i = 0; i < 4; i++) {
		printf("%d\t", a[i]);
	}
	printf("%d", sizeof(a)/ sizeof(a[0]));
	return 0;
}

#endif

#if 0
int main()
{
	int a = -10;

	printf("%d\n", -(~a));		//macros for increment
	printf("%d\n", ~(-a));		//macros for decrement
	return 0;
}
#endif

#if 0

struct free {
	int a:4;
	int b:10;
};

int main()
{
	struct free inst;
	inst.b = 10;
	return 0;
}
#endif

#if 1
int main()
{
	signed char num = -31;

	num = (~num + 1);
	num = -(num >> 2);
	//	num = -(~num);
	//	num = (num  >> 2);

	printf("%d", num);

	return 0;
}


#endif

#if 0

int main( void )
{
	while(1) {

	}

	printf("hello world");
	return 0;
}
#endif

#if 0
int main()
{
	unsigned char *c;
	c = 'A';

	while (c >= 0)
		printf("%d\n", (*c)++);
}
#endif

#if 0

int main()
{
	int _start = 100;
	
	printf("%d", _start);

	return 0;
}
#endif
