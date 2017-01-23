#include <stdio.h>

int main()
{
	unsigned int n = 0;
	char *ptr = NULL;
	int res = 0, i = 0;


	read(0, &n, sizeof(n));

	ptr = (char *)&n;

//	loop to convert hex to int

	for(i = 0; i < 4; i++) {
		res = (res * 10) + (ptr[i] - '0');
	}

//increament in interger

	res = res + 1;

//storing data
	for(i = 3; i >= 0; i--) {
		ptr[i] = '0' + (res % 10);
		res = res/10;
	}


	write(1, ptr, 4);
	

	return 0;
}
