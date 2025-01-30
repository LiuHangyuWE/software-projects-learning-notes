//函数：找出str1和str2共同后缀的起始位置
#include <stdio.h>
typedef struct node {
	char data;
	struct node* next;
}Node;
int findLength(Node* head) {
	Node* p = head;
	int length = 0;
	while (p != NULL) {
		p = p->next;
		length++;
	}
	return length;
}
Node* findIntersectionNode(Node* headA, Node* headB) {
	if (headA == NULL || headB == NULL)    return NULL;
	int lenA = findLength(headA), lenB = findLength(headB);
	Node* m, * n;
	int step;
	if (lenA > lenB) {
		step = lenA - lenB;
		m = headA;
		n = headB;
	}
	else {
		step = lenB - lenA;
		m = headB;
		n = headA;
	}
	for (int i = 0; i < step; i++)
		m = m->next;
	while (m != n) {
		m = m->next;
		n = n->next;
	}
	return m;
}