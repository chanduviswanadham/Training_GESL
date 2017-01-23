#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 235

int getnum( void )
{

	int num;
    int i = 0;
    int result = 0;
	char *numstr;
	
	numstr = ((char *) malloc (sizeof(char) * MAX ));

	fgets (numstr, MAX, stdin );
    
	*(numstr + strlen(numstr) - 1) = '\0';

	for(i = 0; numstr[i] >= '0' && numstr[i] <= '9'; ++i){
      
		if( numstr[i] == '\0') {
				break;
		  }	
		  result = (result * 10) + (numstr[i] - '0');
    		
	}
    
	

    
	return result;
}


/*
int main( void )
{

	int num;

	printf(" get a number ");

	num = getnum();

	printf(" the number is %d ", num);


	return 0;
}

*/
