#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#define MAXSIZE 100

typedef struct Stack{
	ElemType data[MAXSIZE];
	int top;
}Stack;

typedef enum {
    left_pare, right_pare, //左右括号
    add, sub, mul, di, mod,
    EOS, NUM
}contentType;

char expr[] = "x/(i-j)*y";

Stack* initStack() {
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->top = -1;
	return s;
}
int isEmpty(Stack *s) {
	if (s->top == -1)    return 1;
	return 0;
}
int push(Stack *s, ElemType e) {
	if (s->top >= MAXSIZE - 1) {
		printf("栈满了\n");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}
//出栈操作注意主函数写法，理解此处*e作用
ElemType pop(Stack *s, ElemType *e) {
    if (isEmpty(s)) {
    	printf("栈为空\n");
    	return 0;
    }
    *e = s->data[s->top--];
    return 1;
}



contentType getToken(char *symbol, int *index) {
    *symbol = expr[*index];
    *index = *index + 1;
    switch(*symbol) {
        case '(':    return left_pare;
        case ')':    return right_pare;
        case '+':    return add;
        case '-':    return sub;
        case '*':    return mul;
        case '/':    return di;
        case '%':    return mod;
        case '\0':    return EOS;
        default:    return NUM;
    }
}

int print_token(contentType token) {
	switch(token) {
	    case add:    printf("+");    break;
	    case sub:    printf("-");    break;
	    case mul:    printf("*");    break;
	    case di:    printf("/");    break;
	    case mod:    printf("%%");    break;
	    default:    return 0; 
	}
	return 1;
}

void postfix(Stack *s) {
	int in_stack[] = {0, 19, 12, 12, 13, 13, 13, 0};
	int out_stack[] = {20, 19, 12, 12, 13, 13, 13, 0};
	char symbol;
	ElemType e;
	int index = 0;
	contentType token = getToken(&symbol, &index);
	s->data[0] = EOS; //先放入优先级最低的垫底，方便比较

	while(token != EOS) {
		if (token == NUM) {
			printf("%c", symbol);
		} else if (token == right_pare) {
			while(s->data[s->top] != left_pare) {
				pop(s, &e);
				print_token(e);
			}
			pop(s, &e);
		} else {
			while(in_stack[s->data[s->top]] >= out_stack[token]) {
				pop(s, &e);
				print_token(e);
			}
			push(s, token);
		}
		token = getToken(&symbol, &index);
    }
    while (!isEmpty(s)) {
        pop(s, &e);
        print_token(e);
    }
}

int main(int argc, char const *argv[]) {
    Stack *s = initStack();
    printf("%s\n", expr);
    printf("后缀表达式为： ");
    postfix(s);
    free(s);
    return 0;
}