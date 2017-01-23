#include "header.h"
//structure which can store 10 members

struct EH {
	unsigned char e_ident[16];
	short e_type;
	short e_machine;
	int e_version;
	unsigned int e_entry;
} arr[5];

//main function

int main()
{
	char *choice;

	choice = (char*)malloc(sizeof(char) * MAX);
	printf("1.upper to lower case\n2.no of words in the file\n3.find string in"
			"file\n4.removing comments from the code\n5.file copy to file.db\n"
			"6.file copy from file.db\nenter yourchoice:\n");
	
	switch (int_val(fgets(choice, MAX, stdin))) {
	
	case 1:
		low_to_up();	//converting all upper to lower in the file
		break;

	case 2:
		count_words();	//counting the no of words present in the file
		break;
	
	case 3:
		string_infile();	//searching a string in file and its line also
		break;
	
	case 4:
		rm_comments();	//removing comments present in the file
		break;

	case 5:
		cpto_file();	//copy strcture contents to file
		break;

	case 6:
		cpfrom_file();	//assessing file contents and printing it
		break;

	default :
		printf("enter the valid input");
	}
	return 0;
}

//converting all upper to lower in the file

int low_to_up()
{
	FILE *fp, *fp1;
	char a;
	
	fp = fopen("file.txt", "r+");	//opening a file in read and write mode
	if (NULL == fp) {				//cheking is the file opened or not
		printf("unable to create the file");
		exit (1);
	}
	fp1 = fopen("file.txt", "r+");	//opening the same file with another discriptor
	if (NULL == fp1) {				//cheking is the file opened or not
		printf("unable to open the file 1");
		exit (1);
	}
	while ((a = fgetc(fp)) != EOF) {	//checking file reached upto EOF
		a = my_tolower(a);				//calling lower conversion function
		fputc(a, fp1);
	}
	fclose(fp);
	return 0;
}

//counting the no of words present in the file

int count_words()
{
	FILE *fp;
	char a;
	int w_c = 0;
	
	fp = fopen("file.txt", "r");	//opening a file in read mode
	if (NULL == fp) {		//cheking is the file opened or not
		printf("unable to open the file\n");
		exit(1);
	}
	
	while ((a = fgetc(fp)) != EOF) {	//taking single character and checking it is EOF or not from file
		if (a == ' ' || a =='\t' || a == '\n') {	//checking the first accourance of word ending
			while ((a = fgetc(fp)) == ' ' || a == '\t' || a == '\n') {	//checking the wording ending condition immediatly to 1st occurance
				continue;
			}
		w_c++;	//increasing the word count value
		}
	}
	printf("no of words in the file is:%d\n", w_c);
	fclose(fp);
	return 0;
}

void string_infile()
{
	FILE *fp;
	char *str = NULL;
	char buf[MAX];
	int line = 1;
	int i = 0;
	int j = 0;
	int n;
	int len;
	int ma;
	int flag = 0;

	str = malloc (sizeof(char) * MAX);	
	printf("enter the string:\n");
	fgets(str, MAX, stdin);
	len = strlen(str) - 1;
	str[len] = '\0';
	fp = fopen("file.txt", "r");	//open the file in read mode
	if (NULL == fp) {	//checking whether file is opened or not
		printf("unable to open the file\n");
		exit(1);
	}
    while (fgets(buf, MAX, fp) != NULL) {   //fetching one line from the file untill goes to null
        i = 0;                                                                
        while (buf[i]) { //checking the line reached to end
			j = 0;
            if (buf[i] == str[j]) {     //eqauting the 1 st char in buf and 1 st char in str
				n = i;
				ma = i;
                while ((buf[n] == str[j]) && (ma < (ma + len))) {  //cheking remaing characters        
					j++;                                                        
					n++;
					ma++;
                }                                                               
                if ((j == len ) && (buf[n] == ' ')) { //whether the buf contains the str              
					printf("line is:%s", buf);                                  
                    printf("string %s found at line no:%d\n",str, line);        
                   	flag = 1;
                }                                                               
            }                                                                   
            i++;                                                                
        }                                                                       
        
		line++;     //line increment                                            
    }
	if (flag == 0)
		printf("string is not found....!\n");
	fclose(fp);
} 
/*	while (fgets(buf, MAX, fp) != NULL) {	//fetching one line from the file untill goes to null
		i = 0;
		j = 0;
		while (buf[i]) {	//checking the line reached to end
			if (buf[i] == str[j]) {		//eqauting the 1 st char in buf and 1 st char in str
				n = i;
				while (buf[n] == str[j]) {	//cheking remaing characters
					j++;
					n++;
				}
				if (j == len) {	//whether the buf contains the str
					printf("line is:%s", buf);
					printf("string %s found at line no:%d\n",str, line);
					break;
				}
			}
			i++;
		}
		line++;		//line increment
	}
	fclose(fp);
*/


