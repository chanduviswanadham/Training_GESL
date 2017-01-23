#include "headers.h"

int main( void )
{

	char *choice;
	char *dbuff = NULL;
	char *sbuf = NULL;
	char *str1 = NULL;
	char *str2 = NULL;
    char *sstr = NULL; 	
	char find_occ;
	int count;
	int pos;
	int ch;

	printf( "Enter the choice:\n" );
	printf( "1.Strcopy\n2.String specified length copy\n"
			"3.return the adress of charecter\n4.Append strings\n"
			"5.Append 'n' charecters\n6.string compare\n"
			"7.string compare ignoring case\n8.strspn function\n"
			"9.string tokenisation\n10.Palindrome checker\n"
			"11.reverse a string\n12.string squeezer\n13.rotated string"
			"checker\n14.Remove string\n15.Insert a charecter\n" );
	
	choice = ( char * ) malloc( sizeof(char) );
	fgets( choice, 10, stdin );
	
	ch = myatoi( choice );
	
	switch( ch )
	{
		case 1: 
			sbuf = "Global Edge";
			dbuff = ( char * ) malloc( sizeof(char) * MAX );
		
			strcopy( sbuf, dbuff );

			free( dbuff );
				
			break;

		case 2:	sbuf = "Global Edge";
				dbuff = ( char * ) malloc( sizeof(char) * MAX );

				printf( "enter the number of characters to be copied:\t" );
				scanf( "%d", &count );

				strncopy( sbuf, dbuff, count );

				free( dbuff );

				break;

		case 3:	sbuf = "Global Edge";
				
				printf( "enter the charecter whose address is to be found in"
						" string 'Global Edge': ");
	            dbuff = (char *) malloc( sizeof(char) * MAX );
				fgets( dbuff, MAX, stdin );

				find_occ = dbuff[0];
                                                                                
				printf( " %d ", *(chr_add_instr ( sbuf, find_occ ) ) );
				break;

		case 4: printf( "enter the two strings to be appended\n" );
				str1 = (char *) malloc( sizeof(char) * MAX ); 
				fgets( str1, MAX, stdin );
				str2 = ( char * ) malloc( sizeof(char) * MAX ); 
				fgets( str2, MAX, stdin );
		
				printf( "the appended string is: %s\n", sappend(str1, str2) );

				free( str1 );
				free( str2 );

				break;

		case 5:	printf( "enter the two strings to be appended\n" );               
                str1 = ( char * ) malloc( sizeof(char) * MAX );                          
                fgets( str1, MAX, stdin );                                         
                str2 = ( char * ) malloc( sizeof(char) * MAX );                          
                fgets( str2, MAX, stdin );

				printf( "enter the range in first string to be appended:\t" );
				scanf( "%d", &count );                                         
                                                                                
                printf( "the appended string is: %s\n",
						 snappend ( str1, str2, count) );    
                                                                                
				free( str1 );
				free( str2 );

                break;

		case 6:	printf( "enter the two strings to be compared\n" );               
                str1 = ( char * ) malloc( sizeof(char) * MAX );                          
                fgets( str1, MAX, stdin );                                         
                str2 = ( char * ) malloc( sizeof(char) * MAX );                          
                fgets( str2, MAX, stdin );

				printf( "the return value is: %d\n", strcmpr( str1, str2 ) );

				free( str1 );
				free( str2 );
	
				break;

		case 7:	printf( "enter the two strings to be compared by"
						" case ignorance\n");               
                str1 = (char *) malloc( sizeof(char) * MAX );                          
                fgets( str1, MAX, stdin );                                         
                str2 = (char *) malloc( sizeof(char) * MAX );                          
                fgets( str2, MAX, stdin );                                         
                                                                                
                printf( "the return value is: %d\n",
						 strcasecmpr( str1, str2 ));     
                                                                                
                free( str1 );                                                     
                free( str2 );                                                     
                                                                                
                break;

		case 8: printf( "enter the two strings:\n" );
                str1 = ( char * ) malloc( sizeof(char) * MAX );                          
                fgets( str1, MAX, stdin );                                        
                str2 = ( char * ) malloc( sizeof(char) * MAX );                          
                fgets( str2, MAX, stdin );                                        
                                                                                
                printf( "the return value is: %d\n", stringspn( str1, str2 ) ); 
                                                                                
                free( str1 );                                                     
                free( str2 ); 
				
				break;

		case 9:	printf( "enter the string:\n" );
                str1 = ( char * ) malloc( sizeof(char) * MAX );                   
                fgets( str1, MAX, stdin );                                        
                
				printf( "enter the delimiter string:\n" );
				str2 = ( char * ) malloc( sizeof(char) * MAX );                   
                fgets( str2, MAX, stdin );                                        
                                                                                
                printf( "the tokenised string is: %s\n", 
						strtoken( str1, str2 ));   
                                                                                
                free( str1 );                                                     
                free( str2 );                                                     
                                                                                
                break;
		
		case 10:
				printf( "Enter the string to validate for the palindrome:\n" );
				sbuf = ( char * ) malloc( sizeof(char) * MAX );
				fgets( sbuf, MAX, stdin );

				palindrome( sbuf );

				free( sbuf );
	
				break;

		case 11:
				printf( "enter the string to be reversed:\n" );
				sbuf = ( char * ) malloc( sizeof(char) * MAX );                   
                fgets( sbuf, MAX, stdin );                                      
                                                                                
                printf( "the reversed string is: %s\n",reverse( sbuf ) );

				free( sbuf );	
		                                                       
                break;

		case 12:
				printf( "enter the string to squeeze the repeated chars:\n" );
				sbuf = ( char * ) malloc( sizeof(char) * MAX );                   
                fgets( sbuf, MAX, stdin );

				compress( sbuf );

				free( sbuf );

				break;

		case 13:
				printf( "enter the first string:\n" );                                  
                str1 = ( char * ) malloc( sizeof(char) * MAX );                   
                fgets( str1, MAX, stdin );                                      
                                                                                
                printf( "enter the second string:\n" );                               
                str2 = ( char * ) malloc( sizeof(char) * MAX );                   
                fgets( str2, MAX, stdin );

				printf( "the value is: %d\n", strrot( str1, str2 ) );	

				break; 

		case 14:
				printf( "enter the string:\n" );
				sbuf = ( char * ) malloc( sizeof(char) * MAX );                   
                fgets( sbuf, MAX, stdin );

				printf("enter the substring:\n");
				sstr = ( char * ) malloc( sizeof(char) * MAX );                   
                fgets( sstr, MAX, stdin );

				printf( "the string after removal: %s",remsstr( sbuf, sstr ) );

				break;

		case 15:
				printf( "Enter the string:\n" );
			    sbuf = ( char * ) malloc( sizeof(char) * MAX );                   
                fgets( sbuf, MAX, stdin );

				printf( "enter the charector to be inserted:\n" );
				dbuff = ( char * ) malloc( sizeof(char) * MAX );                                  
				fgets( dbuff, MAX, stdin );

				find_occ = dbuff[0];

				printf( "enter the position:\n" );
				scanf( "%d", &pos );

				printf( "%s",insertchar( sbuf, find_occ, pos ) );

				free( sbuf );
				free( dbuff );

				break; 				
				
		default: printf( "undefined entry" );

	}

	return 0;
}
