#include <stdio.h>

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
		
		} else if (' ' == e_val[i]) {
				
				printf("invalid input\n");
				r_val = 0;
				break;
		}
	}
	
	return (r_val);
}
