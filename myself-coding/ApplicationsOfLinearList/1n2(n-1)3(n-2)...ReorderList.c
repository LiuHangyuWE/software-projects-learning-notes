typedef struct node{
    int data;
    struct node* next;
}Node;
void reorderList(Node *head) {
    Node *fast = head->next, *slow = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *first = NULL, *second = slow->next;
    slow->next = NULL;
    Node *third = NULL;
    while(second != NULL) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }
    Node *p1 = head->next, *q1 = first, *p2, *q2;
    while(p1 != NULL && q1 != NULL) {
        p2 = p1->next;
        q2 = q1->next;
        p1->next = q1;
        q1->next = p2;
        p1 = p2;
        q1 = q2;
    }
}