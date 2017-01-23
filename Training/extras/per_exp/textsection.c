#include <stdio.h>

int main()
{
	FILE *fp = NULL;
	FILE *fp1 = NULL;
	
	unsigned char *code = 0x08048000;
	unsigned char *gnu = 0x08049000;

	fp = fopen("code.dat","w+");
	fp1 = fopen("gnu.dat","w+");

	fwrite(code, 4096, 1, fp);
	fwrite(gnu, 4096, 1, fp1);

	return 0;
}
