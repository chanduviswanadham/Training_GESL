#include<stdio.h>

#if 1
struct node {
	int a;
	char c;
	int b;
    }nod;
struct link {
	char a;
	short i;
    }lin;
struct pan {
	char ch;
	int a;
	char p;
     }pa;
struct can {
	char m;
	char c;
	int n;
      }ca;
struct mms {
	char ch;
	short s;
	int n;
      }mm;
struct nm {
	char c;
    }n;
struct art {
	short s;
	short n;
	char ch;
      }ar;
struct quier {
	short s;
	short n;
	int m;
     }quie;
struct covet {
	short s;
	int n;
	short m;
    }cove;
struct cha{
	char b;
	int a;
	char c;
}ch;
int main(void)
{
	printf("%d\n", sizeof(struct node));
	printf("%d\n", sizeof(struct link));
	printf("%d\n", sizeof(struct pan));
	printf("%d\n", sizeof(struct can));
	printf("%d\n", sizeof(struct mms));
	printf("%d\n", sizeof(struct nm));
	printf("%d\n", sizeof(struct art));
	printf("%d\n", sizeof(struct quier));
	printf("%d\n", sizeof(struct covet));
	printf("%d\n", sizeof(struct cha));
	return 0;
}
#endif
