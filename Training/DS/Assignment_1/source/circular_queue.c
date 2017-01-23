#include "Assignment_1_headder.h"
#define CQMAX 6

int arr[CQMAX];
int cqsize = 0;
int cqfront = -1;
int cqrear = -1;

int c_queue()
{
	
	int ch;
	int num;
	
	
	do {
		
		printf("\n1.enqueue\n2.dequeue\n3.display\n0.exit\nenter your choice:\n");
		scanf("%d", &ch);

		switch (ch) {
			
		case 0:
			break;

		case 1:
			printf("enter the element need to insert in the circular queue\n");
			scanf("%d", &num);
			c_enqueue(num);
			break;

		case 2:
			c_dequeue();
			break;

		case 3:
			c_display();
			break;

		default:
			printf("enter the valid option\n");
			break;
		}
	} while (ch != 0);
	
	return 0;
}

void c_enqueue(int num)
{
	if (cqsize == CQMAX) {
		printf("QUEUE IS FULL\n");
	} else if (cqfront == -1) {
		cqfront++;
		cqrear++;
		arr[cqrear] = num;
		cqsize++;
	} else {
		
		if ( cqrear == (CQMAX -1)) {
			cqrear = -1;
		}
		cqrear++;
		arr[cqrear] = num;
		cqsize++;
	}
}

void c_dequeue()
{
	if ( cqsize == 0) {
		printf("QUEUE IS EMPTY\n");
	} else {
		if ( cqfront == (CQMAX - 1)) {
			cqfront = 0;
		}
		printf("deleted element in the circular queue is : %d \n", arr[cqfront]);
		cqfront ++;
		cqsize--;
		if (cqsize == 0) {
			cqfront = -1;
			cqrear = -1;
		}
	}
}

void c_display()
{
	int i;
	if (cqsize == 0) {
		printf("QUEUE IS EMPTY\n");
	} else {
		i = cqfront;
		if (cqfront <= cqrear) {
			while (i <= cqrear) {
				printf("%d ", arr[i]);
				i++;
			}
		} else {
			while (i <= (CQMAX -1)) {
				printf("%d ", arr[i]);
				i++;
			}
			i = 0;
			while (i <= cqrear) {
				printf("%d ", arr[i]);
				i++;
			}
		}
	}
}
