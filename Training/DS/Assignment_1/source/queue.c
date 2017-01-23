#include "Assignment_1_headder.h"
#define QMAX 5

int arr[QMAX];
int qfront = -1;
int qrear = -1;
int qsize = QMAX;
int queue(void)
{
	
	int ch;
	int num;
	
	do {
	
		printf("1.enqueue\n2.de-queue\n3.display\n0.exit\n");
		scanf("%d", &ch);

		switch (ch) {
			
			case 0:
				break;

			case 1:
				printf("enter the element need to enter:\n");
				scanf("%d", &num);
				enqueue(num);
				break;

			case 2:
				dequeue();
				break;

			case 3:
				display();
				break;

			default:
				printf("enter the valid option\n");
				break;
		}
	} while (ch != 0);

	return 0;
}

void enqueue(int num)
{
	if (qrear == (qsize - 1)) {
		printf("queue is full\n");
	} else if (qfront = -1) {
		qrear++;
		arr[qrear] = num;
		qfront++;	
	} else {
		qrear++;
		arr[qrear] =num;
	}
}

void dequeue()
{
	if ((qfront ==  -1) && (qrear = -1)) {
		printf("queue is empty\n");
	} else if (qfront > qrear) {
		printf("queue is empty\n");
		qfront = -1;
		qrear = -1;
	} else {
		printf("the deleted element in the queue:%d\n", arr[qfront]);
		qfront++;
	}
}

void display()
{
	int i = 0;
	if( qfornt == -1) {
		printf("queue is empty\n");
	} else {
		printf("the elements present in the queue:\n");
		for (i = qfront; i <= qrear; i++) {
			printf("%d ", arr[i]);
		}
	}
}
		

