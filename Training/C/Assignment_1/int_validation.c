#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
/*
int int_val(char *);	//function declaration 

int main()
{
	char *val;
	int rval;
	val = (char*)malloc(sizeof(char) * 256);
	printf("enter the value:");
//	scanf("%d", val);
	fgets(val, 256, stdin);
	rval = int_val(val);
	printf("value is:%d\n", rval);
	return 0;
		
}
*/
//validation function

int int_val(char *e_val)
{
	int i = 0;
	int r_val = 0;
	
	for (;e_val[i] != '\0'; i++) {
		
		if (e_val[i] == '+' && i == 0) {
			
			continue;
		
		} else if (e_val[i] == '+' || e_val[i] == '-') {
				
			printf("invalid input\n");
			r_val = 0;
			break;
		
		} else if (e_val[i] == '.' && e_val[i + 1] == '1') {
				
				r_val = 0;
				break;
		
		} else if (e_val[i] >= '0' && e_val[i] <= '9') {
				
				r_val = (r_val * 10) + (e_val[i] - '0');
				continue;
		
		} else if (' ' == e_val[i] || '.' == e_val[i]) {
				
				printf("invalid input\n");
				r_val = 0;
				break;
		}
	}	
	
	return (r_val);
}


