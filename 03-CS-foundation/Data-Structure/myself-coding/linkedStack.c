#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct stack{
	ElemType data;
	struct stack *next;
}Stack;
Stack* initStack() {
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->data = 0;
	s->next = NULL;
	return s;
}
int isEmpty(Stack *s) {
	if (s->next == NULL) {
		printf("栈为空\n");
		return 1;
	} else {
		return 0;
	}
}
//链式栈若要限制节点数量，结构体定义int计数，外加MAXSIZE作限制,此处不表
int push(Stack *s, ElemType e) {
	Stack *p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return 1;
}
//进出栈均由head实现
ElemType pop(Stack *s, ElemType *e) {
    if (isEmpty(s)) {
    	printf("栈为空\n");
    	return 0;
    }
    *e = s->next->data;
    Stack *q = s->next;
    s->next = q->next;
    free(q);
    return 1;
}
int getTop(Stack *s, ElemType *e) {
	if (isEmpty(s)) {
		printf("栈为空\n");
		return 0;
	}
	*e = s->next->data;
	printf("栈顶元素： %d\n", *e);
	return 1;
}
void printStack(Stack *s) {
	if(isEmpty(s)) {
		printf("栈为空\n");
		return;
	}
	Stack *p = s;
	printf("栈由顶到底： ");
	while(p->next != NULL){
		printf("%d ",p->next->data);
		p = p->next;
	}
	putchar('\n');
	return;
}
void freeStack(Stack *s) {
	Stack *p = s, *q = s;
	if(p != NULL) {
		p = p->next;
		free(q);
		q = p;
	}
	free(p);    
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
    freeStack(s);
    return 0;
}