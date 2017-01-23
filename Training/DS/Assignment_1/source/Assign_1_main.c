#include "Assignment_1_headder.h"

int main(void)
{
	int ch;
	
	do {	
		printf("\n**************************MENU*************************\n");
		printf("\n1.stack\n2.queue\n3.circular queue\n\n4.single linked list\n"
			"5.double linked list\n6.circular Single linked list\n"
			"\n0.EXIT\nenter the option:\n");
		scanf("%d", &ch);
		
		switch (ch) {
		
		case 0:
			break;
		
		case 1:
			stack();
			break;
		
		case 2:
			queue();
			break;
		
		case 3:
			c_queue();
			break;
		
		case 4:
			single_linked();
			break;
		
		case 5:
			double_linked();
			break;
		case 6:
			cir_single_linked();	
			break;
		default:
			printf("invalid option..............!\n");
			
		}
	}while (ch != 0);
	return 0;
}
