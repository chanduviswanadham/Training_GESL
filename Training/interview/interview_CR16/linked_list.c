#include <stdio.h>
#include <stdlib.h>

struct list {
	int info;
	struct list *next;
};

void display( struct list * );

void insert(struct list *, int);

int main(void)
{
	struct list *root = NULL;
	int num;
	int op;

	root = (struct list*) malloc(sizeof(struct list));

	while(1) {

		printf("Enter 1 for insertion 2 for display");
		scanf("%d", &op);

		switch(op) {
			case 1: 
				printf("Enter the elemnt to insert\n");
				scanf("%d", &num);
				insert(root, num);
			break;
		case 2:
			display(root);
			break;
		case 3:
			exit(1);
	}
	}

	return 0;
}

void insert(struct list *node, int num)
{
	struct list *temp = NULL;

	temp = (struct list *) malloc(sizeof(struct list));

	temp -> info = num;
	temp -> next = node;
	node = temp;
//	temp = NULL;
//	free(temp);
//	return node;
}	

void display( struct list *node )
{
	struct list *p = node;

	while( p -> next != NULL ) {
		printf("%d\n", p -> info);
		p = p -> next;
	}

}
	
