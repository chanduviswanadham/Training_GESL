#include "Assignment_1_headder.h"

struct ccsll {

	int info;
	struct csll *link;

};
struct csll *last = NULL;
struct csll *temp = NULL;
struct csll *p = NULL;

int count = 0;

int main(void)
{
	int ch;
	
	do {
		
		printf("\n1.insert\n2.delete\n3.display\n0.exit\nenter your option:\n");
		scanf("%d", &ch);
		
		switch (ch) {

		case 0:
			break;

		case 1:
			csll_insert();
			break;

		case 2:
			csll_deletion();
			break;

		case 3:
			csll_display();
			break;

		default:
			printf("invalid option.........\n");
		}
	} while (ch != 0);

	return 0;
}

void csll_insert()
{
	int ch;
	int num;
	int val;
	int pos;

	printf("1.Insert at the beginning\n2.Insert at the end\n3. Insert at"
			"a given position\n4.Insert before a given position\n5.Insert"
			" after a given position\n6.Insert before a given number\n"
			"7.Insert after a given number\n8. Insert at the middle\n9."
			"Insert at penultimate node\n");
	scanf("%d", &ch);
	printf("enter the element need to insert:\n");
	scanf("%d", &num);

	switch (ch) {

	case 1:
		csll_i_begin(num);
		break;
	
	case 2:
		csll_i_end(num);
		break;
	
	case 3:
		printf("enter the position:\n");
		scanf("%d", &pos);
		csll_i_pos(num, pos);
		break;
	
	case 4:
		printf("enter the position:\n");
		scanf("%d", &pos);
		csll_i_bpos(num, pos);
		break;
	
	case 5:
		printf("enter the position:\n");
		scanf("%d", &pos);
		csll_i_apos(num, pos);
		break;
	
	case 6:
		printf("enter the number where insertion before that number :\n");
		scanf("%d", &val);
		csll_i_bnum(num, val);
		break;
	
	case 7:
		printf("enter the number where insertion after that number :\n");
		scanf("%d", &val);
		csll_i_anum(num, val);
		break;
	
	case 8:
		csll_i_mid(num);
		break;
	
	case 9:
		csll_i_pend(num);
		break;
	
	default:
		printf("invalid option......!\n");
		break;
	}
}

void csll_deletion()
{
	int ch;
	int pos;
	int val;

	printf("1.Delete at the beginning\n2.delete at the end\n3.Deletion  at"
			"a given position\n4.Deletion before a given position\n5.Deletion"
			" after a given position\n6.Deletion before a given number\n"
			"7.Deletion after a given number\n8.Deletion at the middle\n9."
			"Deletion at penultimate node\n");
	scanf("%d", &ch);

	switch (ch) {

	case 1:
		csll_d_begin();
		break;
	
	case 2:
		csll_d_end();
		break;
	
	case 3:
		printf("enter the position:\n");
		scanf("%d", &pos);
		csll_d_pos(pos);
		break;
	
	case 4:
		printf("enter the position:\n");
		scanf("%d", &pos);
		csll_d_pos(pos - 1);
		break;
	
	case 5:
		printf("enter the position:\n");
		scanf("%d", &pos);
		csll_d_pos(pos + 1);
		break;
	
	case 6:
		printf("enter the number where deletion before that number :\n");
		scanf("%d", &val);
		csll_d_bnum(val);
		break;
	
	case 7:
		printf("enter the number where deletion after that number :\n");
		scanf("%d", &val);
		csll_d_anum(val);
		break;
	
	case 8:
		csll_d_mid();
		break;
	
	case 9:
		csll_d_pend();
		break;
	
	default:
		printf("invalid option......!\n");
		break;
	}


}

void csll_i_begin(int num)
{
	temp = (struct csll*)malloc(sizeof(struct csll));
	temp -> info = num;
	if (last == NULL) {
		temp -> link = NULL;
		last = temp;
		count++;
	} else {
		temp -> link = last;
		last = temp;
		count++;
	}
}

void csll_i_end(int num)
{
	temp = (struct csll*)malloc(sizeof(struct csll));
	temp -> info = num;
	if (last == NULL) {
		temp -> link = NULL;
		last = temp;
		count++;
	} else {
		p = last;
		while ( p -> link != '\0') {
			p = p -> link;
		}
		temp -> link = NULL;
		p -> link = temp;
		count++;
	}
}

void csll_i_pos(int num, int pos)
{
	int i = 1;
	if (pos > (count + 1)) {
		printf("the position is not available\n");
	} else if (pos == 1) {
		csll_i_begin(num);
	} else {
		p = last;
		temp = (struct csll*)malloc(sizeof(struct csll));
		temp -> info = num;
		while (i < (pos - 1)) {
			p = p -> link;
			i++;
		}
		temp -> link = p -> link;
		p -> link = temp;
		count++;
	}
}

void csll_i_bpos(int num, int pos)
{
	int i = 1;
	if (pos > count) {
		printf("the position is not available\n");
	} if (pos == 1) {
		csll_i_begin(num);
	} else {
		temp = (struct csll*)malloc(sizeof(struct csll));
		temp -> info = num;
		p = last;
		while (i < (pos - 1)) {
			p = p -> link;
			i++;
		}
		temp -> link = p -> link;
		p -> link = temp;
		count++;
	}
}

void csll_i_apos(int num,int pos)
{
	int i = 1;
	if (pos > (count + 1)) {
		printf("the position is not available\n");
	} if (pos == 0) {
		csll_i_begin(num);
	} else {
		temp = (struct csll*)malloc(sizeof(struct csll));
		temp -> info = num;
		p = last;
		while (i <= (pos - 1)) {
			p = p -> link;
			i++;
		}
		temp -> link = p -> link;
		p -> link = temp;
		count++;
	}
}

