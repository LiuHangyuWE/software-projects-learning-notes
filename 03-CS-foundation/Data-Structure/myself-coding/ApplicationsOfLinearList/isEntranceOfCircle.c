typedef struct node {
    int data;
    struct node* next;
}Node;
Node* isCycle(Node* head) {
    Node *fast = head, *slow = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)    return fast;
    }
    return 0;
}
Node findBegin(Node* fast) {
    Node *slow = head;
    while(fast != head) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}