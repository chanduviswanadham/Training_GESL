#include <stdio.h>
#if 0
int main(void)

{

       switch(3) {

       case 1:

               printf("case 1\n");

               break;

      case 2:

               printf("case 2\n");
               break;
      default:
               printf("default case\n");

       }

       return 0;

}
#endif

#if 0
int fun1()

{

    return 20;

}

int fun2()

{
//	return;
}

int main()

{

    int a = fun1();

    int b = a + 40;
    
	int c = fun2();
   	
	printf("%d\n", c);
    return 0;

}

#endif

#if 0

int func(int *val)

{

          (*val)++;

          return val;
}

int main(void)

{

        int val = 10;
		printf("%p\n", &val);

        val = func(&val);

        printf("val = %p\n", val);
}

#endif

#if 0
int func(int, int);
int main()
{
	int a;
	int b = (1,2,3);
	a = func(10, 20);
	printf("values is :%d\t%d", a, b);
	return 0;
}

int func(int a, int b)
{
	return a , b;
}

#endif

#if 1

int main()
{
	int i = 10;

	switch(i) {
		printf("printf\n");
		i = 15;

	case 10:
		printf("i value is :%d", i);
		break;
	
	default:
		printf("ajksdgafhskjdf\n");
	
	}
	return 0;
}

#endif
