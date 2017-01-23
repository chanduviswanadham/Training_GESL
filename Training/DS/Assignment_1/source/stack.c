#include "Assignment_1_headder.h"

int top = -1;
int size = 10;
int arr[10];

int stack(void)
{
	int num;
	int ch;
	
	do {
		printf("\n1.push the elements\n2.pop the element\n3.display stack\n"
				"0.come to out of the program\n");
		scanf("%d", &ch);
		switch (ch) {

		case 1:
			printf("enter the number need to insert:\n");
			scanf("%d", &num);
			my_push(num);
			break;
		
		case 2:
			my_pop();
			break;

		case 3:
			my_display();
			break;

		default:
			printf("enter the valid option from the above list\n");

		}
	} while (ch != 0);
}

