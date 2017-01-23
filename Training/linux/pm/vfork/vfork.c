#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#if 1

//global data

int a = 20;

int main()
{
	int b = 40;		//stack data
	pid_t pid;
	int sd;	
	int *heap = NULL; 	
	heap = malloc(sizeof(int));
	*heap = 50;		//heap data

	if (0 == (sd = open("just.txt", O_RDWR | O_CREAT, 0666))) {	//opening the file
		printf("file open failed\n");
	}

	pid = vfork();	//creatin a process 
	
	if(pid > 0) {	//parent process

		write(sd,"Global Edge ", 12);	//writing string in to the file 
		close(sd);

		//printing the values of different sections

		printf("global value after vfork in parent:%d\t%p\n", a, &a);
		printf("stack value after vfork in parent:%d\t%p\n", b, &b);
		printf("heap value after vfork in parent:%d\t%p\n", *heap, &heap);

	} else if (pid == 0) {	//child process
		
		a = 25;		//modifing the global data
		b = 45;		//modifing the stack data
		*heap = 55;	//modifing the heap data
		
		write(sd, "Software Limited ", 16);		//writing string into the file
		close(sd);

		//printing the values of different sections

		printf("global value after vfork in child:%d\t%p\n", a, &a);
		printf("stack value after vfork in child:%d\t%p\n", b, &b);
		printf("heap value after vfork in child:%d\t%p\n", *heap, &heap);
		exit(0);
	
	} else {	//validation for fork

		printf("fork faileddddddd......!\n");

	}
	return 0;
}
#endif

#if 0

#include  <sys/types.h>

#define   MAX_COUNT  20

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */
void  fail(void);

void  main(void)
{
     pid_t  pid;

     pid = fork();
     if (pid > 1)
          ParentProcess();
	 else if (pid == 0) 
          ChildProcess();
     else
		  fail(); 
}

void  ChildProcess(void)
{
     int   i;

	for (i = 1; i <= MAX_COUNT; i++) {
		printf("   This line is from child, value = %d\n", i);
	}
    printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++) {
          printf("This line is from parent, value = %d\n", i);
	 }
     printf("*** Parent is done ***\n");
}
void fail()
{
	printf("fork failed\n");
}

#endif

#if 0

int main()
{
	fork();
	printf("pid is:%d", getpid());
	return 0;
}

#endif


#if 0

int main()
{
	pid_t pid;
	pid = fork();
	if(pid > 0) {
		printf("i am in parent\n");
		printf("parent pid:%d\tchild pid:%d\n", getpid(), pid);
	} else if (pid == 0) {
		printf("parent pid:%d\tchild pid:%d\n", getppid(), getpid());
		sleep(2);
		printf("i am in child\n");
		printf("parent pid:%d\tchild pid:%d\n", getppid(), getpid());
	} else {
		printf("fork failed......!\n");
	}
	return 0;
}

#endif

#if 0

int main()
{	
	pid_t pid;
	int status;
	pid = fork();
	printf("status value after declarations:%d\n", status);
	if (pid > 0) {
		if ( 0 > (wait(&status))) {
			printf("wait failed....!\n");
		} else {
			printf("%d\n", status);
		}
	} else if (pid == 0) {
		printf("in child process:\npid is :%d\n" , getpid());
		printf("in child status:%d\n", status);
	} else {
		printf("fork failed");
	}
	return 0;
}

#endif
