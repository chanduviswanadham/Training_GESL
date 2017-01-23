#include<stdio.h>
#include<fcntl.h>
#include<sys/file.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	char buf[100];
	int  sf,df,fe;
	
	if(argc != 3)
	{
		write(1,"program 1.text 2.text\n",50);
		exit(1);

	} else  {

		sf = open( argv[1],O_RDONLY);
		if(sf == -1) {
			perror("Source file error");
			exit(0);
		}
		df = open(argv[2],O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
		if(df == -1) {
			perror("Destination failed open");
			exit(0);
		}
		while(0 < (fe = read(sf,&buf,1))) {					
			write (df,&buf,1);
		}
		write(1,"FILES COPIED",15);
		close(sf);
		close(df);
			
	}
	return 0;
}

	
