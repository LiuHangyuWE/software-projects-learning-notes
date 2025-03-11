#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#define MAXSIZE 100

typedef enum {
    mon = 1, tue, wed, thu, fri, sat, sun
}weekday;
typedef enum {
	false, true //不赋值总从0开头
}judgment;


typedef struct Stack{
	ElemType *data;
	int top;
}Stack;

typedef enum {
    left_pare, right_pare, //左右括号
    add, sub, mul, di, mod,
    EOS, NUM
}contentType;

char expr[] = "82/2+56*-";


Stack* initStack() {
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	s->top = -1;
	return s;
}
int isEmpty(Stack *s) {
	if (s->top == -1) {
		printf("栈为空\n");
		return 1;
	} else {
		return 0;
	}
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
int getTop(Stack *s, ElemType *e) {
	if (isEmpty(s)) {
		printf("栈为空\n");
		return 0;
	}
	*e = s->data[s->top];
	printf("栈顶元素： %d\n", *e);
	return 1;
}
void printStack(Stack *s) {
	if(isEmpty(s)) {
		printf("栈为空\n");
		return;
	}
	printf("栈由底到顶： ");
	for (int i = 0; i <= s->top; i++)
		printf("%d ",s->data[i]);
	putchar('\n');
	return;
}
void freeStack(Stack *s) {
	if(s != NULL){
		free(s->data);
	    free(s);
	}    
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
int eval(Stack *s) {
	char symbol;
	int op1, op2;
	int index = 0;
	contentType token = getToken(&symbol, &index);
    while(token != EOS) {
    	if(token == NUM) {
    		push(s, symbol - '0');
    	} else {
    		pop(s, &op2);
    		pop(s, &op1);

    		switch(token) {
    		    case add:    push(s, op1 + op2);    break;
    		    case sub:    push(s, op1 - op2);    break;
    		    case mul:    push(s, op1 * op2);    break;
    		    case di:    push(s, op1 / op2);    break;
    		    case mod:    push(s, op1 % op2);    break;
    		    default:    break;
    		}
    	}
  		token = getToken(&symbol, &index);
    }
    int result;
    pop(s, &result);
    printf("计算结果： %d\n", result);
    return 1;
}

int main(int argc, char const *argv[]) {
	weekday a = mon;
	judgment b = false;
    printf("%d\n", a);
    printf("%d\n", b);
    Stack *s = initStack();
    eval(s);
    return 0;
}