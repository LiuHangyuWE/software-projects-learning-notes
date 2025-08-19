#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node* initList() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = -1;
    head->next = NULL;
    return head;
}

void insertHead(Node* L, int e) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}

void isFind(Node* L, int k) {
    Node* p = L;
    for(int i = 0; i < k; i++) {
        p = p->next;
        if(p == NULL) {
            printf("NULL");
            return;
        }
    }
    printf("%d", p->data);
}

void freeList(Node* L) {
    Node* p = L;
    while (p != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp);
    }
}

int main() {
    Node *L = initList();
    int e, k;
    scanf("%d", &k);
    while(1) {
        scanf("%d", &e);
        if(e == -1) {
            break;
        }
        insertHead(L, e);
    }
    isFind(L, k);
    freeList(L);
    return 0;
}