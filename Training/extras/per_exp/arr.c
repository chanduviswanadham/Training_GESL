#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
int main()
{
	int i;
	
	int a[3] = {1,2,3};
	printf("enter the array index:");
	scanf("%d", &i);
	printf("arr[%d] = %d\n", i, a[i-1]);
	return 0;
}

#endif
#if 0
void func(void *, int);
int main()
{
	int arr[4] = {1,2,3,55};
	func(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}

void func(void * ptr, int size)
{
	int *arr;
	arr = (int *) ptr;
	printf("size of the array:%d\n", size);
	while(size--) {
		printf("%d\n", *arr);
		arr++;
	}
}
#endif
#if 0
int main(void)                                                                  
{                                                                               
    char a[10][5] = {"hi", "hello", "fellows"};
	printf("%s\n", a[2]);
	printf("%c\n", *a[2]);
	return 0;
}

#endif

#if 1
int main()
{
	int arr[5] = { [0 ... 4] = 1 };	//one of the way to make all thw elements to any value
	int i;

	printf("before memset:\n");
	for(i = 0; i < 5; i++) {
		printf("%d\t", arr[i]);
	}
	
	memset(arr, 'a', sizeof(arr));
	
	printf("\nafter memset:\n");
	for(i = 0; i < 5; i++) {
		printf("%d\t", arr[i]);
	}

	return 0;
}

#endif