//removing the comments from the code

int rm_comments()
{
	FILE *fp;
	FILE *fp1;
	int a;
	
	fp = fopen("comment.txt", "r");	//opeing a file in read mode
	if (NULL == fp) {		//checking whether the file is opened or not
		printf("unable to create the file");
		exit (1);
	}
	fp1 = fopen("nocomment.txt", "w");	//opening a file in write mode
	if (NULL == fp1) {	//checking whether the file is opened or not
		printf("unable to open the file 1");
		exit (1);
	}
	while ((a = fgetc(fp)) != EOF) {	//getting the single character and cheking is it valid
		if ( a == '<') {	//making a condition to put same between the < and >
			
			fputc (a, fp1);
			
			while ((a = fgetc(fp)) != '>') {	//checking it reach to >
				
				fputc (a, fp1);	//puting the > in the file
			}
			
			fputc (a, fp1);
		
		} else if ( a == '"') {	//making a condition to put same between the < and >
			
			fputc (a, fp1);
			
			while ((a = fgetc(fp)) != '"') {	//checking it reach to >
				
				fputc (a, fp1);	//puting the > in the file
			}
			
			fputc (a, fp1);
	
		} else if (a == '/') {	//checking conditions for the // and /* & /* conditions
			
			a = fgetc (fp);
			
			if (a == '/') {
				while ((a = fgetc(fp)) != '\n') {
				
				}
			
			} else if(a == '*') {
				
				while ((a = fgetc(fp))) {
					
					if (a == '*') {
						
						if ((a = fgetc (fp)) == '/')
							
							break;
					}
				}
			
			} else
				printf("error:comment is missing\n");
		} else
			fputc(a, fp1);	//putting contents which is not commented 
	}
	return 0;
	fclose(fp);
}

//storing the entire content of the structure in the file using the fwrite command

int cpto_file()
{
	FILE *fp;
	int i;

	if (NULL == (fp = fopen("file.db", "w"))) {	//opening the file in write and checking whether it is opened or not
		printf("file opening was failed\n");
		exit (1);
	}

	printf("enter the details:\n");

	for(i = 0; i < 5; i++) {		//assigning the value of struct EH members
		
		printf("enter the element %d details:\n", i + 1);
		printf("enter the e_ident:\n");
		scanf("%s", arr[i].e_ident);
		printf("enter the type and machine:\n");
		scanf("%hi%hi", &arr[i].e_type, &arr[i].e_machine);
		printf("enter the version and e_entry:\n");
		scanf("%d%u", &arr[i].e_version, &arr[i].e_entry);
	}
	
	fwrite(arr, sizeof(arr), 1, fp);	//writing the struct info in file
	fclose(fp);
	return 0;
}

int cpfrom_file()
{
	FILE *fp;
	int i;
	
	if (NULL == (fp = fopen("file.db", "r"))) {	//opening the file in write and checking whether it is opened or not

		printf("file opening was failed\n");
		exit (1);
	}

	printf("details present in the file:\n");
	fread(arr, sizeof(arr), 1, fp);	//reading the struct info from the file

	for(i = 0; i < 5; i++) {	//printing the struct member values 
		
		printf("the element %d details:\n", i + 1);
		printf("e_ident:%s\n", arr[i].e_ident);
		printf("type and machine:%hi %hi\n", arr[i].e_type, arr[i].e_machine);
		printf("enter the version and e_entry:%d %u\n", arr[i].e_version, 
				arr[i].e_entry);
	}
	
	fclose(fp);
	return 0;
}
