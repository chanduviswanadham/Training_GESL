#include <stdio.h>
#include <stdlib.h>

#if 0
int
main ()
{
  static int i = 5;
  if (--i)
    {
      printf ("%d ", i);
      main (10);
    }
}
#endif

#if 0
#include <stdio.h>

int
main ()
{
  /*
     chandgbsdcbasldas
     as dflahsdfjha skldfhasdf
     as; dfjaskldfhas
     df askdhflkasjdhf 
     h asdf;klah
     ;wefjkljawe */
  printf ("max is :%d", 100);
}

#endif

#if 0
#include <stdio.h>
#define INCREMENT(x) ++x
int
main ()
{
  char *ptr = "GeeksQuiz";
  int x = 10;
  printf ("%s  ", INCREMENT (ptr));
  printf ("%d", INCREMENT (x));
  return 0;
}

#endif

#if 0
#include<stdio.h>

int
main (int argc, char *argv[])
{
  int flag = 0;
  char passwd[10];

  memset (passwd, 0, sizeof (passwd));

  strcpy (passwd, argv[1]);

  if (0 == strcmp ("LinuxGeek", passwd))
    {
      flag = 1;
    }

  if (flag)
    {
      printf ("\n Password cracked \n");
    }
  else
    {
      printf ("\n Incorrect passwd \n");

    }
  return 0;
}
#endif
#if 0
int
main ()
{
  static int i;
  int *ptr = NULL;
  ptr = (int *) malloc (sizeof (int));
  func ();
  func ();
  func ();
  printf ("the value of the i= %d", i);
  free (ptr);
  return 0;
}

int
func ()
{
  static int i = 5;
  printf ("the value of the i= %d", i++);
  return 0;
}
#endif

#if 1

float main( void )	//float double possbile
{
	printf("hello world");
	return;
}

#endif
