#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *prev, *next;
}Node;
Node* initList() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}
void insertHead(Node* L， ElemType e) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    if(L->next != NULL)    L->next->prev = p;
    L->next = p;
}
void insertTail(Node* tail, ElemType e) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = tail;
    tail->next = p;
    p->next = NULL;
    return p;
}
//此后均以前置节点插入为例，但不失一般性
void insertNode(Node* L, int pos, ElemType e) {
    Node *p = L;
    //指向pos的前一个节点
    for(int i = 0; i < pos - 1; i++) {
        p = p->next;
        if(p == NULL)    return 0;
    }
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->prev = p;
    q->next = p->next;
    p->next->prev = q;
    p->next = q;
}
int deleteNode(Node* L, int pos) {
    Node *p = L;
    //退出循环后p指向pos的前一个节点
    for(int i = 0; i < pos - 1; i++) {
        p = p->next;
        if(p->next == NULL) {
            printf("要删除的位置错误\n");
            return 0;
        }
    }
    Node *q = p->next;
    p->next = q->next;
    q->next->prev = p;
    free(q);
    return 1;
}
void freeList(Node* L){
    Node *p = L->next, *q;
    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}
int main(int argc, char const *argv[]){
    return 0;
}