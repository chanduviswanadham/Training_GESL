#include<stdio.h>
#if 0
int main()
{
	char ch='A';
	printf("%d",ch);
	printf("%c",ch);
	return 0;
}
#endif

#if 1

int main()
{
	enum month{jan=1,feb,mar=4,apr,may};
	printf("jan=%d\n",jan);
	printf("apr=%d\n",apr+1);
	return 0;
}
#endif