void csll_i_bnum(int num, int val)
{
	int i = 1;
	temp = (struct csll*)malloc(sizeof(struct csll));
	temp -> info = num;
	if (count == 0) {
		printf("list is empty your num is not there..!\n");
	} else if (last -> info == val) {
		temp -> link = last;
		last = temp;
		count++;
	} else {
		p = last;
		while(i < count) {
			if (p -> link -> info == val) {
				temp -> link = p -> link;
				p -> link = temp;
				count++;
				break;
			}
			i++;
			p = p -> link;
		}
		if (i >= count) {
			printf("the number is not present...!\n");
		}
	}
}

void csll_i_anum(int num, int val)
{
	int i = 1;
	temp = (struct csll*)malloc(sizeof(struct csll));
	temp -> info = num;
	if (count == 0) {
		printf("list is empty your num is not there..!\n");
	} else if (last -> info == val) {
		temp -> link = last -> link;
		last -> link = temp;
		count++;
	} else {
		p = last;
		while(i < count) {
			if (p -> link -> info == val) {
				p = p -> link;
				temp -> link = p -> link;
				p -> link = temp;
				count++;
				break;
			}
			i++;
			p = p -> link;
		}
		if (i >= count) {
			printf("the number is not present...!\n");
		}
	}
}
 
void csll_i_mid(int num)
{
	int i = 1;
	
	temp = (struct csll*)malloc(sizeof(struct csll));
	temp -> info = num;
	
	if (count%2 == 0) {
		p = last;
		while (i <= (count/2)) {
			p = p -> link;
			i++;
		}
		temp -> link = p -> link;
		p -> link = temp;
		count++;
	} else {
		p = last;
		while (i < (count/2)) {
			p = p -> link;
			i++;
		}
		temp -> link = p -> link;
		p -> link = temp;
		count++;
	}
}

void csll_i_pend(int num)
{
	temp = (struct csll*)malloc(sizeof(struct csll));
	temp -> info = num;
	if(count == 0) {
		printf("list is empty\n");
	} else if (count == 1) {
		temp -> link = last;
		last = temp;
		count++;
	} else {
		p =  last;
		while ((p -> link -> link) != NULL) {
			p = p -> link;
		}
		temp -> link = p -> link;
		p -> link = temp;
		count++;
	}
}
		
void csll_d_begin()
{
	if (count == 0) {
		printf("list is empty......!\n");
	} else {
		printf("the deleted element:%d \n", (last -> info));
		last = last -> link;
		count--;
	}		
}

void csll_d_end() {
	
	if (count == 0) {
		printf("list is empty......!\n");
	} else if (count == 1) {
		printf("the deleted element:%d \n", (last -> info));
		last = NULL;
		count--;
	} else {
		p = last;
		while (p -> link ->link != '\0') {
			p = p -> link;
		}
		printf("the deleted element:%d \n", (p ->link -> info));
		p -> link = NULL;
		count--;
	}
}

void csll_d_pos(int pos)
{
	if (count == 0) {
		printf("list is empty......!\n");
	} else if (pos > count) {
		printf("it is not possble...!");
	} else if (pos == 1) {
			printf("the deleted element:%d\n", last -> info);
			last = last -> link;
			count--;
	} else {
		int i = 1;
		p = last;
		while (i < (pos - 1)) {
			p = p -> link;
			i++;
		}
		p -> link = p -> link -> link;
		count--;
	}
}
//deletion after number and before number

void csll_d_bnum(int val)
{
	int i = 1;
	if (count == 0) {
		printf("list is empty...!\n");
	} else if (last -> info == val) {
		printf("no number is before that....!\n");
	} else {
		p = last;
		while(i < count) {
			if (p -> link -> info == val) {
				p -> link = p -> link -> link;
				count--;
				break;
			}
			i++;
			p = p -> link;
		}
		if (i >= count) {
			printf("the number is not present...!\n");
		}
	}
}

void csll_d_anum(int val)
{
	if (count == 0) {
		printf("list is empty your num is not there..!\n");
	} else if (last -> info == val) {
		last -> link = last -> link -> link;
		count--;
	} else {
		int i = 1;
		p = last;
		while(i < count) {
			if ((p -> link -> info == val) && (p -> link -> link != NULL)) {
				p = p -> link;
				p -> link = p -> link -> link;
				count--;
				break;
			}
			i++;
			p = p -> link;
		}
		if (i >= count) {
			printf("invalid number...!\n");
		}
	}
}
 
void csll_d_mid()
{
	if (count == 0) {
		printf("list is empty......!\n");
	} else if (count%2 == 0) {
		csll_d_pos(count/2);
	} else {
		csll_d_pos((count/2) + 1);
	}
}

void csll_d_pend(int num)
{
	if(count == 0) {
		printf("list is empty\n");
	} else if (count == 1) {
		printf("in list there is only one element....!\n");
	} else {
		p =  last;
		while ((p -> link -> link) != NULL) {
			p = p -> link;
		}
		p -> link = NULL;
		count--;
	}
}


void csll_display()
{
	if(count == 0) {
		printf("no elements in the list\n");
	} else {
		p = last;
		printf("single linked list is:\n");
		while (p -> link != '\0') {
			printf("%d\t", p -> info);
			p = p -> link;
		}
		printf("%d", p -> info);
	}
}
