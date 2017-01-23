#include <stdio.h>
#include <stdlib.h>

#if 0

int main(void)
{
	int *ptr = NULL;
	int *ctr = NULL;

	int a = 12;
	int b = 4;
	int c = 3;

	if (NULL == (ptr = (int *)malloc(a))) {		//dynamic allocation of memory
		perror("malloc failed\n");
		exit(1);
	}
	if (NULL == (ctr = (int *)calloc(b, c))) {	//dynamic allocation of memory
		perror("malloc failed\n");
		exit(1);
	}

	*ptr = 10;
	*(ptr + 1) = 20;
	*(ptr + 2) = 30;

	*ctr = 100;
	*(ctr + 1) = 200;
	*(ctr + 2) = 300;

	printf("%d\t%d\t%d\n", *ptr, *(ptr + 1), *(ptr + 2)); 
	printf("%d\t%d\t%d\n", *ctr, *(ctr + 1), *(ctr + 2));

	free(ptr);
	free(ctr);

	return 0;
}

#endif

#if 0

int main(void)
{
	int *ptr = NULL;

	ptr = (int *)calloc(4, 3);

	printf("actual : 0X%x\n", ptr);

	ptr = realloc(ptr, 8);
	free(ptr);
	ptr = NULL;

	printf("shrinking : 0X%x\n", ptr);

	ptr = realloc(ptr, 16);

	printf("extending : 0X%x\n", ptr);

	//	free(ptr);

	//	printf("after freeing:0X%x\n", ptr);
	return 0;
}
#endif

#if 0
int main()
{
	int *ptr = NULL;

	ptr = (int *)malloc(0);

	printf("0X%x\n", ptr);
	printf("pid : %d", getpid());
	getchar();
	return 0;
}
#endif

#if 0
void mallocWrapper(int **intArray, int length)
{
	*intArray = malloc(length * sizeof(int));
}

int main()
{

	int *array    = NULL;    //Whenever you declare a pointer assign it to NULL
	int arraySize = 10;

	mallocWrapper(&array, arraySize);

	array[0] = 100;
	array[1] = 200;
	printf("%d", array[1]);

	free(array);
	return 0;
}

#endif
