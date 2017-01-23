#include<stdio.h>
#include<string.h>
#if 0
int main(int arg, char *argv[])
{

	printf("the no of files in the given directory is: %d\n", arg);
	return 0;
}

#endif

#if 0
int main(int arg, char *argv[])
{
	int count = 0;
   	int len = 0;
 
	printf("the no of files in the given directory is: %d\n", arg);
	arg = arg -1;
	while(arg){
		len = strlen(argv[arg]);
		if( (*(*(argv + arg) + (len - 1)) == 'c') && (*(*(argv + arg) + (len - 2)) == '.'))
			count++;
		arg--;
	}
	printf("the no of c files is:%d", count);
    return 0;
}
#endif

#if 1

void (*func)(int, int,char *);
void arth(int, int,char *);
int main(int arg, char *argv[])
{
	int result = 0;
	int len = 0;

	if(arg != 4)
		printf("you passed so many arguments\n");
	else{
		arg = 1;
		len = strlen(argv[arg]);
		if(len != 3)
			printf("enter the correct keyword operation\n");
		else{
			func = arth;
			func(atoi(argv[2]), atoi(argv[3]), argv[1]);
		}
	}
	return 0;
}
void arth(int a, int b, char *val)
{
	int result = 0;
	if(!strcmp(val, "add")){
		result = a + b;
		printf("result is :%d\n", result);
	}else if(!strcmp(val, "sub")){
		result = a - b;
		printf("result is :%d\n", result);
	}else if(!strcmp(val, "mul")){
		result = a * b;
		printf("result is :%d\n", result);
	}else if(!strcmp(val, "div")){
		result = a / b;
		printf("result is :%d\n", result);
    }
}
#endif
