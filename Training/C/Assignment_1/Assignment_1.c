#include <stdio.h>
#include <stdlib.h>
#define MAX 256
#if 1
 
extern int show_bit(int);
extern int int_val(char *);

int soneb();
int stwob();
int b_copy();
int tog(int, int);
unsigned int r_rot(unsigned int, int);
unsigned int l_rot(unsigned int, int);
int count_bit_set(int);
int count_bit_clear(int);
int cnt_leading_set_bits(int);
int cnt_leading_clear_bits(int);
int cnt_trailing_set_bits(int);
int cnt_trailing_clear_bits(int);
int invert(int, int, int);
int setbits(int, int, int, int);
int main1();

//macro for finding bignumber
#define bit_ts(num, pos) (num >> pos & 1u ? num : (num | (1u<<pos) ) )

//finding the bits
#define getbits(x, p, n){ while( (p + n) != p){		\
							printf("%d", ((x >> (p + n - 1)) & 1u ) );\
							n--;	\
						  }		\
						}
//entering function where we can select many operations

int main()
{
	char *input = NULL;
	int num;
	int num1;
	int pos;
	int n;
	
	input = (char *)malloc( sizeof(char) * MAX );
	printf("1.show bits\n2.swaping 2b in 1no\n3.swaping 2b in 2no\n"
			"4.bit copy\n5.toggle\n6.position set\n7.right rotate one time\n"
			"8.left rotate one time\n9.right rotate\n10.left rotate\n11.set"
			" bits\n12.clear bits\n13.leading set bit\n14.leading clearbit\n"
			"15.trailing setbit\n16.trailing clearbit\n17.getbits\n"
			"18.invert\n19.setbits\n20.macros\n");
	
	switch (int_val(fgets(input, MAX, stdin))) {
	
	case 1:
		printf("enter the number:\n");
		show_bit(int_val(fgets(input, MAX, stdin)));
		break;
	
	case 2:
		soneb();
		break;
	
	case 3:
		stwob();
		break;
	
	case 4:
		b_copy();
		break;
	
	case 5:
		printf("enter the number:\n"); 
		num = int_val(fgets(input, MAX, stdin));
		printf("what is need 0.even toggle 1. odd toggle\n ");
		pos = int_val(fgets(input, MAX, stdin));
		tog(num, pos);
		break;
	
	case 6:
		printf("enter the number:\n");                                          
		num = int_val(fgets(input, MAX, stdin));
        printf("enter the position need to set\n ");                  
		pos = int_val(fgets(input, MAX, stdin));
		num = bit_ts(num, pos); 
		show_bit(num);
		break;
	
	case 7:
		printf("enter the number:\n");                                          
		num = int_val(fgets(input, MAX, stdin));
		r_rot(num, 1);
		break;
	
	case 8:
		printf("enter the number:\n");                                          
		num = int_val(fgets(input, MAX, stdin));
		l_rot(num, 1);
		break;
	
	case 9:		
		printf("enter the number:\n");                                          
		num = int_val(fgets(input, MAX, stdin));
		printf("enter rotation times:\n");
		pos = int_val(fgets(input, MAX, stdin));
		r_rot(num, pos);
		break;
	
	case 10:
		printf("enter the number:\n");                                          
		num = int_val(fgets(input, MAX, stdin));
		printf("enter rotation times:\n");
		pos = int_val(fgets(input, MAX, stdin));
		l_rot(num, pos);
		break;
	
	case 11:
		printf("enter the number:\n");
		num = int_val(fgets(input, MAX, stdin));
		count_bit_set(num);
		break;
	
	case 12:
		printf("enter the number:\n");
		num = int_val(fgets(input, MAX, stdin));
		count_bit_clear(num);
		break;
	
	case 13:
		printf("enter the number:\n");
		num = int_val(fgets(input, MAX, stdin));
		cnt_leading_set_bits(num);
		break;
	
	case 14:
		printf("enter the number:\n");
		num = int_val(fgets(input, MAX, stdin));
		cnt_leading_clear_bits(num);
		break;
	
	case 15:
		printf("enter the number:\n");
		num = int_val(fgets(input, MAX, stdin));
		cnt_trailing_set_bits(num);
		break;
	
	case 16:
		printf("enter the number:\n");
		num = int_val(fgets(input, MAX, stdin));
		cnt_trailing_clear_bits(num);
		break;
	
	case 17:
		printf("enter the number1:\n");
		num = int_val(fgets(input, MAX, stdin));
		printf("enter the posotion:\n");
		pos = int_val(fgets(input, MAX, stdin));
		printf("the number of bits need to get:\n");
		n = int_val(fgets(input, MAX, stdin));
		getbits(num, pos, n);
		break;

	case 18:
		printf("enter the number1:\n");                                         
		num = int_val(fgets(input, MAX, stdin));
        show_bit(num);                                                       
        printf("enter the posotion:\n");                                        
		pos = int_val(fgets(input, MAX, stdin));
        printf("the number no of bits need to invert:\n");                            
		n = int_val(fgets(input, MAX, stdin));
        invert(num, pos, n);
		break;
	
	case 19:
		printf("enter the number1:\n");                                         
		num = int_val(fgets(input, MAX, stdin));
        show_bit(num);
		printf("enter the number2\n");                                          
		num1 = int_val(fgets(input, MAX, stdin));
        show_bit(num1);
		printf("enter the posotion:\n");                                        
		pos = int_val(fgets(input, MAX, stdin));
        printf("the number no of bits need to change:\n");                      
		n = int_val(fgets(input, MAX, stdin));
		setbits(num, pos, n, num1);
		break;

	case 20:
		main1();
		break;		
 
 	default:
		printf("your choice is invalid\n");
		break;
	}
	free(input);
	return 0;
}

