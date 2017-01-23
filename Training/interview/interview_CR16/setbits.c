#include <stdio.h>

unsigned int setbits(int);		//function proto type

int main( void )
{
	int no = 20;

	printf("%d\n", setbits(no));	//calling the setbits function

	return 0;
}

unsigned int setbits(int num)	//function definition
{
	unsigned int count = 0;		//count is always positve
	
	while(num) {

		num = num & (num - 1);

		count++;
	}

	return count;
}
		

