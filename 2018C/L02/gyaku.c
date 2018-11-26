#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define STACK_MAX  100

char *stack[STACK_MAX];
int   stack_pointer = 0;

void error(char *msg) {
    fprintf(stderr, "error: %s\n", msg);
    exit(1);
}

void push(char *pToken) {
    if (stack_pointer >= STACK_MAX) error("stack full");
    stack[stack_pointer++] = pToken;
}

char *pop() {
    return stack_pointer > 0 ? stack[--stack_pointer] : NULL;
}

char *peek() {
    return stack_pointer > 0 ? stack[stack_pointer-1] : NULL;
}

// ���Z�q�̗D�揇�ʂ�Ԃ�
int rank(char *op) {
    if (*op == '*' || *op == '/' || *op == '%') return 4;
    if (*op == '+' || *op == '-') return 5;
    return 99;
}

char** convert(char *token[], int length) {
    int n;
    char *pToken;

    // ���ёւ����g�[�N�����i�[����o�b�t�@�B
    // ����"(", ")" �͏������߁A���̎��Ɋ��ʂ�����΂��̕������͒Z���Ȃ�B
    char** buffer = calloc(length+1, sizeof(char*));
    int nBuf = 0;

    for (n = 0; n < length; n++) {
        if (isdigit(*token[n])) {
            // ���l�Ȃ�΁A�o�b�t�@�ɒǉ�
            buffer[nBuf++] = token[n];
        } else if (*token[n] == ')') {
            // '('�܂ŃX�^�b�N����|�b�v���A�o�b�t�@��. '(' �� ')' �͎̂Ă�.
            while ((pToken = pop()) != NULL && *pToken != '(')
                buffer[nBuf++] = pToken;
            if (pToken == NULL) error("'(' ���Ȃ�");
        } else if (*token[n] == '(') {
            push(token[n]);
        } else if (peek() == NULL) {
            push(token[n]);
        } else {
            while (peek() != NULL) {
                if (rank(token[n]) > rank(peek())) {
                    // ���݂̃g�[�N���̓X�^�b�N�ŏ�ʂ̃g�[�N�����D�揇�ʂ��Ⴂ
                    buffer[nBuf++] = pop();
                } else {
                    push(token[n]);
                    break;
                }
            }
        }
    }

    // �X�^�b�N����ɂȂ�܂Ńg�[�N�������o���A�o�b�t�@��
    while ((pToken = pop()) != NULL)
        buffer[nBuf++] = pToken;
    buffer[nBuf++] = NULL;
    return buffer;
}

void printRPN(char *buffer[]) {
    int n;
    for (n = 0; buffer[n] != NULL; n++)
        printf("%s ", buffer[n]);
}

int main() {
    char *expr[] = { "(", "3.2", "+", "1.5", ")", "*", "4.0" };
    char **buf = convert(expr, sizeof(expr)/sizeof(char*));
    printRPN(buf);

    Sleep(10000);
}