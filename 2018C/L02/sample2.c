#include<stdio.h>

void trim(char *);
int main(void)
{
char *p;
char str[255];
printf("�������?\n");
gets(str);
p=str;
printf("�ϊ��O=%s\n",str);
printf("�ϊ���=");
trim(p);
// printf("�ϊ���=%s\n",str);
}

void trim(char *p)
{
int i=0;
while(*p!='\0'){
if(*p!=' '){
printf("%c",*p);
}
p++;
}
}
