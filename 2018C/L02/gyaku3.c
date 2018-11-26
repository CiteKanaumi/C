#include <stdio.h>
#define STACK_SIZE 100
#define MAX_LEN 100

int stack[STACK_SIZE];
int stack_size = 0;

// �X�^�b�N����o��
int pop()
{
	if (stack_size <= 0) return 0;
	return stack[--stack_size];
}

// �X�^�b�N�ɐς�
int push(int a)
{
	stack[stack_size++] = a;
}

// �v�f�����l���ǂ�������
int is_digit(char *s)
{
	// ������
	if (*s == '+' || *s =='-') {
		s++;
		if (*s >= '0' && *s <= '9') return 1;
		return 0;
	}
	// �����Ȃ�
	if (*s >= '0' && *s <= '9') return 1;
	return 0;
}

// �����񂩂琔�l�����o��
int get_number(char *s)
{
	int sign = 0, n = 0;
	
	// ��������
	if (*s == '+') {
		s++;
	} else if (*s == '-') {
		sign = 1;
		s++;
	}
	// char to int
	while (*s >= '0' && *s <= '9') {
		n = n * 10 + (*s - '0');
		s++;
	}
	// ������ς��ĕԂ�
	if (sign) return -n;
	return n;
}

// �t�|�[�����h�L�@�̕�������v�Z
int calc_rpn(char *s)
{
	int a, b, n;
	
	// �I�[�܂ŌJ��Ԃ�
	while (*s) {
		
		// ���l�Ȃ���o���ăX�^�b�N�ɐς�
		if (is_digit(s)) {
			n = get_number(s);
			push(n);
			while (*s == '-' || *s == '+') {
				s++;
			}
			while (n) {
				n /= 10;
				s++;
			}
			
		// �I�y�����h�Ȃ�2�����v�Z����
		} else {
			switch (*s) {
			case '+':
				a = pop();
				b = pop();
				push(b+a);
				break;
			case '-':
				a = pop();
				b = pop();
				push(b-a);
				break;
			case '*':
				a = pop();
				b = pop();
				push(b*a);
				break;
			case '/':
				a = pop();
				b = pop();
				if (a == 0) break;
				push(b/a);
				break;
			case '%':
				a = pop();
				b = pop();
				if (a == 0) break;
				push(b%a);
			}
			s++;
		}
	}
	return pop();
}

int main()
{
	char s[MAX_LEN];
	printf("�t�|�[�����h�œ���\n");
	scanf("%[^\n]*s", s);
	printf("%s = %d\n", s, calc_rpn(s));
}
