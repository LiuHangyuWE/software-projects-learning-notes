//单链表data<=n，n为保存的整数个数，保留第一次出现的节点，删除其余绝对值相等的节点
//calloc初始化为二进制0（与十进制0相同）
#include <stdio.h>
typedef struct node{
	int data;
	struct node* next;
}Node;
int findLength(Node* L) {
	int len = 0;
	Node* p = L;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}
void deleteAbsSameNode(Node *L, int len){
	Node* p = L;
	int index;
	int* q = (int*)calloc(len, sizeof(int));
	while (p->next != NULL) {
		index = abs(p->next->data);
		if (*(q + index) == 0) {
			*(q + index) = 1;
			p = p->next;
		}
		else {
			Node* temp = p->next;    //建立临时指针去free
			p->next = temp->next;
			free(temp);
		}
	}
	free(q);
}