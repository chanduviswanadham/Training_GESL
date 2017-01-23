#include <stdio.h>
#include <stdlib.h>

struct binary {
	int info;
	struct binary *lchild;
	struct binary *rchild;
};
struct binary *root = NULL;
struct binary *insert(int, struct binary *);
struct binary *delete(int, struct binary *);
struct binary * node(int);
int display();
void in_order(struct binary *);
void pre_order(struct binary *);
void post_order(struct binary *);
void level_order(struct binary *);
int count = 0;
int level = 0;

int main() 
{
	int ch = 0;
	int num = 0;

	do {
		printf("1.insert binary tree\n2.deletion in BST\n3.display\n0.EXIT\nenter the choice:\n");
		scanf("%d", &ch);
		
		switch (ch) {
			
		case 0:
			break;
		
		case 1:
			printf("enter the value need to insert:\n");
			scanf("%d", &num);
			root = insert(num, root);
			break;
		
		case 2:
			printf("enter the value need to delete:\n");
			scanf("%d", &num);
			root = delete(num, root);
			break;
		
		case 3:
			display();
			break;

		default:	
			printf("enter the valid option..........!");
		}
	} while(ch != 0);

	return 0;
}

struct binary * node(int num) {	
	struct binary *temp = NULL;
	temp = (struct binary *)malloc(sizeof(struct binary));
	temp -> lchild = NULL;
	temp -> rchild = NULL;
	temp -> info = num;
	count++;
	return temp;
}

struct binary *insert(int num, struct binary *p)
{
	if (p == NULL) {
		return node(num);
	} else if (num < p -> info) {	
			p -> lchild = insert(num, p -> lchild);
	} else if (num >= p -> info) {	
			p -> rchild = insert(num, p -> rchild);
	}
	return p;
}

int display()
{
	int choice = 0;

	do {	
		printf("\n1.pre-order method display\n2.in-order display method\n"
				"3.post-order display method\n4.level order display method"
				"\n0.EXIT\nenter the choice:\n");
		scanf("%d", &choice);

		switch (choice) {
			
		case 0:
			break;
		
		case 1:
			pre_order(root);
			break;

		case 2:
			in_order(root);
			break;

		case 3:
			post_order(root);
			break;
		
		case 4:
			level_order(root);
			break;

		default:
			printf("invalid option..................!\n");

		}
	} while (choice != 0);
	
	return 0;
}

void in_order(struct binary *p)
{
	if (p != NULL) {
		in_order(p -> lchild);
		printf("%d\t", p -> info);
		in_order(p -> rchild);
	}
}
void pre_order(struct binary *p)
{
	if (p != NULL) {
		printf("%d\t", p -> info);
		pre_order(p -> lchild);
		pre_order(p -> rchild);
	}
}
void post_order(struct binary *p)
{
	if (p != NULL) {
		post_order(p -> lchild);
		post_order(p -> rchild);
		printf("%d\t", p -> info);
	}
}

void level_order(struct binary *p)
{
	while (1) {
		if (p == NULL) 
			break;
		printf("%d", p -> info);
		level_order(p -> lchild);
		level_order(p -> rchild);
	}
}
struct binary *delete(int num, struct binary *p)
{
	struct binary *c = NULL;
	struct binary *t = NULL;

	if (p == NULL) {
		return NULL;
	} else if (p -> info > num) {
			p -> lchild = delete(num, p -> lchild);
	} else if (p -> info < num) {
			p -> rchild = delete(num, p -> rchild);
	} else if (p -> info == num) {
		if (p -> rchild == NULL && p -> lchild == NULL) {
			free (p);
			return NULL;
		} else if (p -> rchild != NULL && p -> lchild == NULL) {
			t = p -> rchild;
			free (p);
			return t;
		} else if (p -> rchild == NULL && p -> lchild != NULL) {
			t = p -> lchild;
			free (p);
			return t;
		} else if (p -> rchild != NULL && p -> lchild != NULL) {
				c = p -> rchild;	
				t = p -> rchild;
				while (t -> lchild ) {
				
					t = t -> lchild;
				}
				while (c -> lchild != t && c -> lchild != NULL) {
					c = c -> lchild;
				}
				p -> info = t -> info;
				if (c -> lchild) {
					c -> lchild = delete(t -> info, t);
				} else {
					p -> rchild = c -> rchild;
					free(c);
				}
		}
	} 
	return p;
}
	
		