//swaping 2 bits in 1 number function

int soneb()
{
	int num;
	char *input = NULL;
	int s_bit;
	int d_bit;
	int temp;
	
	input = (char *)malloc( sizeof(char) * MAX );
	printf("enter the decimal number:\n");
//	scanf("%d", &num);
	num = int_val(fgets(input, MAX, stdin));
	printf("binary number before swaping:\n");
	show_bit(num);
	printf("\nenter the source and destination bit positons:\n");
//	scanf("%d%d", &s_bit, &d_bit);
	s_bit = int_val(fgets(input, MAX, stdin));
	d_bit = int_val(fgets(input, MAX, stdin));
	temp=((num >> s_bit) & 1u) ^ ((num >> d_bit) & 1u);
	if (temp != 0) {
		temp = (temp << s_bit) | (temp << d_bit);
		num = num ^ temp;
		show_bit( num );
	}
	
	else {
		printf("both the bits are same\n");
	}	
	printf("\n");
	free(input);
	return 0;
}

//swaping 2 bits in 2 numbers function

int stwob()
{
	char *input = NULL;
	int s_num;
	int d_num;
	int s_bit;
	int d_bit;
	int s_ex;
	int d_ex;
	
	input = (char *)malloc( sizeof(char) * MAX );
	printf("enter the source and destination numbers:\n");
//	scanf("%d%d", &s_num, &d_num);
	s_num = int_val(fgets(input, MAX, stdin));
	d_num = int_val(fgets(input, MAX, stdin));
	printf("source:");
	show_bit(s_num);
	printf("destination");
	show_bit(d_num);
	printf("enter the positon  source bit and destination bit:\n");
//	scanf("%d%d", &s_bit, &d_bit);
	s_bit = int_val(fgets(input, MAX, stdin));
	d_bit = int_val(fgets(input, MAX, stdin));
	
	s_ex = (s_num >> s_bit) & 1u;
	d_ex = (d_num >> d_bit) & 1u;
	s_ex = s_ex << d_bit;
	d_ex = d_ex << s_bit;
	s_num = s_num & (~(1u << s_bit));
	d_num = d_num & (~(1u << d_bit));
	s_num = s_num | d_ex;
	d_num = d_num | s_ex;
	
//	printf("after swaping source");
//	show_bit(s_num);
	printf("after swaping destination");
	show_bit(d_num);
	free(input);
	return 0;
}

//bit copy function

