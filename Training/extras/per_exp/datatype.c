#include <stdio.h>
#include <limits.h>
#include <float.h>
int main()
{
	printf("sizeof int:%d\n", sizeof(int));
	printf("min:%d\tmax=%d\n",INT_MIN,INT_MAX);
	printf("sizeof long int:%d\n", sizeof(long int));
	printf("min:%ld\tmax=%ld\n",LONG_MIN,LONG_MAX);
	printf("sizeof float:%d\n", sizeof(float));
	printf("min:%f\tmax=%f\tprecision%d\n",FLT_MIN,FLT_MAX, FLT_DIG);
	printf("sizeof double:%d\n", sizeof(double));
	printf("min:%lf\tmax=%lfprecision:%d\n",DBL_MIN,DBL_MAX,DBL_DIG);
	return 0;
}
	
