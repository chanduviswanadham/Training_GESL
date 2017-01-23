#include "Assignment_1_headder.h"

struct sll {

	int info;
	struct sll *link;

};
struct sll *sll_start = NULL;
struct sll *sll_temp = NULL;
struct sll *sll_p = NULL;

int sll_count = 0;

int single_linked(void)
{
	int ch;
	
	do {
		
		printf("\n1.insert\n2.delete\n3.display\n0.exit\nenter your option:\n");
		scanf("%d", &ch);
		
		switch (ch) {

		case 0:
			break;

		case 1:
			sll_insert();
			break;

		case 2:
			sll_deletion();
			break;

		case 3:
			sll_display();
			break;

		default:
			printf("invalid option.........\n");
		}
	} while (ch != 0);

	return 0;
}

void sll_insert()
{
	int ch;
	int num;
	int val;
	int sll_pos;

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
		sll_i_begin(num);
		break;
	
	case 2:
		sll_i_end(num);
		break;
	
	case 3:
		printf("enter the position:\n");
		scanf("%d", &sll_pos);
		sll_i_pos(num, sll_pos);
		break;
	
	case 4:
		printf("enter the position:\n");
		scanf("%d", &sll_pos);
		sll_i_bpos(num, sll_pos);
		break;
	
	case 5:
		printf("enter the position:\n");
		scanf("%d", &sll_pos);
		sll_i_apos(num, sll_pos);
		break;
	
	case 6:
		printf("enter the number where insertion before that number :\n");
		scanf("%d", &val);
		sll_i_bnum(num, val);
		break;
	
	case 7:
		printf("enter the number where insertion after that number :\n");
		scanf("%d", &val);
		sll_i_anum(num, val);
		break;
	
	case 8:
		sll_i_mid(num);
		break;
	
	case 9:
		sll_i_pend(num);
		break;
	
	default:
		printf("invalid option......!\n");
		break;
	}
}

void sll_deletion()
{
	int ch;
	int sll_pos;
	int val;

	printf("1.Delete at the beginning\n2.delete at the end\n3.Deletion  at"
			"a given position\n4.Deletion before a given position\n5.Deletion"
			" after a given position\n6.Deletion before a given number\n"
			"7.Deletion after a given number\n8.Deletion at the middle\n9."
			"Deletion at penultimate node\n");
	scanf("%d", &ch);

	switch (ch) {

	case 1:
		sll_d_begin();
		break;
	
	case 2:
		sll_d_end();
		break;
	
	case 3:
		printf("enter the position:\n");
		scanf("%d", &sll_pos);
		sll_d_pos(sll_pos);
		break;
	
	case 4:
		printf("enter the position:\n");
		scanf("%d", &sll_pos);
		sll_d_pos(sll_pos - 1);
		break;
	
	case 5:
		printf("enter the position:\n");
		scanf("%d", &sll_pos);
		sll_d_pos(sll_pos + 1);
		break;
	
	case 6:
		printf("enter the number where deletion before that number :\n");
		scanf("%d", &val);
		sll_d_bnum(val);
		break;
	
	case 7:
		printf("enter the number where deletion after that number :\n");
		scanf("%d", &val);
		sll_d_anum(val);
		break;
	
	case 8:
		sll_d_mid();
		break;
	
	case 9:
		sll_d_pend();
		break;
	
	default:
		printf("invalid option......!\n");
		break;
	}


}

void sll_i_begin(int num)
{
	sll_temp = (struct sll*)malloc(sizeof(struct sll));
	sll_temp -> info = num;
	if (sll_start == NULL) {
		sll_temp -> link = NULL;
		sll_start = sll_temp;
		sll_count++;
	} else {
		sll_temp -> link = sll_start;
		sll_start = sll_temp;
		sll_count++;
	}
}

void sll_i_end(int num)
{
	sll_temp = (struct sll*)malloc(sizeof(struct sll));
	sll_temp -> info = num;
	if (sll_start == NULL) {
		sll_temp -> link = NULL;
		sll_start = sll_temp;
		sll_count++;
	} else {
		sll_p = sll_start;
		while ( sll_p -> link != '\0') {
			sll_p = sll_p -> link;
		}
		sll_temp -> link = NULL;
		sll_p -> link = sll_temp;
		sll_count++;
	}
}

