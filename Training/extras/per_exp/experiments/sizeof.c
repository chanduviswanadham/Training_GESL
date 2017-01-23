#include<stdio.h>
//size of each datatype
#if 0
int main()
{
	printf("the size of the int:%d\n",sizeof(int));
	printf("the size of the float:%d\n",sizeof(float));
	printf("the size of the char:%d\n",sizeof(char));
	printf("the size of the double:%d\n",sizeof(double));
	return 0;
}
#endif

// size of the qualifers

#if 0

int main(void)
{
	
	printf("the size of the signed int:%d\n",sizeof(signed int));
	printf("the size of the unsigned int:%d\n",sizeof(unsigned int));
	printf("the size of the short int:%d\n",sizeof(short int));
	printf("the size of the long int:%d\n",sizeof(long int));
	printf("the size of the signed char:%d\n",sizeof(signed char));
	printf("the size of the unsigned char:%d\n",sizeof(unsigned char));
	printf("the size of the long double:%d\n",sizeof(long double));
	return 0;
}
#endif

//use of the qualifers

#if 1

int main(void)
{

	printf("the size of the long long int:%d\n",sizeof(long long int));
	//printf("the size of the long long float:%d\n",sizeof(long long float));
	//printf("the size of the long long double:%d\n",sizeof(long long double));
	//printf("the size of the long long long int:%d\n",sizeof(long long long int));
	//printf("the size of the long long long float:%d\n",sizeof(long long long float));
	//printf("the size of the long long long double:%d\n",sizeof(long long long double));
	//printf("the size of the long long long long int :%d\n",sizeof(long long long long int));
	//printf("the size of the long long long long long int:%d\n",sizeof(long long long long long int));
	printf("the size of the short int:%d\n",sizeof(short int));
	//printf("the size of the short short int:%d\n",sizeof(short short int));
	//printf("the size of the short short short int:%d\n",sizeof(short short short int));

	
	return 0;
}

#endif


