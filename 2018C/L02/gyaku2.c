#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILURE 0

typedef char data_type; /*char型をdata_type型に置き換える */

typedef struct node_tag {
 data_type data; 
 struct node_tag *next;     /* 後続ノードへのポインタ */
} node_type;                /* ノードの型 */

 node_type *head; /* スタックの先頭へのポインタ （変数宣言）*/

void initialize(node_type **pp)    /* スタックの初期化 */
{
 *pp = NULL;              /* スタックは空（先頭ノードなし） */
}

/* ノードを後ろに付け加える*/

node_type* new_node(data_type data, node_type** head) {
  node_type* n = malloc(sizeof(data_type));
  node_type* p;
  n->data = data;
  n->next = NULL;
  if (*head == NULL) {
    *head = n;
    return n;
  }
  p = *head;
  while(1) {
    if (p->next == NULL) {
      p->next = n;
      break;
    }
    p = p->next;
  }
  return n;
}

//末尾のノードの文字を出力する
data_type last_node(node_type **pp)
{
 node_type *temp=*pp;
 if (*pp == NULL) return 0;
 while (1) {
   if (temp->next == NULL) {
     break;
   }
   temp = temp->next;
 } 
 return(temp->data);
}

int is_empty(node_type *p) {        /* 空スタックのとき真、  そうでないならば偽を返す */
 if (p == NULL) return TRUE;        /* 空スタックのとき */
 else return FALSE;                 /* 空スタックでないとき */
}

//スタックの先頭ノードの削除
int pop(node_type **pp)
{
 node_type *temp;
 if (*pp != NULL) {
 temp = (*pp)->next;
 free(*pp); /* メモリの解放 */
 *pp = temp;
 return SUCCESS;
 }
 else return FAILURE;
}

//スタックの先頭へのノードの挿入
int push(node_type **pp, data_type x)
{
  node_type *temp;
  temp = new_node(x, pp); 
  if (temp == NULL) return FAILURE;
  *pp = temp;
  return SUCCESS;
}

//文字の優先順位を出力する
int prior(data_type s){
  if(s=='A' || s== 'B' ||s== 'C' ||s== 'D' ||s== 'E' ||s== 'F' || s=='G')
    return 5;
  if(s=='=')
    return 0;
  if(s=='(')
    return 4;
  if(s==')')
    return 1;
  if(s=='+'||'-')
    return 2;
  if (s=='*'||s=='/')
    return 3;
}

//スタックの先頭のデータの取得
data_type top(node_type *p)
{
 if (p == NULL) /* 空スタックのとき */
   return   ('\0'); 
 else /* 空スタックでないとき */
 return p->data; /* スタックの先頭のデータを返す */
}

int main(void){
  int n=0,i=0,j=0;
  data_type s[50],p[50];

  printf("中置記法の順に代入文の文字列を入力してください:");
  scanf("%s",s);
  n = strlen(s);

  for(i=0;i<n;i++){
    printf("s[%d]:%c\n",i,s[i]);
  }
  initialize(&head);
  //優先順位の出力(優先順位がついているかの確認用)
  for(i=0;i<n;i++){
    new_node(s[i],&head);
    printf("prior(s[%d]):%d\n",i,prior(s[i]));
    }

  for(i=1;i<n;i++){
    while(prior(last_node(&head))>=prior(s[i]) && is_empty(head)==FAILURE){
      //新たに読み取った文字の方が、スタック最上部の文字より優先度が低ければ、スタックをポップしてそれを読み取る。
      p[j]=last_node(&head);
      pop(&head);
      j++; 
    }      

    //スタックの最上部の文字より新たに読み取った文字の優先順位が高ければ、スタックに積む
    if(prior(last_node(&head))<prior(s[i])){
      push(&head,s[i]);
    }
  }

  //逆ポーランド記法の順に出力する  
  for(i=0;i<j;i++){
    printf("p[%d]:%c\n",i,p[i]);
    }

  Sleep(100000);
  
  return 0;

} 
