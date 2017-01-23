#ifndef _HEADERS_H_
#define _HEADERS_H_
#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
#define MAX 256                                                                 
                                                                                
extern char my_tolower(char);  //function is present in the tolower.c           
extern int int_val(char *);                                                     
                                                                                
//function declarations                                                         
                                                                                
int low_to_up();                                                                
int count_words();                                                              
void string_infile();                                                           
int rm_comments();                                                              
int cpto_file();                                                                
int cpfrom_file();

#endif
