#include "Assignment_1_headder.h"

extern int arr[MAX];
extern int top;
extern int size;

void my_push(int num)
{

	if (top == (size -1)) {
		printf("the stack is full\n");
	} else {
		top++;
		arr[top] = num;
	}
}
