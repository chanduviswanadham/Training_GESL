//#include "sor_header.h"
#include <stdio.h>
#include <stdlib.h>

void bubble_sorting(int *, int);
void selection_sorting(int *, int);
void insertion_sorting(int *, int);
void merge_sorting(int *, int, int);
void merging(int *,int ,int, int);
void quick_sorting(int *, int, int);
void swap(int *, int, int);
void display(int *, int);

int main()
{
	int ch;
	int *arr = NULL;
	int n;
	int i = 0;
	
	do {
		
		printf("\n*********MENU*********\n");
		printf("1.Bubble sorting\n2.selection sorting\n3.insertion sorting\n"
				"4.merge sorting\n5.quick sorting\n0.EXIT\n");
		scanf("%d", &ch);
		
		if (ch != 0) {
			printf("enter the no of elements need to sort:\n");
			scanf("%d", &n);
			arr = (int *)malloc(sizeof(int) * n);

			printf("enter the elements:\n");
			for (i = 0; i < n; i++) {
				scanf("%d", &arr[i]);
			}
		}

		switch (ch) {
		
		case 1:
			bubble_sorting(arr, n);
			break;
		
		case 2:
			selection_sorting(arr, n);
			break;

		case 3:
			insertion_sorting(arr, n);
			break;
		
		case 4:
			merge_sorting(arr, 0, n - 1);
			display(arr, n);
			break;
		
		case 5:
			quick_sorting(arr, 0, n - 1);
			display(arr, n);
			break;

		case 0:
			break;

		default:
			printf("invalid option.......!");
		} 
	
	} while (ch != 0);

		return 0;
}

void bubble_sorting(int *arr, int n) 
{
	int i = 0;
	int j = 0;
	int temp;
	
	for (i = 0; i < (n - 1); i++) {
		for (j = 0; j < (n - 1 - i); j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	display(arr, n);
}
		
void selection_sorting(int *arr, int n)
{
	unsigned short min;
	unsigned short i = 0;
	unsigned short j = 0;
	int temp;

	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	display(arr, n);

}

void insertion_sorting(int *arr, int n)
{
	unsigned short i = 0;
	unsigned short d = 0;
	int temp;

	for (i = 1 ; i <= n - 1; i++) {
		d = i;
		while ( d > 0 && arr[d] < arr[d-1]) {
			temp = arr[d];
			arr[d] = arr[d-1];
			arr[d-1] = temp;
			d--;
		}
	}
	display(arr, n);
}

//merge sorting 

void merge_sorting(int *arr, int low, int up)
{
	int mid = 0;

	if(low < up) {
		mid = (low + up)/2;
		merge_sorting(arr, low, mid);
		merge_sorting(arr, mid + 1, up);
		merging(arr,low,mid,up);
	}
}

void merging(int *arr,int low, int mid, int up)
{
	int k = low;
	int l1 = low;
	int l2 = mid + 1;
//	int element = up - low + 1;
	int rarr[200];
//	rarr = (int*)malloc(sizeof(int) * up);	
	
	while((l1 <= mid)&& (l2 <= up)) {
		if (arr[l1] <= arr[l2]) {
			rarr[k++] = arr[l1++];
		} else {
			rarr[k++] = arr[l2++];
		}
	}
	while (arr[l1]) {
		rarr[k++] = arr[l1++];
	}
	while (arr[l2]) {
		rarr[k++] = arr[l2++];
	}
	for (k = low;k <= up; k++) {
		arr[k] = rarr[k];
	}
}

void quick_sorting(int *arr, int firstindex, int lastindex)
{
    //declaaring index variables
    int pivotIndex,
		temp, 
		index1, 
		index2;

    if(firstindex < lastindex)
    {
        //assigninh first element index as pivot element
        pivotIndex = firstindex;
        index1 = firstindex;
        index2 = lastindex;

        //Sorting in Ascending order with quick sort
        while(index1 < index2) {
            while(arr[index1] <= arr[pivotIndex] && index1 < lastindex) {
                index1++;
            }
            while(arr[index2] > arr[pivotIndex]) {
                index2--;
            }

            if(index1 < index2)
            {
                //Swapping opertation
                temp = arr[index1];
                arr[index1] = arr[index2];
                arr[index2] = temp;
            }
        }

        //At the end of first iteration, swap pivot element with index2 element
        temp = arr[pivotIndex];
        arr[pivotIndex] = arr[index2];
        arr[index2] = temp;

        //Recursive call for quick sort, with partiontioning
        quick_sorting(arr, firstindex, index2 - 1);
        quick_sorting(arr, index2 + 1, lastindex);
    }
}
void display(int *arr, int n)
{

	unsigned short ch;
	unsigned short i = 0;
	
	printf("what you want:\n1.asending order\n2.descending order\n");
	scanf("%hi", &ch);
	
	switch (ch) {
	
	case 1:
		printf("After sorting -  Ascending order :\n");
		
		for (i = 0; i < n; i++) {
			printf("%d\t", arr[i]);
		}
		break;
	
	case 2:
		
		printf("After sorting -  Descending order :\n");
		
		for (i = n - 1; i >= 0; i--) {
			printf("%d\t", arr[i]);
		}
		break;
	
	default:
		printf("invalid option............!");
	}
}
