#include <stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;
//front和rear是真实的队列起止点，而非总是0和MAXSIZE
void initQueue(Queue *Q) {
	Q->front = Q->rear = 0;
}
int isEmpty(Queue *Q) {
	if (Q->front == Q->rear)    return 1;//注意判断条件
	return 0;
}
ElemType deQueue(Queue *Q) {
    if (isEmpty(Q)) {
    	printf("队列为空\n");
    	return 0;
    }
    ElemType e = Q->data[Q->front];
    Q->front++;
    return e;
}
//判断队列是否已满，出队后队列前端有空位，要转移后判断
int isFull(Queue *Q) {
	if(Q->front > 0) {
        int step = Q->front;
        for (int i = Q->front; i <= Q->rear; i++)
        	Q->data[i - step] = Q->data[i];
        Q->front = 0;
        Q->rear = Q->rear - step;
        return 1;
	} else if(Q->rear == MAXSIZE) {
		printf("队列已满员\n");
		return 0;
	}
	return 0; //其余情况未满
}
int enterQueue(Queue *Q, ElemType e) {
	if (isFull(Q))		return 0;
	Q->data[Q->rear++] = e; //加后rear处为空
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
	Queue q;
	initQueue(&q);
	enterQueue(&q, 10);
    enterQueue(&q, 20);
    enterQueue(&q, 30);
    printQueue(&q);
    ElemType topValue;
    getHead(&q, &topValue);
    printf("出队列元素： %d\n", deQueue(&q)); //不需要提前赋值
    printQueue(&q);
    getHead(&q, &topValue);
    return 0;
}