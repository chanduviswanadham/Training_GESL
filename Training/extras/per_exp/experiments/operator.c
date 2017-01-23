#include<stdio.h>

#if 0

//relational operator

int main()
{
	float a=11.00001,b=10.00001;
	int c;
	printf("enter the a and b values:\n");
	//scanf("%ld%ld",&a,&b);
	printf("relational operators:\n1.equal\n2.not equal\n3.left greater than 
			right\n4.right greater than left\n5.greater than or equal\n");
	scanf("%d",&c);
	switch(c){
	case 1:
		if(a==b){
			printf("a and b are euqal\n");
		}else{
			printf("a and b are not equan");
		}
		break;
	case 2:
		if(a!=b){
			printf("a and b are not euqal\n");
		}else{
			printf("a and b are equal\n");
		}
		break;
	case 3:
		if(a>b){
			printf("a is greater than b\n");
		}else{
			printf("a is less than b\n");
		}
		break;
	case 4:
		
		if(a<b){
			printf("a<b\n");
		}else{
			printf("a>b\n");

		}
		break;
	case 5:
		
		if(a>=b){
			printf("a>=b\n");
		}else{
			printf("a<=b\n");
		}
		break;
	default:
		printf("you are entered wrong one\n");
		break;
	}
	return 0;
}

#endif

#if 0

int main()
{
	double a=0.00000,b=0.00001;
	int c;
	//printf("enter the a and b values:\n");
	//scanf("%ld%ld",&a,&b);
	printf("logical operators:\n1.logical and\n2.logical or \n3.logical not\n");
	scanf("%d",&c);
	switch(c){
	case 1:
		printf("logical and:%d",a&&b);
		break;
	case 2:
		printf("logical or :%d",a||b);
		break;
	case 3:
		printf("the logical not of a is:%d",!a);
		printf("the logical not of b is:%d",!b);
		break;
	default:
		printf("you are entered wrong one\n");
		break;
	}
	return 0;
}
#endif


#if 1

int main()
{
	int a=1,b=2;
	int c;
	//printf("enter the a and b values:\n");
	//scanf("%ld%ld",&a,&b);
	printf(" operators:\n1.bitwise and\n2.bitwise or \n3.bitwise eor\n4.complementory\n5.left shif\n6.right shif");
	scanf("%d",&c);
	switch(c){
	case 1:
		printf("bitwise and:%d\n",a&b);
		break;
	case 2:
		printf("bitwise  or :%d\n",a|b);
		break;
	case 3:
		printf("bitwise eor: %d\n",a^b);
		break;
	case 4:
		printf("complement :%d\n",~a);
		break;
	case 5:
		printf("left shift:%d\n",a<<1);
		break;
	case 6:
		printf("right shift:%d",a>>1);
		break;
	default:
		printf("you are entered wrong one\n");
		break;
	}
	return 0;
}
#endif
