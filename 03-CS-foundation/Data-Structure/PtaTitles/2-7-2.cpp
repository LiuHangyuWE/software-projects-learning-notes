#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

//Pay attention to the extra operation with the addition of head node
Node* initList() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = -1;
    head->next = NULL;
    return head;
}

//Find a method that do not need to find the tail repeatedly!!!Using the function type is brilliant, even marvelous
//Mark the tail and then I can find the tail easily
Node* insert(Node *tail, int e) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    tail->next = p;
    tail = p;
    return tail;
}

void insertOne(Node* tail) {
    int e;
    while(1) {
        scanf("%d", &e);
        if(e == -1) {
            break;
        }
        tail = insert(tail, e);
    }
}

//Using the sector(really POWERFUL tool)to handle problems like this
void integrate(Node* L, Node* L1, Node* L2) {
    Node* p1 = L1->next;
    Node* p2 = L2->next;
    Node* tail = L;

    while(p1 != NULL && p2 != NULL) {
        if(p1->data <= p2->data) {
            tail->next = p1;
            tail = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            tail = p2;
            p2 = p2->next;
        }
    }
    
    while(p1 != NULL) {
        tail->next = p1;
        tail = p1;
        p1 = p1->next;
    }

    while(p2 != NULL) {
        tail->next = p2;
        tail = p2;
        p2 = p2->next;
    }

    tail->next = NULL;
}

void printOne(Node* L) {
    Node* p = L->next;
    if(p == NULL) {
        printf("NULL");
        return;
    }
    while(p != NULL) {
        printf("%d", p->data);
        p = p->next;
        //Last print should not have ' ', I also use vector to calculate
        if(p != NULL) {
            printf(" ");
        }
    }
}

int main() {
    Node *L1 = initList(), *L2 = initList(), *L3 = initList();
    insertOne(L1);
    insertOne(L2);
    integrate(L3, L1, L2);
    printOne(L3);
    return 0;
}