#include <stdio.h>
#include <stdlib.h>

// macro to get the pointer which pointer to staring address of the structure 

#define STARTOFF(type, member, addr) ((char *)addr - (char *)(&(((type *)0) -> member)))
struct link {
	struct link *next;
	struct link *prev;
};

//structure 
struct task {
	long state;
	int pid;
	int flags;
	int prio;
	unsigned char fpu_counter;
	struct link tasks;
	char rcu_read;
	int tgid;
	char comm[16];
	unsigned int rt_prio;
}initial = {.state = 55000, .pid = 150, .flags = 10, .prio = 54, .fpu_counter = 65};

int main()
{
	struct task *start_addr = (struct task*)STARTOFF(struct task, tasks, &(initial.tasks)); // which holds the return vlaue from the macro
	printf("%ld\n", start_addr -> state);
	printf("%d\n", start_addr -> pid);
	printf("%d\n", start_addr -> flags);
	printf("%d\n", start_addr -> prio);
	printf("%c\n", start_addr -> fpu_counter);
	
	return 0;
}
