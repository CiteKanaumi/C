#include <stdio.h>
#include <math.h>

int main ()
{
  double A = 0;
  int i, j, X;
  
  printf("how many box?\n");
  scanf("%d", &X);
  
  double a[X];

  for(i=0; i<X; i++)
    {
	  printf("insert number:");
	  scanf("%lf", &a[i]);
    }

  printf("(show number)\n");
  
  for(i=0; i<X; i++)
    {
	  printf("%e\n", a[i]);
      A=A+a[i];
    }

  printf("sum:%e\n", A);

  A = 0;

  for (i=0; i<X; i++)
    {
      for(j=i+1; j<X; ++j)
      {
    	  if( fabs(a[i]) > fabs(a[j]) )
    	  {
    		  double temp;
    		  temp = a[i];
    		  a[i] = a[j];
    		  a[j] = temp;
    	  }
      }
    }

  printf("(sort)\n");
  
  for(i=0; i<X; i++)
    {
	  printf("%e\n", a[i]);
      A=A+a[i];
    }
	   printf("sum:%e\n", A);
  
  return 0;
}


