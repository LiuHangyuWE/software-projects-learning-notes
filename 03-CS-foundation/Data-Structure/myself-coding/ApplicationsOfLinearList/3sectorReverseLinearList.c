#include <stdio.h>
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node* next;
}Node;
Node* initList() {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = -1;
	p->next = NULL;
	return p;
}
Node* reverseList(Node* head) {
	Node* first = NULL, * second = head->next, * third;
	while (second != NULL) {
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}
	Node* head = initList();
	head->next = first;
	return head;
}