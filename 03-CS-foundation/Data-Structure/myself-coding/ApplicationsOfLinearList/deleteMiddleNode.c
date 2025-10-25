typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *next;
}Node;
int delMiddleNode(Node* head) {
    Node *fast = head->next, *slow = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *q = slow->next;
    slow->next = q->next;
    free(q);
    return 1;
}