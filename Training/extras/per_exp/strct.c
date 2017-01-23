#include <stdlib.h>

#if 0 

struct a {

    struct b *m;

    int n;

} p;

struct b {
	double b;
}

 

int main()

{

    p.m = malloc (8);

    p.m->h = 9;

 

    return 0;

 

}

#endif

#if 1
#pragma pack (4)
struct chandu {
	int  a : 2;
	int b: 4;
	char c : 2;
	int d : 2;
};

int main()
{
	struct chandu priya = { -1, 2, -3 , 4};
	printf("%d\t%d\t%d\t%d\n", priya.a, priya.b, priya.c, priya.d);
	printf("%u\t%u\t%u\t%u\n", priya.a, priya.b, priya.c, priya.d);
	printf("%d\n", sizeof(priya));
	return 0;
}
#endif

