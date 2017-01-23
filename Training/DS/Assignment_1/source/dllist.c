#include "Assignment_1_headder.h"

struct dll {

	int info;
	struct dll *dll_llink;
	struct dll *dll_rlink;

};
struct dll *dll_start = NULL;
struct dll *dll_temp = NULL;
struct dll *dll_p = NULL;

int dll_count = 0;

int double_linked(void)
{
	int ch;
	
	do {

		printf("\n*************Double Linked List**************\n");
		printf("\n1.insert\n2.delete\n3.display\n0.exit\nenter your option:\n");
		scanf("%d", &ch);
		
		switch (ch) {

		case 0:
			break;

		case 1:
			dll_insert();
			break;

		case 2:
			dll_deletion();
			break;

		case 3:
			dll_display();
			break;

		default:
			printf("invalid option.........\n");
		}
	} while (ch != 0);

	return 0;
}

void dll_insert()
{
	int ch;
	int num;
	int val;
	int dll_pos;

	printf("\n**********MENU**********\n");
	printf("\n1.Insert at the beginning\n2.Insert at the end\n3. Insert at"
			"a given position\n4.Insert before a given position\n5.Insert"
			" after a given position\n6.Insert before a given number\n"
			"7.Insert after a given number\n8. Insert at the middle\n9."
			"Insert at penultimate node\n");
	scanf("%d", &ch);
	printf("enter the element need to insert:\n");
	scanf("%d", &num);

	switch (ch) {

	case 1:
		dll_i_begin(num);
		break;
	
	case 2:
		dll_i_end(num);
		break;
	
	case 3:
		printf("enter the position:\n");
		scanf("%d", &dll_pos);
		dll_i_pos(num, dll_pos);
		break;
	
	case 4:
		printf("enter the position:\n");
		scanf("%d", &dll_pos);
		if (dll_pos <= dll_count) {
			dll_i_pos(num, (dll_pos - 1));
		} else {
			printf("it is not possible......!\n");
		}
		break;
	
	case 5:
		printf("enter the position:\n");
		scanf("%d", &dll_pos);
		if (dll_pos <= dll_count) {
			dll_i_pos(num, (dll_pos + 1));
		} else {
			printf("it is not possible......!\n");
		}
		break;
	
	case 6:
		printf("enter the number where insertion before that number :\n");
		scanf("%d", &val);
		dll_i_bnum(num, val);
		break;
	
	case 7:
		printf("enter the number where insertion after that number :\n");
		scanf("%d", &val);
		dll_i_anum(num, val);
		break;
	
	case 8:
		dll_i_mid(num);
		break;
	
	case 9:
		dll_i_pend(num);
		break;
	
	default:
		printf("invalid option......!\n");
		break;
	}
}

void dll_deletion()
{
	int ch;
	int dll_pos;
	int val;

	printf("\n1.Delete at the beginning\n2.delete at the end\n3.Deletion  at"
			"a given position\n4.Deletion before a given position\n5.Deletion"
			" after a given position\n6.Deletion before a given number\n"
			"7.Deletion after a given number\n8.Deletion at the middle\n9."
			"Deletion at penultimate node\n");
	scanf("%d", &ch);

	switch (ch) {

	case 1:
		dll_d_begin();
		break;
	
	case 2:
		dll_d_end();
		break;
	
	case 3:
		printf("enter the position:\n");
		scanf("%d", &dll_pos);
		dll_d_pos(dll_pos);
		break;
	
	case 4:
		printf("enter the position:\n");
		scanf("%d", &dll_pos);
		dll_d_pos((dll_pos - 1));
		break;
	
	case 5:
		printf("enter the position:\n");
		scanf("%d", &dll_pos);
		dll_d_pos((dll_pos + 1));
		break;
	
	case 6:
		printf("enter the number where deletion before that number :\n");
		scanf("%d", &val);
		dll_d_bnum(val);
		break;
	
	case 7:
		printf("enter the number where deletion after that number :\n");
		scanf("%d", &val);
		dll_d_anum(val);
		break;
	
	case 8:
		dll_d_mid();
		break;
	
	case 9:
		dll_d_pend();
		break;
	
	default:
		printf("invalid option......!\n");
		break;
	}


}

void dll_i_begin(int num)
{
	dll_temp = (struct dll*)malloc(sizeof(struct dll));
	dll_temp -> info = num;
	
	dll_temp -> dll_rlink = dll_start;
	dll_temp -> dll_llink = NULL;
	dll_start = dll_temp;
	dll_count++;
}

void dll_i_end(int num)
{
	dll_p = dll_start;
	
	if (dll_start == NULL) {
	
		dll_i_begin(num);
	
	} else {
		
		dll_i_pos(num, dll_count+1);
	
	}
}

void dll_i_pos(int num, int dll_pos)
{
	int i = 1;
	
	if (dll_pos == 1) {
		
		dll_i_begin(num);
	
	} else {
		
		dll_p = dll_start;
		dll_temp = (struct dll*)malloc(sizeof(struct dll));
		dll_temp -> info = num;
		
		while (i < (dll_pos - 1)) {
			dll_p = dll_p -> dll_rlink;
			i++;
		}
		
		dll_temp -> dll_llink = dll_p;
		dll_temp -> dll_rlink = dll_p -> dll_rlink;
		
		if (dll_pos != (dll_count + 1)) {
		
			dll_p -> dll_rlink -> dll_llink = dll_temp;
		
		}
		
		dll_p -> dll_rlink = dll_temp;
		dll_count++;
	}
}