void sll_i_pos(int num, int sll_pos)
{
	int i = 1;
	if (sll_pos > (sll_count + 1)) {
		printf("the position is not available\n");
	} else if (sll_pos == 1) {
		sll_i_begin(num);
	} else {
		sll_p = sll_start;
		sll_temp = (struct sll*)malloc(sizeof(struct sll));
		sll_temp -> info = num;
		while (i < (sll_pos - 1)) {
			sll_p = sll_p -> link;
			i++;
		}
		sll_temp -> link = sll_p -> link;
		sll_p -> link = sll_temp;
		sll_count++;
	}
}

void sll_i_bpos(int num, int sll_pos)
{
	int i = 1;
	if (sll_pos > sll_count) {
		printf("the position is not available\n");
	} if (sll_pos == 1) {
		sll_i_begin(num);
	} else {
		sll_temp = (struct sll*)malloc(sizeof(struct sll));
		sll_temp -> info = num;
		sll_p = sll_start;
		while (i < (sll_pos - 1)) {
			sll_p = sll_p -> link;
			i++;
		}
		sll_temp -> link = sll_p -> link;
		sll_p -> link = sll_temp;
		sll_count++;
	}
}

void sll_i_apos(int num,int sll_pos)
{
	int i = 1;
	if (sll_pos > (sll_count + 1)) {
		printf("the position is not available\n");
	} if (sll_pos == 0) {
		sll_i_begin(num);
	} else {
		sll_temp = (struct sll*)malloc(sizeof(struct sll));
		sll_temp -> info = num;
		sll_p = sll_start;
		while (i <= (sll_pos - 1)) {
			sll_p = sll_p -> link;
			i++;
		}
		sll_temp -> link = sll_p -> link;
		sll_p -> link = sll_temp;
		sll_count++;
	}
}

void sll_i_bnum(int num, int val)
{
	int i = 1;
	sll_temp = (struct sll*)malloc(sizeof(struct sll));
	sll_temp -> info = num;
	if (sll_count == 0) {
		printf("list is empty your num is not there..!\n");
	} else if (sll_start -> info == val) {
		sll_temp -> link = sll_start;
		sll_start = sll_temp;
		sll_count++;
	} else {
		sll_p = sll_start;
		while(i < sll_count) {
			if (sll_p -> link -> info == val) {
				sll_temp -> link = sll_p -> link;
				sll_p -> link = sll_temp;
				sll_count++;
				break;
			}
			i++;
			sll_p = sll_p -> link;
		}
		if (i >= sll_count) {
			printf("the number is not sll_present...!\n");
		}
	}
}

void sll_i_anum(int num, int val)
{
	int i = 1;
	sll_temp = (struct sll*)malloc(sizeof(struct sll));
	sll_temp -> info = num;
	if (sll_count == 0) {
		printf("list is empty your num is not there..!\n");
	} else if (sll_start -> info == val) {
		sll_temp -> link = sll_start -> link;
		sll_start -> link = sll_temp;
		sll_count++;
	} else {
		sll_p = sll_start;
		while(i < sll_count) {
			if (sll_p -> link -> info == val) {
				sll_p = sll_p -> link;
				sll_temp -> link = sll_p -> link;
				sll_p -> link = sll_temp;
				sll_count++;
				break;
			}
			i++;
			sll_p = sll_p -> link;
		}
		if (i >= sll_count) {
			printf("the number is not sll_present...!\n");
		}
	}
}
 
void sll_i_mid(int num)
{
	int i = 1;
	
	sll_temp = (struct sll*)malloc(sizeof(struct sll));
	sll_temp -> info = num;
	
	if (sll_count%2 == 0) {
		sll_p = sll_start;
		while (i <= (sll_count/2)) {
			sll_p = sll_p -> link;
			i++;
		}
		sll_temp -> link = sll_p -> link;
		sll_p -> link = sll_temp;
		sll_count++;
	} else {
		sll_p = sll_start;
		while (i < (sll_count/2)) {
			sll_p = sll_p -> link;
			i++;
		}
		sll_temp -> link = sll_p -> link;
		sll_p -> link = sll_temp;
		sll_count++;
	}
}