int b_copy()
{
	char *input = NULL;
	int s_num;
	int d_num;
	int s_bit;
	int d_bit;
	int no;
	char sb;
	char db;
	char l_e1;
	char l_e2;
	
	input = (char *)malloc( sizeof(char) * MAX );
	printf("enter the source and destination numbers:\n");                      
	s_num = int_val(fgets(input, MAX, stdin));
	d_num = int_val(fgets(input, MAX, stdin));
//    scanf("%d%d", &s_num, &d_num);                                              
    printf("the binary value of source:\n");                                    
    show_bit(s_num);                                                          
    printf("the binary value of destination:\n");                               
    show_bit(d_num);
	printf("the number of bits need to copy:\n");
	no = int_val(fgets(input, MAX, stdin));
//	scanf("%d", &no);
	printf("enter the positon  source bit and destination bit:\n");             
	s_bit = int_val(fgets(input, MAX, stdin));
	d_bit = int_val(fgets(input, MAX, stdin));
//    scanf("%d%d", &s_bit, &d_bit);
	for (l_e1 = s_bit ,l_e2 = d_bit ; l_e1 >= (s_bit+1) - no; l_e1--, l_e2--) {
		sb = s_num >> l_e1 & 1u;
		db = d_num >> l_e2 & 1u;
		if ( sb != db ) {
			d_num = d_num ^ 1u << l_e2;
		}
	}
	show_bit(d_num);
	free(input);
	return 0;
}

int tog(int num,int i)                                                                     
{                                                                               
	printf("before toggle:\n");                                                  
	show_bit(num);                                                             
	for ( ;i <= ( sizeof( int )*8 ) - 1; i += 2) {                           
		num = num ^ (1u << i);                                                   
	}                                                                           
	printf("after toggle:\n");                                                  
	show_bit(num);                                                             
	return 0;                                                                   
}     

unsigned int r_rot(unsigned int num, int pos)
{
	printf("binary value:");
	show_bit(num);
	num = (num >> pos) | (num << (32-pos));
	printf("after right rotation by %d:", pos);
	show_bit(num);
	return 0;
}

unsigned int l_rot(unsigned int num, int pos)
{
	printf("binary value:");
	show_bit(num);
	num = (num << pos) | (num >> (32-pos));
	printf("after right rotation by %d:",pos );
	show_bit(num);
	return 0;
}

int count_bit_set(int num)
{
	int i;
	int count = 0;
	
	for(i = (sizeof(int) * 8) - 1;i >= 0;i--){
		if(num >> i & 1u)
			count++;
	}
	printf("no of set bits:%d\n", count);
	return 0;
}

int count_bit_clear(int num)
{
	int i;
	int count = 0;
	
	for(i = (sizeof(int) * 8) - 1;i >= 0;i--){
		if((num >> i & 1u) == 0)
			count++;
	}
	printf("no of clear bits:%d\n", count);
	return 0;
}

int cnt_leading_set_bits(int num)
{
	int i = (sizeof(int)*8) - 1;
	int count = 0;
	
	while(num >> i & 1u){
		count++;
		i--;
	}	
	printf("the no of leading set bits:%d\n",count);	
	return 0;
}

int cnt_leading_clear_bits(int num)
{
	int i = (sizeof(int) * 8) - 1;
	int count = 0;
	
	while(!(num >> i & 1u)){
		count++;
		i--;
	}	
	printf("the no of leading clear bits:%d\n",count);	
	return 0;
}

int cnt_trailing_set_bits(int num)
{
	int i = 0;
	int count = 0;
	
	while(num >> i & 1u){
		count++;
		i++;
	}	
	printf("the no of trailing set bits:%d\n",count);	
	return 0;
}

int cnt_trailing_clear_bits(int num)
{
	int i = 0;
	int count = 0;
	
	while(!(num >> i & 1u)){
		count++;
		i++;
	}	
	printf("the no of trailing clear bits:%d\n",count);	
	return 0;
}

int invert(int x, int p, int n)
{
	while( (p + n) != p){                           
		x = x ^ (1u << (p + n -1));
		n--;
	} 
	printf("%d", x);
	show_bit(x);
	return 0;                                          
}   	

int setbits(int x, int p, int n, int y)
{
	while((p + n -1) >= p){
		if(((x >> (p + n -1)) & 1u) != ((y >> (p + n -1)) & 1u))
			x = x ^ (1u << (p + n -1));
		n--;
	}
	show_bit(x);
	return 0;
}

//macros programs
#define MAXMIN(num, num1) {                                              \
		int i = (sizeof(int) * 8) - 1;									 \
		while(i >=0){               					                 \
			if(((num >> i) & 1u) > ((num1 >> i) &1u)){                   \
				printf("number 1 is greater than number 2\n");           \
				break;                                                   \
			}else if(((num >> i) & 1u) < ((num1 >> i) &1u)){             \
				printf("number 2 is greater than number 1\n");           \
				break;                                                   \
			}else                                                        \
				i--;                                                     \
		}                                                                \
	}

