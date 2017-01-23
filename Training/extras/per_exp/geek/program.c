#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#if 0

int main(void)
{
	char buff[10];
	memset(buff,0,sizeof(buff));

	gets(buff);

	printf("\n The buffer entered is [%s]\n",buff);

	return 0;
}
#endif

#if 0
void main(void)
{
	char *ptr = (char*)malloc(10);

	if(NULL == ptr)
	{
		printf("\n Malloc failed \n");
		return;
	}
	else
	{

		free(ptr);
	}

	return;
}
#endif

#if 0
int main()
{
	int ch = 1;

	switch(ch) {

		case 1:
			printf("i am in case 1\n");
			return;

		default:
			printf("in default case\n");

	}
	printf("in main\n");
	return 0;
}

#endif

#if 0

int main()
{	
	int func() {
		printf("chandu viswanadham\n");
		return 0;
	}

	func();
	main(10);
	printf("happy\n");
	return 0;
}
#endif

#if 0
# include <stdio.h>
int main ()
{
	int a[] = { 00001, 00010, 00100, 01000 };
	int i;
	for ( i = 0 ; i < 4 ; i++)
		printf("%o\t", a[i]);
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	float arr[] = {12.4, 2.3, 4.5, 6.7};
	printf("%d\n", sizeof(arr)/sizeof(arr[0]));
	return 0;
}
#endif

#if 0
int main() 
{ 
	static a[3]={1}; 
	int b[3]={1}; 
	printf("%d %d",a[2],b[2]);
	return 0;
} 
#endif

#if 0
#define Max(a,b) a>b?a:b 
int main() 
{ 
	printf("%d\n", Max(100,100)+10); 
} 
#endif

