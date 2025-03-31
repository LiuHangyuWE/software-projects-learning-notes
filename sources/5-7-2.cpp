//由前序遍历和中序遍历造树，镜像化后层序遍历
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct TreeNode {
    ElemType data;
    struct TreeNode *lchild, *rchild;
} TreeNode;
 
typedef TreeNode* BiTree;
 
typedef struct {
    TreeNode *data;
    int front;
    int rear;
} Queue;

Queue* initQueue (void) {
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    Q->data = (BiTree)malloc(sizeof(TreeNode) * MAXSIZE);
    Q->front = Q->rear = 0;
    return Q;
}

int isEmpty (Queue* Q) {
    return Q->front == Q->rear;
}

int queueSize (Queue* Q) {
    return (Q->rear + MAXSIZE - Q->front) % MAXSIZE;
}

void equeue (Queue *Q, TreeNode e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        printf("队列已满\n");
        exit(0);
    }
    
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
}

void dequeue (Queue *Q, BiTree e) {
    if (isEmpty(Q)) {
        printf("队列为空\n");
        exit(0);
    }
    
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
}

int Index = 0;
ElemType preStr[MAXSIZE]; //存前序遍历结果
ElemType inStr[MAXSIZE]; //存中序遍历结果

//在中序遍历中找根结点的位置
int findRoot(ElemType data, int inStart, int inEnd) {
    for (int i = inStart; i <= inEnd; i++) {
        if (data == inStr[i]) {
            return i;
        }
    }
    printf("输入有误\n");
    exit(0);
}
 
//递归造树
void createBiTree(BiTree* T, int preStart, int inStart, int inEnd) {
    //最后一个有效结点的inStart == inEnd，再次调用，孩子为NULL
    if (inStart > inEnd) {
        *T = NULL;
        return;
    }
    
    *T = (BiTree)malloc(sizeof(TreeNode));
    (*T)->data = preStr[preStart];
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
    
    int root = findRoot((*T)->data, inStart, inEnd);
    
    //每一层的左右孩子均在造树时就先镜面反转
    createBiTree(&(*T)->rchild, preStart + 1, inStart, root - 1);
    createBiTree(&(*T)->lchild, preStart + root - inStart + 1, root + 1, inEnd);
}
 
void levelOrder (BiTree T) {
    Queue *Q = initQueue();
    int flag = 1; //满足格式没有末尾空格
    equeue(Q, *T);
    while (!isEmpty(Q)) {
        int count = queueSize(Q);
        while (count > 0) {
            TreeNode current;
            dequeue(Q, &current);
            
            if (flag) {
                printf("%d", current.data);
                flag = 0;
            } else {
                printf(" %d", current.data);
            }
            
            if (current.lchild != NULL)    equeue(Q, *current.lchild);
            if (current.rchild != NULL)    equeue(Q, *current.rchild);
            count--;
        }
    }
}

int main (int argc, char const *argv[]) {
    short N;
    scanf("%hd", &N);
    
    //printf("输入中序遍历的结果：\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &inStr[i]);
    }
    
    //printf("输入前序遍历的结果：\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &preStr[i]);
    }
    BiTree T = NULL;
    createBiTree(&T, 0, 0, N - 1);
    
    //printf("镜面翻转后的层序遍历如下：\n");
    levelOrder(T);
    return 0;
}