#define CLEAR_R_SETBIT(num){											\
		int i=0;														\
		while(i <= ((sizeof(int) * 8) - 1)){							\
			if(((num >> i) & 1u) == 1){									\
				num ^= 1u << i;											\
				break;													\
			}															\
			i++;														\
		}																\
		show_bit(num);													\
	}


#define SET_R_CLEARBIT(num){											\
		int i=0;														\
		while(i <= ((sizeof(int) * 8) - 1)){							\
			if(((num >> i) & 1u) == 0){									\
				num ^= 1u << i;											\
				break;													\
			}															\
			i++;														\
		}																\
		show_bit(num);													\
	}

#define CLEAR_L_SETBIT(num){											\
		int i = (sizeof(int) * 8) - 1;									\
		while(i >= 0){							 						\
			if(((num >> i) & 1u) == 1){									\
				num ^= 1u << i;											\
				break;													\
			}															\
			i--;														\
		}																\
		show_bit(num);													\
	}

#define SET_L_CLEARBIT(num){											\
		int i = (sizeof(int) * 8) - 1;									\
		while(i >= 0){													\
			if(((num >> i) & 1u) == 0){									\
				num ^= 1u << i;											\
				break;													\
			}															\
			i--;														\
		}																\
		show_bit(num);													\
	}
#define CLEAR_SD_SET(n, s, d){											\
		int i = (sizeof(int) * 8) - 1;									\
		while( i >= 0){													\
			if(i >= d && i <= s)										\
				n |= 1u << i;											\
			else														\
				n &= (~(1u << i));										\
			i--;														\
		}																\
		show_bit(n);													\
	}																	

#define SET_SD_CLEAR(n, s, d){											\
		int i = (sizeof(int) * 8) - 1;									\
		while( i >= 0){													\
			if(i >= d && i <= s)										\
				n &= (~(1u << i));										\
			else														\
				n |= 1u << i;											\
			i--;														\
		}																\
		show_bit(n);													\
	}																	
							
#define TOGGLE_SD(n, s, d){													\
		int i = (sizeof(int) * 8) - 1;									\
		while( i >= d){													\
			if(i >= d && i <= s)										\
				n ^= 1u << i;											\
			i--;														\
		}																\
		show_bit(n);													\
	}				
																	


				

int main1()
{
	int choice;
	int num;
	int num1;
	int s;
	int d;

	printf("1.maxium and minimum\n2.clear the right most set bit\n3.clear"
			"the left most set bit\n4.set the right most clear bit\n"
			"5.set the left most clear bit\n6.set s to d remaining clear\n"
			"7.clear s to d remaining set\n8.toggle from s to d\n");
	scanf("%d", &choice);
	switch(choice){	
	case 1:
		printf("enter the number1:\n");
		scanf("%d", &num);
		printf("enter the number:2\n");
		scanf("%d", &num1);
		MAXMIN(num, num1);
		break;

	case 2:
		printf("enter the number:\n");
		scanf("%d", &num);
		CLEAR_R_SETBIT(num);
		break;
	
	case 3:
		printf("enter the number:\n");
		scanf("%d", &num);
		CLEAR_L_SETBIT(num);
		break;
	
	case 4:
		printf("enter the number:\n");
		scanf("%d", &num);
		SET_R_CLEARBIT(num);
		break;

	case 5:
		printf("enter the number:\n");
		scanf("%d", &num);
		SET_L_CLEARBIT(num);
		break;
		
	case 6:
		printf("enter the number:\n");
		scanf("%d", &num);
		printf("enter the source posotion:\n");                                        
        scanf("%d", &s);                                                      
        printf("enter the destination posotion:\n");                                        
        scanf("%d", &d);
		CLEAR_SD_SET(num, s, d);
		break;                                                     

	case 7: 
		printf("enter the number:\n");
		scanf("%d", &num);
		printf("enter the source posotion:\n");                                        
        scanf("%d", &s);                                                      
        printf("enter the destination posotion:\n");                                        
        scanf("%d", &d);
		SET_SD_CLEAR(num, s, d);
		break;      
		
	case 8:
		printf("enter the number:\n");
		scanf("%d", &num);
		printf("enter the source posotion:\n");                                        
        scanf("%d", &s);                                                      
        printf("enter the destination posotion:\n");                                        
        scanf("%d", &d);
		TOGGLE_SD(num, s, d);
		break;
	
	default:
		printf("your choice is invalid\n");
		break;
	}
	return 0;
}
#endif

