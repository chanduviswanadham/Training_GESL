#include <stdio.h>

static int sta_in = 10;			//data
const int con_in = 15;			//ro data
int glo_in = 25;		//data
volatile int vol_in = 250;		//data
int glo_in_zero = 0;
int *ptr = NULL;
int *ptr1;

static int sta_un;		//.bss
const int con_un;		//common
int glo_un;			//common
volatile int vol_un;		//common

int main()
{
	static int fun_sta_in = 10; //data
	const int fun_con_in = 15;	//stack
	int *p = &fun_con_in;//stack
	int fun_glo_in = 25;//stack
	volatile int fun_vol_in = 250;//stack

	static int fun_sta_un;//.bss
	const int fun_con_un;//stack
	int fun_glo_un;//stack
	volatile int fun_vol_un;//stack
	printf("the value of fun_con_in is :%d\n", fun_con_in);
	*p = 250;
	printf("the value of fun_con_in is :%d\n", fun_con_in);
/*	printf("the value of con_in is :%d\n", con_in);
	p = &con_in;
	*p = 150;
	printf("the value of con_in is :%d\n", con_in);
	printf("the value of a is :%d", a);
	printf("the value of b is :%hi", b);
	printf("the value of c is :%f", c);
	printf("the value of d is :%lf", d);

	
	printf("the value of e is :%d", e);
	printf("the value of f is :%d", f);
//	printf("the value of g is :%d", g);
	printf("the value of h is :%d", h);
*/	return 0;
}
