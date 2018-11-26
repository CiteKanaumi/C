#include<stdio.h>

void trim(char *);
int main(void)
{
char *p;
char str[255];
printf("•¶Žš—ñ‚Í?\n");
gets(str);
p=str;
printf("•ÏŠ·‘O=%s\n",str);
printf("•ÏŠ·Œã=");
trim(p);
// printf("•ÏŠ·Œã=%s\n",str);
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
