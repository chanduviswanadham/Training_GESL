#include "Assignment_1_headder.h"

struct csll {

	int info;
	struct csll *clink;

};
struct csll *c_start = NULL;
struct csll *c_temp = NULL;
struct csll *c_p = NULL;

int count = 0;

int cir_single_linked()
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
	c_temp = (struct csll*)malloc(sizeof(struct csll));
	c_temp -> info = num;
	if (c_start == NULL) {
		c_start = c_temp;
		c_temp -> clink = c_start;
		count++;
	} else {
        c_p = c_start;
		c_temp -> clink = c_start;
		while(c_p -> clink != c_start) {
		    c_p = c_p -> clink;
		}
		c_p -> clink = c_temp;
		c_start = c_temp;
		count++;
	}
	free(c_temp);
}

void csll_i_end(int num)
{
	c_temp = (struct csll*)malloc(sizeof(struct csll));
	c_temp -> info = num;
	if (count == 0){
		csll_i_begin(num);
	} else if (c_start == c_start -> clink) {
		c_temp -> clink = c_start;
		c_start -> clink = c_temp;
		count++;
		free(c_temp);
	} else {
		c_p = c_start;
		while ( c_p -> clink != c_start) {
			c_p = c_p -> clink;
		}
		c_temp -> clink = c_start;
		c_p -> clink = c_temp;
		count++;
		free(c_temp);
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
		c_p = c_start;
		c_temp = (struct csll*)malloc(sizeof(struct csll));
		c_temp -> info = num;
		while (i < (pos - 1)) {
			c_p = c_p -> clink;
			i++;
		}
		c_temp -> clink = c_p -> clink;
		c_p -> clink = c_temp;
		count++;
	}
	free(c_temp);
}

void csll_i_bpos(int num, int pos)
{
	int i = 1;
	if (pos > count) {
		printf("the position is not available\n");
	} if (pos == 1) {
		csll_i_begin(num);
	} else {
		c_temp = (struct csll*)malloc(sizeof(struct csll));
		c_temp -> info = num;
		c_p = c_start;
		while (i < (pos - 1)) {
			c_p = c_p -> clink;
			i++;
		}
		c_temp -> clink = c_p -> clink;
		c_p -> clink = c_temp;
		count++;
		free(c_temp);
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
		c_temp = (struct csll*)malloc(sizeof(struct csll));
		c_temp -> info = num;
		c_p = c_start;
		while (i <= (pos - 1)) {
			c_p = c_p -> clink;
			i++;
		}
		c_temp -> clink = c_p -> clink;
		c_p -> clink = c_temp;
		count++;
		free(c_temp);
	}
}

void csll_i_bnum(int num, int val)
{
	int i = 1;
	c_temp = (struct csll*)malloc(sizeof(struct csll));
	c_temp -> info = num;
	if (count == 0) {
		printf("list is empty your num is not there..!\n");
	} else if (c_start -> info == val) {
		csll_i_begin(num);
	} else {
		c_p = c_start;
		while(i < count) {
			if (c_p -> clink -> info == val) {
				c_temp -> clink = c_p -> clink;
				c_p -> clink = c_temp;
				count++;
				break;
			}
			i++;
			c_p = c_p -> clink;
		}
		if (i >= count) {
			printf("the number is not present...!\n");
		}
	}
	free(c_temp);
}

void csll_i_anum(int num, int val)
{
	int i = 1;
	c_temp = (struct csll*)malloc(sizeof(struct csll));
	c_temp -> info = num;
	if (count == 0) {
		printf("list is empty your num is not there..!\n");
	} else if (c_start -> info == val) {
		csll_i_end(num);
	} else {
		c_p = c_start;
		while(i < count) {
			if (c_p -> clink -> info == val) {
				c_p = c_p -> clink;
				c_temp -> clink = c_p -> clink;
				c_p -> clink = c_temp;
				count++;
				break;
			}
			i++;
			c_p = c_p -> clink;
		}
		if (i >= count) {
			printf("the number is not present...!\n");
		}
	}
	free(c_temp);
}
 
void csll_i_mid(int num)
{	
	if (count%2 == 0) {
		csll_i_pos(num, (count/2 + 1));
	} else {
	    csll_i_pos(num, count/2);
	}
}

void csll_i_pend(int num)
{
	csll_i_pos(num, (count-1));
}
		
void csll_d_begin()
{
	if (count == 0) {
		printf("list is empty......!\n");
	} else {
		printf("the deleted element:%d \n", (c_start -> info));
        c_p = c_start;
        while(c_p -> clink != c_start) {
            c_p = c_p -> clink;
        }
		c_start = c_start -> clink;
		c_p -> clink = c_start;
		count--;
	}		
}

void csll_d_end() {
	
	if (count == 0) {
		printf("list is empty......!\n");
	} else if (count == 1) {
		printf("the deleted element:%d \n", (c_start -> info));
		c_start = NULL;
		count--;
	} else {
		c_p = c_start;
		while (c_p -> clink ->clink != c_start) {
			c_p = c_p -> clink;
		}
		printf("the deleted element:%d \n", (c_p ->clink -> info));
		c_p -> clink = c_start;
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
			csll_d_begin();
	} else {
		int i = 1;
		c_p = c_start;
		while (i < (pos - 1)) {
			c_p = c_p -> clink;
			i++;
		}
		c_p -> clink = c_p -> clink -> clink;
		count--;
	}
}
//deletion after number and before number

void csll_d_bnum(int val)
{
	int i = 1;
	if (count == 0) {
		printf("list is empty...!\n");
	} else if (c_start -> info == val) {
		printf("no number is before that....!\n");
	} else {
		c_p = c_start;
		while(i < count) {
			if (c_p -> clink -> info == val) {
				c_p -> clink = c_p -> clink -> clink;
				count--;
				break;
			}
			i++;
			c_p = c_p -> clink;
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
	} else if (c_start -> info == val) {
		c_start -> clink = c_start -> clink -> clink;
		count--;
	} else {
		int i = 1;
		c_p = c_start;
		while(i < count) {
			if ((c_p -> clink -> info == val) && (c_p -> clink -> clink != c_start)) {
				c_p = c_p -> clink;
				c_p -> clink = c_p -> clink -> clink;
				count--;
				break;
			}
			i++;
			c_p = c_p -> clink;
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
	csll_d_pos(count - 1);
}


void csll_display()
{
	if(count == 0) {
		printf("no elements in the list\n");
	} else {
		c_p = c_start;
		printf("single circular linked list is:\n");
		while (c_p -> clink != c_start) {
			printf("%d\t", c_p -> info);
			c_p = c_p -> clink;
		}
		printf("%d", c_p -> info);
	}
}
