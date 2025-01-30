#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node* next;
}Node;
Node* initList() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = -1;
	head->next = NULL;
	return head;
}
//头插法：与插入顺序相反
void insertHead(Node* L, ElemType e) {   
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
	return 1;
}
//尾插法：与插入顺序相同，先遍历到尾节点获取尾节点地址;tail为原尾节点，p为新尾节点
Node* get_tail(Node* L) {
	Node* p = L;
	while (p->next != NULL)
		p = p->next;
	return p;
}
//尾插法：由于传入元素含tail，必每次更新tail值，故声明不能为void型
Node* insertTail(Node* tail, ElemType e) {    
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;
	return p;
}
//指定pos插：注意头节点不含有效数据，下标与数据实际位置相同
void insertNode(Node* L, int pos, ElemType e) {
	Node* p = L;
	for (int i = 0; i < pos - 1; i++) {
		p = p->next;
		if (p == NULL)    return 0;
	}
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
}
void deleteNode(Node* L, int pos) {
	Node* p = L;
	for (int i = 0; i < pos - 1; i++) {
		p = p->next;
		if (p == NULL)    return 0;
	}
	if (p->next == NULL) {
		printf("要删除的位置错误\n");
		return 0;
	}
	Node* q = p->next;
	p->next = q->next;
	free(q);
}
//malloc开辟的空间分散，必须逐个释放
void freeList(Node* L) {
	Node* p = L->next;
	Node* q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}
int listLength(Node* L) {
	Node* p = L;
	int len = 0;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}
void printNode(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	putchar('\n');
}
int main(int argc, char const *argv[]) {
	Node* list = initList();
	insertHead(list, 10);
	insertHead(list, 20);
	insertHead(list, 30);
	printNode(list);
	Node* tail = get_tail(list);
	tail = insertTail(tail, 40);
	tail = insertTail(tail, 50);
	tail = insertTail(tail, 60);
	printNode(list);
	insertNode(list, 2, 25);
	printNode(list);
	deleteNode(list, 7);
	printNode(list);
	printf("链表长度：%d ；数据域长度：%d\n", listLength(list), listLength(list) - 1);    //链表长度包含头节点
	freeList(list);
	printf("链表长度：%d ；数据域长度：%d\n", listLength(list), listLength(list) - 1);    //未释放头节点，可能含重要数据  
	free(list);
	printf("链表长度：%d ；数据域长度：%d\n", listLength(list), listLength(list) - 1);    //全部释放后无法打印
	return 0;
}