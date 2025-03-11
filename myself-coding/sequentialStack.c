#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
	ElemType *data;
	int top;
}Stack;
/* //栈内存分配
void initStack(Stack *s) {
	s->top = -1;
}
*/
//堆内存分配
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
int main(int argc, char const *argv[]) {
	Stack *s = initStack();
	push(s, 10);
    push(s, 20);
    push(s, 30);
    printStack(s);
    ElemType topValue;
    getTop(s, &topValue);
    pop(s, &topValue); //不需要提前赋值
    printStack(s);
    getTop(s, &topValue);
    printf("%d\n", topValue);
    freeStack(s);
    return 0;
}