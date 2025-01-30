#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* link;
}Node;
Node* head() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = -1;
	L->link = NULL;
	return L;
}
Node* tail_(Node* L) {
	Node* p = L;
	while (p->link != NULL)
		p = p->link;
	return p;
}
Node* insert(Node* tail, int e) {
	Node* p = (Node*)malloc(sizeof(Node));
	tail->link = p;
	p->data = e;
	p->link = NULL;
	return p;
}
void free_(Node* L) {
	Node* p = L;
	Node* q;
	while (p != NULL) {
		q = p->link;
		free(p);
		p = q;
	}
}
int final_findNode(Node* L, int k){
	if (k <= 0)    return 0;
	Node *fast = L, *slow = L;
	for (int i = 0; i < k; i++) {
		if (fast == NULL)    return 0;
		fast = fast->link;
	}
	while (fast != NULL) {
		fast = fast->link;
		slow = slow->link;
	}
	printf("倒数第%d个节点值为：%d\n", k, slow->data);
	return 1;
}
int main() {
	Node* list = head();
	Node* tail = tail_(list);
	tail = insert(tail, 1);
	tail = insert(tail, 2);
	tail = insert(tail, 3);
	final_findNode(list, 3);
	free_(list);
	return 0;
}