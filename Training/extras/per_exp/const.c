#include <stdio.h>
#include <stdlib.h>

char *str = "chanduviswanadham";
char *str1 = "chanduviswanadham";
const int a = 25;
const int b = 25;
int main()
{
//	char str1[7] = {"chandu"};
	pid_t pid;
	pid = fork();

	if( pid > 0) {
		wait();
		printf("i am in parent and the address of str and str1 is:%p\t%p\n", &str, &str1);
		printf("in parent a address is:%p and b address is:%p\n", &a, &b);
	} else if (pid == 0) {
		printf("i am in child and the address of str and str1 is:%p\t%p\n", &str, &str1);
		printf("in child a address is:%p and b address is:%p\n", &a, &b);
	} else {
		printf("fork failed...........!");
	}
	return 0;
}
