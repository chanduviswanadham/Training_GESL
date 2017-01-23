#include<stdio.h>
#if 0
int main(void)
{
	char c = 127;
	for (;c<128;c++) { 
	printf("hello");
	}
}
#endif
#if 0
int main(void)
{
	int a = 5, b = 6;
	printf ("%d\n",a=b);
	printf ("%d\n",a==b);
	printf ("%d%d\n",a,b);
	return 0;
}
#endif
#if 0
int main(void)
{
	typedef int *i;
	int j = 10;
	i * a = &j;
	printf ("%d\n",**a);
	return 0;
}
#endif

#if 0
int main(void)
{
	int a = 10;
	int b = 20;
	int c = 30;

	if (c > b > a) 
		printf ("TRUE\n");
		printf ("FALSE\n");
	return 0;
}
#endif

#if 0
#define MAX ABC
#define ABC 100

int main(void)
{
	printf ("%d",MAX);
	return 0;
}	
#endif

#if 0                                                                          
                                                                                
int main()                                                                      
{                                                                               
    int x = 10;                                                                 
    int *const ptr = &x;                                                        
    ++(*ptr);                                                                   
    printf ("%d\n",x);                                                          
}                                                                               
#endif                                                                          
 
#if 0
int fun();
int main()
{
	int	x = 7;  
	x = fun();
	printf ("%d \n",x);
	return 0;
}
int fun()
{
	printf("hello\n");
} 
#endif

#if 0
int main()
{
	int i,j;
	int n = 4;
	for(i = 0; i< n;i++){
		for (j = 0; j < n ;j++) {
			if (i == j) {
				printf("%d%d\n",i,j);
				break;
			}
		}
	}
	printf ("hello");
}
#endif
#if 0
 int main()
{
	int arr[]={ 1,2,3,4 };
	int *ptr;;;;
	ptr++ = arr;
	printf("%d",*ptr);
	return 0;
} 
#endif

#if 0
main()
{
char *s;
scanf ("%s",s);
printf(s);
} 
#endif


#if 0
int main(void)
{
	printf ("range of char 0 - %d",(1<<(sizeof(char)*8)));
}
#endif
#if 0
int main()
{
	unsigned char c = 257;	//do some experiment on this
	printf ("%d",c);
	return 0;
} 
#endif

#if 0
int main(void)
{
	printf (printf ("hello"));
	return 0;
}
#endif

#if 0
#define abc 100
#define MAX abc
void main()
{
	scanf("%d");
//	int MAX = 1000;
	printf("max= %d",MAX);	//compiler syntax error:you can use NULL inside printf
} 
#endif
#if 0
#define A B
#define B C
#define C A
int main(void)
{	
	char A = 5;	
	char B = 6;
	char C = 7;
	printf ("%d",A);
}
#endif

#if 0

int main(void)
{
	scanf ("%d");
	printf ();
}
#endif

#if 0
//#include
#define islower(c) ( a <=(c) && (c)<= z )
#define toupper(c) (islower(c)?(c)-( a - A ):(c))

main()
{
	char *p="i am fine";
	while(*p)
	printf("%c",toupper(*p++));
} 
#endif

#if 0
a = 200;	//by default int
int main(void)
{
	//200;	//not error
	printf ("%d\n",a);
	printf("tricky problem");
} 
#endif

#if 0
int main(void)
{
	int;	//not error
	printf("tricky problem");
} 
#endif

#if 0
#define MAX 100
#define MAX 300
#define MAX 500
int main(void)
{
	printf ("%d\n",MAX);
	return 0;
}
#endif

#if 0
int main(void)
{
	printf ("%d");
}
#endif

#if 1
int main(void)
{
	int i =10;
	char arr[sizeof('c')];	//4 because character constant
	printf ("%d",sizeof(arr));
	return 0;
}
#endif


#if 1
int main(void)
{
	int i =10;
	char arr[sizeof("c")];	//2 because \0 included
	printf ("%d",sizeof(arr));
	return 0;
}
#endif
