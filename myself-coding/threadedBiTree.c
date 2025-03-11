#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
//中序遍历线索化
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode *lchild, *rchild;
	//ltag为0，指向该节点左孩子；为1，指向该节点前驱。rtag为0，右孩子；为1，后继
	int ltag, rtag; 
}ThreadNode;
typedef ThreadNode* ThreadTree;

char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0;

ThreadTree prev;

void createTree(ThreadTree *T) {
	ElemType ch;
	ch = str[idx++];
	if (ch == '#') {
		*T = NULL;
	} else {
		*T = (ThreadTree)malloc(sizeof(ThreadNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		if ((*T)->lchild != NULL)    (*T)->ltag = 0; //表示有左孩子
		createTree(&(*T)->rchild);
		if ((*T)->rchild != NULL)    (*T)->rtag = 0; //表示有右孩子
	}
}
//具体中序线索化
void threading(ThreadTree T) {
	if (T != NULL) {
		threading(T->lchild);
		if (T->lchild == NULL) {
			T->ltag = 1;
			T->lchild = prev;
		}
		if (prev->rchild == NULL) {
			prev->rtag = 1;
			prev->rchild = T;
		}
		prev = T;
		threading(T->rchild);
	}
}
//开始线索化
//头节点的lchild指向二叉树的根（把二叉树视为头节点的左孩子），rchild指向遍历的最后一个节点（将头节点视为尾节点的后继)
//按遍历顺序，第一个节点的前驱是头节点，最后一个节点的后继是头节点
void inOrderThreading(ThreadTree *head, ThreadTree T) {
	*head = (ThreadTree)malloc(sizeof(ThreadNode));
	(*head)->ltag = 0;
	(*head)->rtag = 1;
	(*head)->rchild = *head;
	if (T == NULL) {
		(*head)->lchild = *head;
	} else {
		(*head)->lchild = T;
		prev = *head;

		threading(T);

		//最后一个节点线索化
		prev->rchild = *head;
		prev->rtag = 1;
		(*head)->rchild = prev;
	}
}

void inOrder(ThreadTree T) {
	ThreadTree curr = T->lchild;
	while(curr != T) {
		while(!curr->ltag)    curr = curr->lchild;
		printf("%c ", curr->data);
		while(curr->rtag && curr->rchild != T) {
			curr = curr->rchild;
			printf("%c ", curr->data);
		}
		curr = curr->rchild;
	}
	printf("\n");
}
int main(int argc, char const *argv[]) {
	ThreadTree head;
	ThreadTree T;
	createTree(&T);
	//线索化树
	inOrderThreading(&head, T);
	//基于线索遍历
	inOrder(head);
	return 0;
}