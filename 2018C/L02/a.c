#include <stdio.h>
#include <stdlib.h>

 

#define MAX_SIZE 20

 

typedef enum {false, true} bool;

 

typedef struct {
 int top ;
 int items[MAX_SIZE] ;
} Stack;

 

void Initstack(Stack *pstack){
 pstack->top= -1;
}

 

bool Isfull(Stack *pstack){
 return pstack->top == MAX_SIZE-1;
}

 

bool Isempty(Stack *pstack){
 return pstack->top == -1 ;
}

 

void push(Stack *pstack, int item){
 if(Isfull(pstack))
  exit(1) ;
 pstack->items[++(pstack->top)]= item;
}

 

void pop(Stack *pstack, int *save){
 if(Isempty(pstack))
  exit(1) ;
 *save=pstack->items[pstack->top];
 --(pstack->top);
}

 

int main(void){
 int num;
 Stack stack;
 int save;

 Initstack(&stack);

 for(num=1; num<=MAX_SIZE; num++){
  push(&stack , num);
 }

 while (!Isempty(&stack)) ;
 {
  pop(&stack, &save);
  printf("Popped number : %d\n", save);
 }

 return 0;
}
