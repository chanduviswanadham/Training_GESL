#include <stdio.h>
#include <stdlib.h>

#define MAX 256
int main()
{
  char *name;
  printf("Who are you? ");
  if(NULL == fgets(name, MAX, stdin)) {
	perror("reading failed\n");
	exit(1);
  }
  printf("Glad to meet you, %s\n", name);
  return(0);
}