void dll_i_bnum(int num, int val)
{
	int i = 1;
	if (dll_count == 0) {
		printf("list is empty your num is not there..!\n");
	} else if (dll_start -> info == val) {
		dll_i_begin(num);
	} else {
		dll_p = dll_start;
		while(i <= dll_count) {
			if (dll_p -> info == val) {
				dll_i_pos(num, (i - 1));
				break;
			}
			i++;
			dll_p = dll_p -> dll_rlink;
		}
		if (i > dll_count) {
			printf("the number is not present...!\n");
		}
	}
}

void dll_i_anum(int num, int val)
{
	int i = 1;
	
	if (dll_count == 0) {
		printf("list is empty your num is not there..!\n");
	} else {
		dll_p = dll_start;
		while(i <= dll_count) {
			if (dll_p -> info == val) {
				dll_i_pos(num, (i + 1));
				break;
			}
			i++;
			dll_p = dll_p -> dll_rlink;
		}
		if (i > dll_count) {
			printf("the number is not present...!\n");
		}
	}
}
 
void dll_i_mid(int num)
{
	if (dll_count%2 == 0) {
		dll_i_pos(num, dll_count/2);
	} else {
		dll_i_pos(num, (dll_count/2 + 1));	
	}
}

void dll_i_pend(int num)
{
	dll_temp = (struct dll*)malloc(sizeof(struct dll));
	dll_temp -> info = num;
	if(dll_count == 0) {
		printf("list is empty\n");
	} else if (dll_count == 1) {
		dll_i_begin(num);
	} else {
		dll_i_pos(num, dll_count);
	}
}

// deletion of double linked lists

void dll_d_begin()
{
	if (dll_count == 0) {
		
		printf("list is empty......!\n");
	
	} else {
		
		printf("the deleted element:%d \n", (dll_start -> info));
		dll_start = dll_start -> dll_rlink;
		dll_count--;
	}		
}


void dll_d_end() {
	
	if (dll_count == 0) {
		
		printf("list is empty......!\n");
	
	} else if (dll_count == 1) {
		
		printf("the deleted element:%d \n", (dll_start -> info));
		dll_start = NULL;
		dll_count--;
	
	} else {
		dll_p = dll_start;
		
		while (dll_p -> dll_rlink != '\0') {
			dll_p = dll_p -> dll_rlink;
		}
		
		printf("the deleted element:%d \n", (dll_p -> info));
		dll_p -> dll_llink -> dll_rlink = NULL;
		dll_count--;
	}
}

void dll_d_pos(int dll_pos)
{
	if (dll_count == 0) {
		
		printf("list is empty......!\n");
	
	} else if (dll_pos > dll_count) {
		
		printf("it is not possble...!");
	
	} else if (dll_pos == 1) {
	
		dll_d_begin();
	
	} else if (dll_pos == dll_count){ 
		
		dll_d_end();
	
	}else {
		
		int i = 1;
		dll_p = dll_start;
		
		while (i < dll_pos) {
			dll_p = dll_p -> dll_rlink;
			i++;
		}
		
		dll_p -> dll_llink -> dll_rlink = dll_p -> dll_rlink;
		dll_p -> dll_rlink -> dll_llink = dll_p -> dll_llink;
		dll_count--;
	}
}
//deletion after number and before number

void dll_d_bnum(int val)
{
	int i = 1;
	if (dll_count == 0) {
		
		printf("list is empty...!\n");
	
	} else if (dll_start -> info == val) {
		
		printf("no number is before that....!\n");
	
	} else {
		
		dll_p = dll_start;
		while(i <= dll_count) {
			
			if (dll_p -> info == val) {
				dll_d_pos(i - 1);
				break;
			}
			
			i++;
			dll_p = dll_p -> dll_rlink;
		
		}
		
		if (i > dll_count) {
			
			printf("the number is not resent...!\n");
		
		}
	}
}

void dll_d_anum(int val)
{
	if (dll_count == 0) {
		
		printf("list is empty your num is not there..!\n");
	
	} else if (dll_start -> info == val) {
		
		dll_d_pos(2);
	
	} else {
		
		int i = 1;
		dll_p = dll_start;
		while(i <= dll_count) {
			
			if (dll_p -> info == val) {
				dll_d_pos(i+1);
				break;
			}
			
			i++;
			dll_p = dll_p -> dll_rlink;
		
		}
		if (i > dll_count) {
			
			printf("invalid number...!\n");
		}
	}
}
 
void dll_d_mid()
{
	if (dll_count == 0) {
		
		printf("list is emdty......!\n");
	
	} else if (dll_count%2 == 0) {
		
		dll_d_pos(dll_count/2);
	
	} else {
		
		dll_d_pos((dll_count/2) + 1);
	}
}

void dll_d_pend(int num)
{
	
	if (dll_count > 1) {
		
		dll_d_pos((dll_count - 1));
	
	} else {
		
		printf("there is no any penultimate for the list.....!!\n");
	
	}
}


void dll_display()
{
	if(dll_count == 0) {
		
		printf("no elements in the list\n");
	
	} else {
		
		dll_p = dll_start;
		printf("Double linked list is:\n");
		
		while (dll_p -> dll_rlink != '\0') {
			printf("%d\t", dll_p -> info);
			dll_p = dll_p -> dll_rlink;
		}
		
		printf("%d\t\n", dll_p -> info);
	}
}
