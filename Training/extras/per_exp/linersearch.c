#include <stdio.h>
#include <stdlib.h>
#if 1

void rec_search(int arr[], int search, int si);
int main()
{
	int arr[5] = { 55, 42, 12, 16, 17};
	rec_search(arr, 10, sizeof(arr)/ sizeof(arr[0]));
	return 0;
}

void rec_search(int arr[], int search, int size)
{
	printf("size is :%d\n", size);
	if (search == arr[0]) {
		printf("element found\n\t%d\n", arr[0]);
		exit(0);
	} else if (size == 0) {
		printf("element not found\n");
	} else {
		rec_search(++arr,search,--size);
	}
}
#endif
