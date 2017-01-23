#include <stdio.h>

#if 1

//#pragma pack(push,2)
struct name {
	char a;
	int b;
	char c;
	char d;
	int e;
	char f;
	char g;
	char h;
	int i;
	char j;
};
//#pragma pack(pop)

int main()
{
	printf("%d\t\n", sizeof(struct name));
	return 0;
}
#endif
