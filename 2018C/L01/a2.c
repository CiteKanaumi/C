#include <stdio.h> 
#include <stdlib.h>

struct list
{
  double x;		       
  struct list *next;	 
};

struct list *add_list(double x, struct list *head);
void show_list(struct list *p);
void sum_list(struct list *p);
void sort_list(struct list *p);

int main(void)
{
  struct list *head;	        
  double x = 0;
  int num;
  head = NULL;
  
  while(1)
    {
      printf("0>insert, 1>show, 2>sort, 3>sum\n");
      scanf("%d", &num);
      
      if(num == 0)
	{
	  printf("insert number:");
	  scanf("%lf", &x);
	  head = add_list(x, head);
	}
      else if(num == 1)  
	{
	  show_list(head);
	}
      else if(num == 2)
	{
	  sort_list(head);
	}
      else if(num == 3)
	{
	  sum_list(head);
	}
    }
  
  return 0;
}

struct list *add_list(double x, struct list *head)
{
  struct list *p;
  
  if ((p = (struct list *) malloc(sizeof(struct list))) == NULL)
    {
      exit(EXIT_FAILURE);
    }
  
  p->x = x;
  
  p->next = head;	     
  head = p;      
  
  return head;
}


void show_list(struct list *p)
{
  while (p != NULL)
    {
      printf("%e\n", p->x);
      p = p->next;
    }
}

void sum_list(struct list *p)
{
  double A = 0;
  while (p != NULL)
    {
      A = A + p->x;
      p = p->next;
    }
  printf("%e\n", A);
}

void sort_list(struct list *p)
{
  struct list *head;
  struct list *back;
  double temp = 0;
  double sum = 0;
  int i, j, k;
  int data_count = 0;

  head = p;

  while(p != NULL)
    {
      data_count++;
      p = p->next;
    }  
  
  for(i=0; i<data_count-1; i++)
    {
      for(j=data_count-1; j>i; j--)
	{
	  p = head;
	  for(k=0, p=head; k<j-1; k++)
	    {
	      p = p->next;
	    }
	  back = p;
	  p = p->next;

	  if( fabs(p->x) < fabs(back->x) )
	    {
	      temp = p->x;
	      p->x = back->x;
	      back->x = temp;
	    }
	}
    }
  
}
