#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct TreeNode {
	ElemType data;
	struct TreeNode *lchild, *rchild;
}TreeNode;

typedef TreeNode* BiTree;
//用前序遍历造二叉树
char str[] = "ABDH#K###E##CFI###G#J##";
int Index = 0;

void createTree(BiTree *T) {
	ElemType ch = str[Index++];
	if (ch == '#') {
		*T = NULL;
	} else {
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		createTree(&(*T)->lchild);
		createTree(&(*T)->rchild);
	}
}
//前序遍历
void preOrder(BiTree T) {
	if(T == NULL)    return;
	putchar(T->data);
	putchar(' ');
	preOrder(T->lchild);
	preOrder(T->rchild);
}
//中序遍历
void inOrder(BiTree T) {
	if(T == NULL)    return;
	inOrder(T->lchild);
	putchar(T->data);
	putchar(' ');
	inOrder(T->rchild);
}
//后序遍历
void postOrder(BiTree T) {
	if(T == NULL)    return;
	postOrder(T->lchild);
	postOrder(T->rchild);
	putchar(T->data);
	putchar(' ');
}
int main(int argc, char const *argv[]) {
	BiTree T;
	createTree(&T);
	preOrder(T);
	putchar('\n');
	inOrder(T);
	putchar('\n');
	postOrder(T);
	putchar('\n');
	putchar('A');
	return 0;
}