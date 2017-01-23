#ifndef _HEADERS_H
#define _HEADERS_H

#include<stdio.h>
#include<stdlib.h>
#define DIFF 32
#define MAX 100

int strleng( char * );
void strcopy(char *, char *);
int myatoi( char * );
void strncopy(char *, char *, int);
char * chr_add_instr (char *, char);
char * sappend (char *, char *);
char * snappend (char *, char *, int);
char strcmpr (char *, char *);
int strcasecmpr(char *, char *);
size_t stringspn( char *, char *);
int palindrome( char *);
char *reverse( char *);
void compress( char *);
char *remsstr(char *str, char *sstr);
char *insertchar(char *, char, int);
char *strtoken( char *, char * );
int strrot( char *str, char *rstr);

#endif
