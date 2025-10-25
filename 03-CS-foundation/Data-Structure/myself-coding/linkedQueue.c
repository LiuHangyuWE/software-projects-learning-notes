//基于链表的队列不用检查是否已满，也不用循环以减少挪动次数
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct QueueNode{
	ElemType data;
	struct QueueNode *next;
}QueueNode;
typedef struct {
	QueueNode *front, *rear;
}Queue;
Queue* initQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = -1;
    node->next = NULL;
    q->front = node;
    q->rear = node;
	return q;
}
int isEmpty(Queue *Q) {
	return Q->front == Q->rear;//注意判断条件
}
int deQueue(Queue *Q, ElemType *e) {
    if (isEmpty(Q)) {
    	printf("队列为空\n");
    	return 0;
    }
    QueueNode *node = Q->front->next;
    Q->front->next = node->next;
    if (Q->rear == node)    Q->rear = Q->front; //删尾节点注意更改rear指向
    free(node);
    return 1;
}
int enterQueue(Queue *Q, ElemType e) {
	QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = e;
	node->next = NULL;
	Q->rear->next = node;
	Q->rear = node;
	return 1;
}
int getHead(Queue *Q, ElemType *e) {
	if (isEmpty(Q)) {
		printf("队列为空\n");
		return 0;
	}
	*e = Q->front->next->data;
	printf("队头元素： %d\n", *e);
	return 1;
}
void printQueue(Queue *Q) {
	if (isEmpty(Q)) {
		printf("队列为空\n");
		return;
	}
	printf("队列由头到尾： ");
	QueueNode *p = Q->front->next;
	while (p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	putchar('\n');
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