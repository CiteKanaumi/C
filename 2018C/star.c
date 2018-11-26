#include<stdio.h>
#include<stdlib.h>

int main()
{
  int num;
  while(1)
    {
      printf("insert num : ");
      scanf("%d", &num);
      if(num%2 == 0)
	{
	  printf("please retry\n");
	}
      else
	{
	  break;
	}
    }
  int k = num / 2;
  int l;
  for(int i = -k; i <= k; i++)
    {
      l = k + 1 - abs(i);
      for(int j = 0; j < l; j++)
	{
	  printf("*");
	}
      printf("\n");
    }
    
  return 0;
}
