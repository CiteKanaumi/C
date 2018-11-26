#include <stdio.h>
#define STACK_SIZE 100
#define MAX_LEN 100

int stack[STACK_SIZE];
int stack_size = 0;

// スタックから出す
int pop()
{
	if (stack_size <= 0) return 0;
	return stack[--stack_size];
}

// スタックに積む
int push(int a)
{
	stack[stack_size++] = a;
}

// 要素が数値かどうか判定
int is_digit(char *s)
{
	// 符号つき
	if (*s == '+' || *s =='-') {
		s++;
		if (*s >= '0' && *s <= '9') return 1;
		return 0;
	}
	// 符号なし
	if (*s >= '0' && *s <= '9') return 1;
	return 0;
}

// 文字列から数値を取り出す
int get_number(char *s)
{
	int sign = 0, n = 0;
	
	// 符号処理
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
	// 符号を変えて返す
	if (sign) return -n;
	return n;
}

// 逆ポーランド記法の文字列を計算
int calc_rpn(char *s)
{
	int a, b, n;
	
	// 終端まで繰り返す
	while (*s) {
		
		// 数値なら取り出してスタックに積む
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
			
		// オペランドなら2項を計算する
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
	printf("逆ポーランドで入力\n");
	scanf("%[^\n]*s", s);
	printf("%s = %d\n", s, calc_rpn(s));
}
