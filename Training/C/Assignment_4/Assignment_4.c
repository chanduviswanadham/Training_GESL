#include <stdio.h>

#if 0

struct initial1{
	unsigned char vpi : 4;
	unsigned char gfc : 4;
	unsigned char vci : 4;
	unsigned char vpi2 : 4;
	unsigned char vci2 : 8;
	unsigned char clp : 1;
	unsigned char : 1;
	unsigned char pti : 1;
	unsigned char : 1;
	unsigned char vci3 : 4;
	unsigned char hec : 8;
}i1;

struct initial2{
	unsigned int sp : 16;
	unsigned int dp : 16;
	unsigned int sn : 32;
	unsigned int acn : 32;
	unsigned int hl : 4;
	unsigned int re : 6;
	unsigned int cb : 6;
	unsigned int wi : 16;
	unsigned int cs : 16;
	unsigned int ur : 16;
	unsigned int op : 32;
	unsigned int da : 32;
}i2;

struct initial3{
	unsigned int ve : 4;
	unsigned int hl : 4;
	unsigned int st : 8;
	unsigned int tl : 16;
	unsigned int id : 16;
	unsigned int fl : 4;
	unsigned int fo : 12;
	unsigned int ttl : 8;
	unsigned int po : 8;
	unsigned int hc : 16;
	unsigned int sip : 32;
	unsigned int dip : 32;
	unsigned int op : 20;
	unsigned int pd : 12;
}i3;

int main(void)
{
	printf("the size of the structure 1 is : %d\n", sizeof(i1));
	printf("the size of the structure 2 is : %d\n", sizeof(i2));
	printf("the size of the structure 3 is : %d\n", sizeof(i3));
	return 0;
}
#endif

#if 0
extern show_bit(int);
union sample
{
	int a:5;
	int b:10;
	int c:5;
	int d:21;
	int e;
}s;

int main()
{
	printf("enter the value:\n");
	scanf("%d", &s.e);
	show_bit(s.e);
	printf("the value present in the a is:%d\n", s.a);
	printf("the value present in the b is:%d\n", s.b);
	printf("the value present in the c is:%d\n", s.c);
	printf("the value present in the d is:%d\n", s.d);
	
	return 0;
}
#endif

#if 1

union endiness
{
	int a;
	char ch[2];
}en;
int main()
{
	en.a = 20;
	if(en.ch[0] == 0){
		printf("it is big endian type storage\n");
	}
	else{
		printf("it is little endian type storage\n");
	}
	return 0;

}
#endif

