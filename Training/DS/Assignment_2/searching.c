#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int binary(int *, int, int, int);
int r_binary(int *, int, int, int);
int s_search(int *, int, int);
int s_r_search(int *, int, int, int);

int main()
{
	int arr[MAX] = {5, 10, 15, 19, 25, 26, 35, 45, 74, 110};
	int search = 0;
	int index;
	int choice;


	do{
		
		printf("1.sequencial search\n2.binary search\n3.sequential recursive" 
				"search\n4.recursive binary search\n0.exit\nyour choice:\n");
		scanf("%d", &choice);
	
		if(choice != 0) {
			printf("enter the element you need to search:\n");
			scanf("%d", &search);
		}
		switch (choice) {
		
		case 0:
			break;
		
		case 1:
			index = s_search(arr, search, MAX);
			if (index) {
				printf("number is found in the array in the %d position\n", index);
			} else {
				printf("number not found in the array..........!\n");
			}
			break;
		
		case 2:
			index = binary(arr, 0, MAX - 1, search);
			if (index) {
				printf("number is found in the array in the %d position\n", index);
			} else {
				printf("number not found in the array..........!\n");
			}
			break;

		case 3:
			index = s_r_search(arr, 0, search, MAX);
			if (index) {
				printf("number is found in the array in the %d position\n", index);
			} else {
				printf("number not found in the array..........!\n");
			}
			break;
		
		case 4:
			index = r_binary(arr, 0, MAX - 1, search);
			if (index) {
				printf("number is found in the array in the %d position\n", index);
			} else {
				printf("number not found in the array..........!\n");
			}
			break;
		}

	} while (choice != 0);
	
	return 0;
}

int s_search(int *arr, int search, int n) {
	int i = 0;
	for (;i < n; i++) {
		if (arr[i] == search) 
			return (i+1);
	}
	return 0;
}

int s_r_search(int *arr, int index,int search, int n) {
	if (index == n) {
		return 0;
	} else if (arr[index] == search) {
		return index + 1;
	} else 
		s_r_search(arr, index + 1, search, n);
}

int binary(int *arr, int start, int end, int search)
{
	int mid;
	mid = (start + end)/2;
	
	while (mid >= start && mid <= end) {
		
		if ( arr[mid] == search) {
			return (mid + 1);
		} else if (arr[mid] > search) {
			end = mid - 1;
			mid = (start + end)/2;
		} else if (arr[mid] < search) {
			start =  mid + 1;
			mid = (start + end)/2;
		} 
	}

	return 0;
}

int r_binary(int *arr, int start, int end, int search)
{
	int mid;
	mid = (start + end)/2;
	if ( arr[mid] == search) {
		return (mid + 1);
	} else if (start < end) {
		if (arr[mid] > search) {
			end = mid - 1;
			r_binary(arr, start, end, search);
		} else {
			start =  mid + 1;
			r_binary(arr, start, end, search);
		}	 
	} else {
		return 0;
	}
}


