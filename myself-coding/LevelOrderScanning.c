#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef char TreeType;
typedef struct TreeNode {
	TreeType data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode;
typedef TreeNode* ElemType;
typedef struct {
	ElemType *data;
	int front;
	int rear;
}Queue;
typedef TreeNode* BiTree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

void createTree(BiTree *T) {
	TreeType ch;
	ch = str[idx++];
	if (ch == '#') {
		*T = NULL;
	} else {
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
}
Queue* initQueue() {
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	q->front = q->rear = 0;
	return q;
}

int isEmpty(Queue *Q) {
	return Q->front == Q->rear;
}
int equeue(Queue *Q, ElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		printf("队列已满\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;
}
int dequeue(Queue *Q, ElemType *e) {
	if (Q->front == Q->rear) {
		printf("队列为空\n");
		return 0;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}
int queueSize(Queue *Q) {
	return Q->rear - Q->front;
}

int maxDepth(BiTree root) {
	if (root == NULL)    return 0;
	int depth = 0;
	Queue* q = initQueue();
	equeue(q, root);
	while(!isEmpty(q)) {
		int count = queueSize(q);
		while(count > 0) {
			BiTree current;
			dequeue(q, &current);
			if (current->lchild != NULL)    equeue(q, current->lchild);
			if (current->rchild != NULL)    equeue(q, current->rchild);
			count--;
		}
		depth++;
	}
	return depth;
}

int main(int argc, char const *argv[]) {
	BiTree T;
	createTree(&T);
	printf("%d\n", maxDepth(T));
	return 0;
}