#include "Assignment_1_headder.h"

extern int arr[MAX];
extern int top;
void my_display()                                                                  
{                                                                               
    int i = 0;                                                                  
    if (top == -1) {                                                            
        printf("the stack frame is empty\n");                                   
    } else {                                                                    
        for (i = 0; i <= top; i++) {                                            
            printf("%d ", arr[i]);                                              
        }                                                                       
    }                                                                           
} 
