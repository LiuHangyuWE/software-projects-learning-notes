#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
	ElemType *data;
	int front;
	int rear;
}Queue;
//front和rear是真实的队列起止点，而非总是0和MAXSIZE
Queue* initQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	q->front = q->rear = 0;
	return q;
}
int isEmpty(Queue *Q) {
	return Q->front == Q->rear;//注意判断条件
}
ElemType deQueue(Queue *Q, ElemType *e) {
    if (isEmpty(Q)) {
    	printf("队列为空\n");
    	return 0;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}
//循环队列判断队列是否已满，看加1后对一圈的余数是否与队头重合
int isFull(Queue *Q) {
	if((Q->rear + 1) % MAXSIZE == Q->front) {
		printf("循环队列已满\n");
		return 1;
	}
    return 0;
}
int enterQueue(Queue *Q, ElemType e) {
	if (isFull(Q))		return 0;
	Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE; //队尾指针指向队尾的下一个位置,循环队列总会空至少1格
	return 1;
}
int getHead(Queue *Q, ElemType *e) {
	if (isEmpty(Q)) {
		printf("队列为空\n");
		return 0;
	}
	*e = Q->data[Q->front];
	printf("队头元素： %d\n", *e);
	return 1;
}
void printQueue(Queue *Q) {
	if(isEmpty(Q)) {
		printf("队列为空\n");
		return;
	}
	printf("队列由头到尾： ");
	for(int i = Q->front; i < Q->rear; i++)
		printf("%d ",Q->data[i]);
	putchar('\n');
	return;
}
int main(int argc, char const *argv[]) {
	Queue *q = initQueue();
	enterQueue(q, 10);
    enterQueue(q, 20);
    enterQueue(q, 30);
    enterQueue(q, 40);
    enterQueue(q, 50);
    printQueue(q);
    ElemType topValue;
    getHead(q, &topValue);
    deQueue(q, &topValue);
    printf("出队列元素： %d\n", topValue); //不需要提前赋值
    printQueue(q);
    getHead(q, &topValue);
    return 0;
}