#include<stdio.h>

int show_bit(int deci)                                                          
{                                                                               
    int i;                                                                      
    for(i = ( sizeof(int)*8)-1 ; i >= 0 ; i-- ){                                
        (deci >> i & 1u) ? printf("1") : printf("0");                                           
    }                                                                           
    printf("\n");                                                               
    return 0;                                                                   
}
	