void sll_i_pend(int num)
{
	sll_temp = (struct sll*)malloc(sizeof(struct sll));
	sll_temp -> info = num;
	if(sll_count == 0) {
		printf("list is empty\n");
	} else if (sll_count == 1) {
		sll_temp -> link = sll_start;
		sll_start = sll_temp;
		sll_count++;
	} else {
		sll_p =  sll_start;
		while ((sll_p -> link -> link) != NULL) {
			sll_p = sll_p -> link;
		}
		sll_temp -> link = sll_p -> link;
		sll_p -> link = sll_temp;
		sll_count++;
	}
}
		
void sll_d_begin()
{
	if (sll_count == 0) {
		printf("list is empty......!\n");
	} else {
		printf("the deleted element:%d \n", (sll_start -> info));
		sll_start = sll_start -> link;
		sll_count--;
	}		
}

void sll_d_end() {
	
	if (sll_count == 0) {
		printf("list is empty......!\n");
	} else if (sll_count == 1) {
		printf("the deleted element:%d \n", (sll_start -> info));
		sll_start = NULL;
		sll_count--;
	} else {
		sll_p = sll_start;
		while (sll_p -> link ->link != '\0') {
			sll_p = sll_p -> link;
		}
		printf("the deleted element:%d \n", (sll_p ->link -> info));
		sll_p -> link = NULL;
		sll_count--;
	}
}

void sll_d_pos(int sll_pos)
{
	if (sll_count == 0) {
		printf("list is empty......!\n");
	} else if (sll_pos > sll_count) {
		printf("it is not sll_possble...!");
	} else if (sll_pos == 1) {
			printf("the deleted element:%d\n", sll_start -> info);
			sll_start = sll_start -> link;
			sll_count--;
	} else {
		int i = 1;
		sll_p = sll_start;
		while (i < (sll_pos - 1)) {
			sll_p = sll_p -> link;
			i++;
		}
		sll_p -> link = sll_p -> link -> link;
		sll_count--;
	}
}
//deletion after number and before number

void sll_d_bnum(int val)
{
	int i = 1;
	if (sll_count == 0) {
		printf("list is empty...!\n");
	} else if (sll_start -> info == val) {
		printf("no number is before that....!\n");
	} else {
		sll_p = sll_start;
		while(i < sll_count) {
			if (sll_p -> link -> info == val) {
				sll_p -> link = sll_p -> link -> link;
				sll_count--;
				break;
			}
			i++;
			sll_p = sll_p -> link;
		}
		if (i >= sll_count) {
			printf("the number is not sll_present...!\n");
		}
	}
}

void sll_d_anum(int val)
{
	if (sll_count == 0) {
		printf("list is empty your num is not there..!\n");
	} else if (sll_start -> info == val) {
		sll_start -> link = sll_start -> link -> link;
		sll_count--;
	} else {
		int i = 1;
		sll_p = sll_start;
		while(i < sll_count) {
			if ((sll_p -> link -> info == val) && (sll_p -> link -> link != NULL)) {
				sll_p = sll_p -> link;
				sll_p -> link = sll_p -> link -> link;
				sll_count--;
				break;
			}
			i++;
			sll_p = sll_p -> link;
		}
		if (i >= sll_count) {
			printf("invalid number...!\n");
		}
	}
}
 
void sll_d_mid()
{
	if (sll_count == 0) {
		printf("list is empty......!\n");
	} else if (sll_count%2 == 0) {
		sll_d_pos(sll_count/2);
	} else {
		sll_d_pos((sll_count/2) + 1);
	}
}

void sll_d_pend(int num)
{
	if(sll_count == 0) {
		printf("list is empty\n");
	} else if (sll_count == 1) {
		printf("in list there is only one element....!\n");
	} else {
		sll_p =  sll_start;
		while ((sll_p -> link -> link) != NULL) {
			sll_p = sll_p -> link;
		}
		sll_p -> link = NULL;
		sll_count--;
	}
}


void sll_display()
{
	if(sll_count == 0) {
		printf("no elements in the list\n");
	} else {
		sll_p = sll_start;
		printf("single linked list is:\n");
		while (sll_p -> link != '\0') {
			printf("%d\t", sll_p -> info);
			sll_p = sll_p -> link;
		}
		printf("%d", sll_p -> info);
	}
}
