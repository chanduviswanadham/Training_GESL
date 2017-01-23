#include <stdio.h>

#if 1
union mystruct
{
	int a;
	char name[22];
};
int main()
{
	printf("%d", sizeof(union mystruct));
	return 0;
}
#endif

#if 0
union u 
{
	int a;
	char b;
}u1;
int main()
{
u1.a = 10;
printf("%d", u1.b);
return 0;
}
#endif

#if 0

struct my
{
	unsigned int a:4;
	unsigned int b:4;
}v1 = {-1,-1};

int main()
{
	printf("%u\t%u", v1.a, v1.b);
	return 0;
}

#endif

#if 0
int main()
{
	struct name
	{ 
		static int i;
		char arr[10];
	};
	struct name obj1, obj2;
	obj1.i = 1000;
	printf("%d", obj2.i);
	return 0;
}
#endif

#if 0
union A 
{
	char character;
	int ascii;
};
int main()
{
	union A arr[2] = {{65},{'a'}};
	printf("%c\t%c\n", arr[0], arr[1]);
	return 0;
}
#endif

#if 0
int main()
{
	union name {	
		int _i;	
		float _f;
	} _u = {10};
	printf("%f\n",_u._f );
	printf("%d\n",_u._i );
	return 0;
}
#endif

#if 0
struct a
{
	int x;
	struct a b;
};

int main()
{
	struct a st;
	st.x = 10;
	printf("%d", st.x);
	return 0;
}
#endif

#if 0
int main()
{
	struct happy 
	{		
		enum app {a,b,c};
	}obj;
	printf("%d %d %d", obj.a, obj.b, obj.c);
	return 0;
}
#endif

#if 0 
typedef enum errortype
{	
	warnings, errors, expectdes,
}error;

int main()
{
	error g1;
	g1 = 1;
	printf("%d\n", g1);
	return 0;
}
#endif
