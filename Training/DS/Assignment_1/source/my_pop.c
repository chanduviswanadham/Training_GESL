#include "Assignment_1_headder.h"

extern int arr[MAX];
extern int top;                                                                                
void my_pop()                                                            
{                                                                               
    if (top == -1) {                                                     
        printf("the stack is empty\n");
	} else {                                                                    
    	printf("the removed element in the stack is: %d\n", arr[top]);          
        top--;  	
	}                                                              
} 
