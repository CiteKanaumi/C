#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAILURE 0

typedef char data_type; /*char�^��data_type�^�ɒu�������� */

typedef struct node_tag {
 data_type data; 
 struct node_tag *next;     /* �㑱�m�[�h�ւ̃|�C���^ */
} node_type;                /* �m�[�h�̌^ */

 node_type *head; /* �X�^�b�N�̐擪�ւ̃|�C���^ �i�ϐ��錾�j*/

void initialize(node_type **pp)    /* �X�^�b�N�̏����� */
{
 *pp = NULL;              /* �X�^�b�N�͋�i�擪�m�[�h�Ȃ��j */
}

/* �m�[�h�����ɕt��������*/

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

//�����̃m�[�h�̕������o�͂���
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

int is_empty(node_type *p) {        /* ��X�^�b�N�̂Ƃ��^�A  �����łȂ��Ȃ�΋U��Ԃ� */
 if (p == NULL) return TRUE;        /* ��X�^�b�N�̂Ƃ� */
 else return FALSE;                 /* ��X�^�b�N�łȂ��Ƃ� */
}

//�X�^�b�N�̐擪�m�[�h�̍폜
int pop(node_type **pp)
{
 node_type *temp;
 if (*pp != NULL) {
 temp = (*pp)->next;
 free(*pp); /* �������̉�� */
 *pp = temp;
 return SUCCESS;
 }
 else return FAILURE;
}

//�X�^�b�N�̐擪�ւ̃m�[�h�̑}��
int push(node_type **pp, data_type x)
{
  node_type *temp;
  temp = new_node(x, pp); 
  if (temp == NULL) return FAILURE;
  *pp = temp;
  return SUCCESS;
}

//�����̗D�揇�ʂ��o�͂���
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

//�X�^�b�N�̐擪�̃f�[�^�̎擾
data_type top(node_type *p)
{
 if (p == NULL) /* ��X�^�b�N�̂Ƃ� */
   return   ('\0'); 
 else /* ��X�^�b�N�łȂ��Ƃ� */
 return p->data; /* �X�^�b�N�̐擪�̃f�[�^��Ԃ� */
}

int main(void){
  int n=0,i=0,j=0;
  data_type s[50],p[50];

  printf("���u�L�@�̏��ɑ�����̕��������͂��Ă�������:");
  scanf("%s",s);
  n = strlen(s);

  for(i=0;i<n;i++){
    printf("s[%d]:%c\n",i,s[i]);
  }
  initialize(&head);
  //�D�揇�ʂ̏o��(�D�揇�ʂ����Ă��邩�̊m�F�p)
  for(i=0;i<n;i++){
    new_node(s[i],&head);
    printf("prior(s[%d]):%d\n",i,prior(s[i]));
    }

  for(i=1;i<n;i++){
    while(prior(last_node(&head))>=prior(s[i]) && is_empty(head)==FAILURE){
      //�V���ɓǂݎ���������̕����A�X�^�b�N�ŏ㕔�̕������D��x���Ⴏ��΁A�X�^�b�N���|�b�v���Ă����ǂݎ��B
      p[j]=last_node(&head);
      pop(&head);
      j++; 
    }      

    //�X�^�b�N�̍ŏ㕔�̕������V���ɓǂݎ���������̗D�揇�ʂ�������΁A�X�^�b�N�ɐς�
    if(prior(last_node(&head))<prior(s[i])){
      push(&head,s[i]);
    }
  }

  //�t�|�[�����h�L�@�̏��ɏo�͂���  
  for(i=0;i<j;i++){
    printf("p[%d]:%c\n",i,p[i]);
    }

  Sleep(100000);
  
  return 0;

} 
