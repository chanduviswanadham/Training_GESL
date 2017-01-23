#include<stdio.h>

//converting the decimal to binary

int show_bit(int deci)                                                          
{                                                                               
    int i;
	printf("the binary number is:\n");                                                                      
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--) {                                
        (deci >> i & 1u) ? printf("1") : printf("0");//taking the bits from msb to lsb
    }                                                                           
    printf("\n");                                                               
    return 0;                                                                   
}
	
