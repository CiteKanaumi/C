#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 
#include <conio.h> 
#include <time.h> 

#define EMPTY 0

struct node { 
   int data; 
   struct node * link; 
};

typedef struct node Stack;



int isEmpty(Stack* top) 
{ 
   return (top == EMPTY) ? 1 : 0; 
} 


Stack * get_node() { 
   Stack * tmp; 
   tmp = (Stack *)malloc(sizeof(Stack)); 
   tmp->link = EMPTY; 
   return tmp; 
} 

int push(Stack **top, int data) { 
   Stack *tmp; 
   tmp = *top; 
   *top = get_node(); 
   (*top)->data = data; 
   (*top)->link = tmp; 
   return data; 
} 
int pop(Stack **top) { 
   int data; 
   Stack *tmp; 
   if (isEmpty(*top)) 
   { 
      return EMPTY; 
   } 
   tmp = (*top)->link; 
   data = (*top)->data; 
   free(*top); 
   *top = tmp; 
   return data; 
} 
void printAll(Stack* top) 
{ 
   Stack* tmp = top; 
   if (isEmpty(top)) 
   { 
      printf("empty\n"); 
      return; 
   } 
   while (tmp != EMPTY) 
   { 
      printf("%d\n", tmp->data); 
      tmp = tmp->link; 
   } 
} 
void main() { 
   int num, pushtmp;// num:switch select, pushtmp: insert num 
   Stack* top = EMPTY; 
   while (1)//x 
   { 
      printf("<<< menu >>>\n1.push\n2.pop\n3.show all\n4.exit\n"); 
      printf("select : "); 
      scanf("%d", &num); 
      switch (num) { 
         case 1://push 1 
         printf("insert data : "); 
         scanf("%d", &pushtmp); 
         push(&top, pushtmp); 
         system("cls"); 
         break; 
         case 2:// pop 1 
         if (!isEmpty(top)) 
         { 
            printf("%d\n", pop(&top)); 
         } 
         else 
         { 
            printf("empty\n"); 
         } 
         Sleep(1000); 
         system("cls"); 
         break; 
         case 3:// 
         printAll(top); 
         Sleep(2000); 
         system("cls"); 
         break; 
         case 4: //  
         { 
            while (!isEmpty(top)) 
            { 
               printf("%d\n", pop(&top)); 
            } 
            printf("sleep!\n"); 
            Sleep(1000); 
         } 
         printf("complete! \ngood bye!\n"); 
         Sleep(2000); 
         exit(1); 
         break; 
      } 
   } 
} 
