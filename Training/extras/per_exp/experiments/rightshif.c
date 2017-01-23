#include<stdio.h>

int main()
{
	unsigned int num;
	printf("enter the hexa decimal number:\n");
	scanf("%x",&num);
	num=num>>3;
	printf("the shifted value of the hexa decimal value:%x\n",num);
	return 0;
}