#if 0
#define x 10); 
int main() 
{ 
	printf("%d\n", x 

	} 
#endif

#if 0
#include "program.s"

			int main()
			{
			return 0;
			}

#endif

#if 0
#include <stdio.h>
			int main()
			{
			int i = 3;
			int j = 4;
			float f1 = i / j;
			float f2 = (float) i / j;
			printf("3 / 4 == %f or %f depending on the type used.\n", f1, f2);
			}
#endif

#if 0

#define f(a,b) a##b
#define h(a) g(a)
#define g(a) #a

int main()
{
	printf("%s\n",h(f(1,2)));
	printf("%s\n",g(f(1,2)));
	return 0;
}
#endif

#if 0
int main()
{
	int a[3] = {0001, 0010, 0090};  //zero is represented for octal in c, octal only contains interger constants from 0 to 7. 
	return 0;
}
#endif

#if 0
int main()
{
	int a = 'c';
	int b = 'cp';

	printf("a = %x\tb = %x", a, b);
	return 0;
}
#endif

#if 0
int main()
{
	char *str = "chandu \\nviswanadham\"";
	printf("%s\n", str);
	return 0;
}
#endif

#if 0


int main()
{
	enum { a, b, c, d = 0, e = 1, f, g, h = c };
	printf("a = %d\t d = %d\t f = %d\t h = %d\n", a, d, f, h);
	int *p = &a;
	int *q = &b;
	//	int a = 10, b = 15;
	printf("sum = %d\n", sum(p, q));

	//	printf("a  = %p \t h = %p", &a, &h);
	return 0;
}

int sum(int *a, int *b) {

	return (*a + *b);
}
#endif

#if 0

int main()
{
	int  a[5] = {1, 2, 3, 4, 5};
	int *ptr = a;
	char  *ptr1 = (char *)a;
	int i = 0;

	for(i = 0 ;i < 5; i++, ptr++) {
		printf("ptr  :%p \t data : %d\t\n", ptr, *ptr);
	}

	printf("\n");

	//	printf("%d\t\n", *ptr);

	for(i = 0 ;i < 5; i++, ptr1 = (char *)((int *)ptr1 + 1)) {  //eventhough we modify the increment it will increment only one so use + 1 for perfect answer

		printf("ptr 1 :%p \t data : %d\t\n", ptr1,*(int *)ptr1);

	}

	return 0;

}
#endif

#if 0

//static int fun();
int main()

{

	printf("before declaration:%d\n", fun());
}

static int fun()
{
	return 10;
}

#endif

#if 0
struct happy {
	int a;
	int b;
};
int main()
{	
	/*	struct happy {
		int a;
		int b;
		};
	 */
	struct happy *ptr = "NUL";

	ptr = (struct happy*) malloc(sizeof(struct happy));
	ptr -> a = 10;
	ptr -> b = 20;

	//printf("%d\t%d\\n", (*ptr).a, (*ptr).b);
	printf("%d\t%d\n", ptr -> a, ptr -> b);
	return 0;
}
#endif
#if 0

int fun(void)                                                                   
{                                                                               
	return 1,2,3;                                                               
}                                                                               

int main(void)                                                                  
{                                                                               
	int i;                                                                      
	i = 1,2,3;                                                                  
	printf ("%d\n",i);                                                          
	i =fun();                                                                   
	printf ("%d\n",i);                                                          
	return 0;                                                                   
}
#endif

#if 0

static int a;
int b;

int main()
{
	int a = 10;
	int b = 20;
	printf("%d\t%d", a, b);
	return 0;
}

#endif

#if 0
int main()
{
	int arr[4] = {3, 2, 0, 1};
	int i = 0;

	for(i = 0; i < 4; i++) {
		printf("%d\t", arr[i]);
	}

	for(i = 0; i < 4; i++) {

		arr[arr[i]] = arr[arr[i]] + arr[i];
		//arr[i] = arr[arr[i]] - arr[i];

		if (arr[arr[i]] - arr[i]) {
			arr[i] = arr[arr[i]] - arr[i];
		} else { 
			arr[i] = abs(arr[arr[i]] - arr[i]);
		}

		if (arr[arr[i]] - arr[i]) {

			arr[arr[i]] = arr[arr[i]] - arr[i];

		} else {

			arr[arr[i]] = abs(arr[arr[i]] - arr[i]);
		}

	}

	/*	for(i = 0; i < 4; i++) {
		printf("%d\t", arr[i]);
		}
	 */	return 0;
}
#endif

#if 0
#include<stdio.h>
int main(){
	double num=5.2;
	int var=5;
	printf("%d\t",sizeof(num && num));
	printf("%d\t",sizeof(var=15/2));
	printf("%d",var);
	return 0;
}
#endif

#if 0

int main (void)                                                                 
{                                                                                  

	printf("sd : %d \n", fileno(stdin));                                        
	printf("sd : %d \n", fileno(stdout));                                       
	printf("sd : %d \n", fileno(stderr));                                                                        

	return 0;                                                                   
}

#endif

#if 0

size_t my_size (int n);

int main ()
{
	int n;

	scanf ("%d", &n);

	printf ("%d\n", my_size (n));

	return 0;
}

size_t my_size (int n)
{
	char a[n + 3];

	return sizeof (a);

}

#endif

#if 0			//can we change 0			//can we change 
int main()
{
	printf("%s\n", __TIME__);
#undef __TIME__

#define __TIME__ "14:15:10"
	printf("%s\n", __TIME__);
	printf("%s\n", __DATE__);
	return 0;
}
#endif

#if 0
#define #define 10

int main()
{
	printf("%d", #define);
	return 0;
}
#endif

#if 0	//# will place the quotes from where it encountered to only to the single macro.

#define MAX(a, b)  #a##b //"viswanadham"

int main()
{	
	printf("%s", MAX(chandu, viswanadham));
	return 0;
}
#endif

#if 0	//proto type mismatch
//const char *a = "hello";
int printf("%d",10);

int main()
{

	printf("%d", 10);
	return 0;
}
#endif

#if 0

#include <chandu>.c >

int main()
{
	printf("a value is :%d", a);
	return 0;
}
#endif

#if 0

#define MAX

#ifndef MAX
#define MAX 100

#endif

int main()
{
	printf("%d", MAX);
	return 0;
}
#endif

#if 0
#error "chanduviswanadham"


int main()
{
	return 0;
}
#endif

#if 0	//null directive will not show any impact on the compilation
#
#
#
int main()
{	
	return 0;
}
#endif

#if 0

int main()
{
	printf("line:%d\n", __LINE__);
	printf("File:%s\n", __FILE__);
	printf("date:%s\n", __DATE__);
	printf("time:%s\n", __TIME__);
	printf("stdc:%d\n", __STDC__);
	return 0;
}

#endif

#if 0

#include <stdio.h>

void function1( );
void function2( );

#pragma startup function1
#pragma exit function2

int main( )
{
	printf ( "\n Now we are in main function" ) ;
	return 0;
}

void function1( )
{
	printf("\nFunction1 is called before main function call");
}

void function2( )
{
	printf ( "\nFunction2 is called just before end of main function");
}
#endif

#if 0

#define 1@# 10
int main()
{
	return 0;
}

#endif

#if 0

//char printf(const char *, ...);
int main()
{
	char a = 0;
	printf("%d", sizeof(a = printf("hello""viswanadham")));
	return 0;
}
#endif

#if 0

int main()
{
	int a = -250, b = -50, c = -40;
	//	a > b ? printf("10"): printf("20");
	((a > b) && (a > c)) ? printf("%d", a) : (b > c) ? printf("%d", b) : printf("%d", c);
	return 0;
}

#endif

#if 0

char str1[100];

char *fun(char str[])
{
	static int i = 0;
	if (*str)
	{
		fun(str+1);
		str1[i] = *str;
		i++;
	}
	return str1;
}

int main()
{
	char str[] = "GATE CS 2015 Mock Test";
	printf("%s", fun(str));
	return 0;
}
#endif

#if 0

int main()
{
	int i = 1024;
	for (; i; i >>= 1)
		printf("GeeksQuiz");
	return 0;
}
#endif

#if 0
#define PRINT(i, limit) do \
{ \
	if (i++ < limit) \
	{ \
		printf("GeeksQuiz\n"); \
		continue; \
	} \
	printf("djkfhajkdhfjkasd\n"); \
}while(0)

int main()
{
	int i = 0;
	PRINT(i, 3);
	return 0;
}
#endif

#if 0

int main()
{
	int i = 1;

	do {
		printf("%d\nenter input:\n", i);
		//		scanf("%d", &i);
		i = (int) getchar();
		printf("entered value :%d\n", i);
	}while(i == 1);
	return 0;
}
#endif

#if 0
void func();

int main()
{
	func();
	func();
	return 0;
}

void func()
{
	static int num1 = 0, int num2 = 0;
	printf("num1 = %d\n num2 = %d", num1, num2);
	num1++;
	num2++;
}
#endif

#if 0
int main()
{
	int i = 1, j;
	for ( ; ; )
	{ 
		if (i)
			j = --i;
		if (j < 10)
			printf("GeeksQuiz", j++);
		else
			break;
	}
	return 0;
}
#endif

#if 0

int main()
{
	int i ;
	int j;
	switch(1)
	{
			case 1:
				printf("case one\n");
				continue;
//				break;
//				case j = 10:
//						printf("j value is :%d", j);
//				break;
				
			default:
				printf("default...value of i is:%d\n", i);
		 
	}
	return 0;
}
#endif

#if 0

#if X == 1
#define Y 3
#else 
#define Y 5
#endif

int main()
{
	printf("%d", Y);
	return 0;
}
#endif

#if 0

int main()
{
	printf("%schandu viswanadham", "happy");// string need another string starting address
	return 0;
}
#endif

#if 0
#define a 10
int main()
{	
	printf("%d", a);	//what ever the latest update that will be taken to in the account by preprocessor
#define a 50
	printf("%d", a);
	return 0;
}
#endif

#if 0


int main()
{
	return 0;
}

#endif

#if 0

#define A -B
#define B -C
#define C 5

int main()
{
	printf("value is:%d", A);
	return 0;
}
#endif

#if 0

struct mem {
	int num1;
	int num2;
}x = {1, 10};

int main()
{
	if(x.num1 == x.num2) {
		printf("value is :%d", x.num1);
	}
	else 
		printf("value is :%d", x.num2);
}
return 0;
}
#endif

#if 0

void func(void);

int main()
{
	int arr[] = {20};
	int a = 10;
	func();
	return 0;
}

void func(void)
{
	extern int arr[];
	extern int a;

	printf("size of a :%d", sizeof(arr));	//invalid on arr[]
	printf("size of a :%d", sizeof(a));		//valid on a 
	return;
}

#endif


#if 0
int *ptr;

int main()
{
	printf("ptr holding address:%p \t value is:", ptr);
	return 0;
}
#endif

#if 0
int main ()
{
	char a[6] = "world";
	int i, j;
	for (i = 0, j = 5; i < j; a [i++] = a [j--]);
	printf ("%s\n", a);
	return 0;
}
#endif

#if 0

int main()
{
	//float f = 40.15625;
	printf("%d\t", 40.123);
	return 0;
}
#endif

#if 0

int main()
{
	char str[] = "123456789";
	char *str1 = "123456789";
	char str2[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

	//	printf("str[] of str[1] = %c\tstr[1] = %s\n", str[1], str + 1);
	//	printf("*str1 of str1 = %c\tstr[1] = %s\n", str1, str1 + 1);
	//	printf("str[] = %p, str1[] = %p, str2[] = %p", &str, &str1, &str2);

	//	printf("sizeof str = %d\tsizeof str2 = %d", sizeof(str), sizeof(str2));
	printf("str2[] of str[1] = %c\tstr[1] = %s\n", str2[1], str2);

	return 0;
}
#endif

#if 0

int main()
{
	int *ptr = func();
	printf("array= %s", ptr);
	return 0;
}

int func()
{
	int arr[3] = { 1, 2, 3};
	return arr;
}

#endif

#if 0

int fun();
int main()
{
	int (*ptr)(int ) = fun;
	(*ptr)(3);
	return 0;
}

int fun(int n)
{
	for(;n > 0; n--)
		printf("GeeksQuiz ");
	return 0;
}

#endif

#if 0


int main()
{
	extern int num;
	//	printf("%p", &num);
	return 0;
}

//int num = 10;
//int num;
#endif

#if 0
#include <stdarg.h>

int func(int count, int next, ...)
{
	va_list ref;
	int i;

	va_start(ref, next);

	for(i = 0; i <= 3; i++) {
		printf("%d\t", va_arg(ref, int));
	}
	va_end(ref);

	return 0;
}

int main()
{
	func(5, 1, 2, 3, 4, 5);
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;
	int b = 15;

	printf("=%d",(a+1),(b=a+2));
	printf(" %d=",b);

	return 0;
}
#endif

#if 0

/*int func(){
  printf("int func");
  return 0;
  }
 */int func() {
	 printf("in another func:%d\t%d", a, b);
	 return 0;
 }

int main()
{
	func();
	func(10, 20);
	func(15);
	return 0;
}
#endif

#if 0

int main()
{
	static int i=5;
	if(--i){
		main();
		printf("%d ",i);
	}
}
#endif

#if 0

int main()
{
	func(10, 20);
	return 0;
}

void func(int a, int b) {
	printf("%d\t%d", a, b);
	return;
}
#endif

#if 0

#define max(a) #@a

int main()
{	
	printf("%c", max(b));
	return 0;
}
#endif

#if 0

int main()
{
	register int i = 10;
	int *a = &i;	//registers wont give their addresses
	printf("%d", *a);
	return 0;
}
#endif

#if 0

extern int num;
int main()
{
	//	int num;
	//	extern int num = 70;
	//	num = 70;
	printf("%d\t", num);
	int func()
	{
		int a = 40;
		printf("%d\t", a);
		return 0;
	}
	fun();
	return 0;
}

//int num = 60;

int fun()
{	
	//	printf("%d", num);
	return 0;
}


#endif
#if 0
int main()
{
	int arr[3] = {1, 2, 3};
	int (*p)[3] = NULL;

	p = &arr;

	printf("[%p]\t%d\n", arr, arr[0]);
	printf("[%p]\t%p\t%d\n", p, *p, **p);
	//	printf("[%p]\t%d\t%p\n", *p, **p, ++p);
	return 0;
}
#endif

#if 0
char *fun()
{
	static char arr[1024];
	return arr;
}

int main()
{
	char *str = "geeksforgeeks";
	strcpy(fun(), str);
	str = fun();
	strcpy(str, "geeksquiz");
	printf("%s", fun());
	return 0;
}
#endif

#if 0

int main()
{
	int *ptr = NULL;
	int *ptr1 = NULL;

	ptr = (int *)malloc(10);
	ptr1 = (int *)malloc(10);

	printf("before ptr\n:");
	printf("%u\t", *ptr);
	printf("%u\t", *(ptr + 1));
	printf("%u\t", *(ptr + 2));
	printf("%u\n", *(ptr + 3));

	free(ptr);
	//free(ptr1);

	printf("after ptr free\n:");
	printf("%u\t", *ptr);
	printf("%u\t", *(ptr + 1));
	printf("%u\t", *(ptr + 2));
	printf("%u\n", *(ptr + 3));

	free(ptr1);

	printf("before ptr1 free\n:");
	printf("%u\t", *ptr);
	printf("%u\t", *(ptr + 1));
	printf("%u\t", *(ptr + 2));
	printf("%u\n", *(ptr + 3));


	printf("after ptr1 free\n:");
	printf("0x%X\t", *ptr1);
	printf("%u\t", *(ptr1 + 1));
	printf("%u\t", *(ptr1 + 2));
	printf("%u\n", *(ptr1 + 3));

	printf("0x%X\n", ptr);
	printf("0x%X\n", &ptr);
	printf("0x%X\n", ptr1);
	printf("0x%X\n", &ptr1);
	//	free(ptr);

	return 0;

}
#endif

#if 0
#include <malloc.h>

void display(int *ptr);
int main()
{
	int *ptr = NULL;
	int *cal = NULL;

	ptr = (int *)malloc(10);
//	cal = (int *)calloc(3, 4);

	malloc_stats();

	ptr[0] = 100;
	ptr[1] = 200;
	ptr[2] = 300;

/*	cal[0] = 100;
	cal[1] = 200;
	cal[2] = 300;

	display(ptr);
	display(cal);

	free(ptr);
	free(cal);

	malloc_stats();
	
	ptr = (int *)malloc(10);
//	cal = (int *)calloc(3, 4);

	display(ptr);
	display(cal);
*/	
	free(ptr);

	malloc_stats();

	
//	malloc_stats();
	
//	free(ptr);
	
//	malloc_stats();

//	printf("ajshdfjkhaskf\n");

	return 0;
}

void display(int *ptr) {
	int i = 0;

	for(i = 0; i < 3; i++) {
		printf("%d\t", ptr[i]);
	}
	printf("\n");
	return;
}
#endif

#if 0

int main()
{	
	int *ptr;
	ptr = NULL;

	//	*ptr = 10;

	//	printf("%d", *ptr);
	free(ptr);		// why it is working
	free(ptr);
	free(ptr);
	return 0;
}
#endif

#if 0

int main()
{
	int *ptr;

	printf("wild pointer:%d", *ptr);

	ptr = (int *)malloc(sizeof(int));

	*ptr = 10;

	printf("pointer :%d", *ptr);

	free(ptr);

	printf("dangling pointer :%d", *ptr);

	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;

	printf("=%d %d=",(a+1), a, a, a);

	return 0;
}
#endif

#if 0

int main()
{	
	int a = 10, b;

	10 > 20 ? (a = 30, b = 30) : (a = 40,b = 40);

	printf("a= %d\tb=%d", a, b);
	return 0;
}
#endif

#if 0
int main()
{
	int a;
	int a;

	return 0;
}
#endif

#if 0

int main()
{
	int i = 15;
	int res = 0;

//	sizeof(i = 10);

	printf("%d\t", sizeof "chandu");		//without () it is working fine 

	printf("%d", i);

	return 0;
}

#endif

#if 0

int main()
{
	int i = 15;

	printf("%d\t%d\t%d", ++i, ++i, i++);

	return 0;
}
#endif

#if 0

int main()
{
	FILE *fp;
	char c;

	if(NULL == (fp = fopen(__FILE__, "r"))) {
		perror("open failed\n");
		exit(1);
	}

	while((c = fgetc(fp)) != EOF) {
		putc(c, stdout);
	}

	return 0;
}
		
#endif

#if 0

#include <assert.h>

int main()
{
	int x = 7;

	x = 9;

	assert(x = 7/0);

	return 0;
}

#endif

#if 0

int main()
{
	printf("%d");
	return 0;
}

#endif

#if 0

int func(int a, int b) {

	return a+b;
}

int main()
{
	printf("%d\n", func(10,20));
	printf("%d\n", func(20,30));
	printf("%d\n", func(30,40));

	return 0;
}

#endif

#if 0

int main()
{
	printf("%d", sizeof('\0'));	//'\0' will give 4 and "\0"will give 2
	return 0;
}
#endif

#if 0

int main()
{
	int a = 4;
	int b = 5;
	int sum;
	
	sum = func(a,b);

	return 0;
}

int func(int a, int b)
{
	int c;

	c = a + b;

	return c;
}
#endif

